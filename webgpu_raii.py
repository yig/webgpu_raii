import re
import sys

## Read the contents of `webgpu.h` to a string. Check for a path as a command line argument.
webgpu_h_path = 'webgpu.h' if len( sys.argv ) == 1 else sys.argv[1]
webgpu_h = open( webgpu_h_path, 'r' ).read()

## Find all type names to release or free.
types = []
## Look for functions of the form `wgpu{Type}{Release|FreeMembers}( {Type} )`.
for match in re.finditer( r'WGPU_EXPORT void wgpu([A-Za-z]+)(Release|FreeMembers)\(WGPU([A-Za-z]+) [A-Za-z]+\) WGPU_FUNCTION_ATTRIBUTE;', webgpu_h ):
    ## The function name and its only parameter should refer to the same type.
    assert match.group(1) == match.group(3)
    ## Store the function name and the name of the function to release it.
    types.append( ( match.group(1), match.group(2) ) )

print("""#pragma once

// Author: Yotam Gingold <yotam@yotamgingold.com>
// License: CC0
// URL: <https://github.com/yig/webgpu_raii/>

#include <webgpu/webgpu.h>
#include <memory>

#ifdef WEBGPU_RAII_DEBUG
#include <iostream>
#endif
""")

## From: https://stackoverflow.com/questions/60568363/shared-ptr-custom-deleter
## From: https://stackoverflow.com/questions/56091228/implicit-conversion-of-stdshared-ptr-to-pointer-type
for T, Release in types:
    ## If the release function is 'Release', it's actually a pointer.
    if Release == 'Release':
        print( f"""struct WGPU{T}Ref : public std::shared_ptr< std::remove_pointer<WGPU{T}>::type > {{
        WGPU{T}Ref() {{}}
    #ifdef WEBGPU_RAII_DEBUG
        WGPU{T}Ref( WGPU{T} {T} ) : std::shared_ptr< std::remove_pointer<WGPU{T}>::type >( {T}, [](WGPU{T} {T}){{
            std::cout << "wgpu{T}Release(): " << reinterpret_cast<std::uintptr_t>({T}) << '\\n';
    #ifndef WEBGPU_RAII_LEAK
            if( {T} ) wgpu{T}Release( {T} );
    #endif
            }} ) {{
            std::cout << "Acquired a WGPU{T}: " << reinterpret_cast<std::uintptr_t>({T}) << '\\n';
            }}
    #else
        WGPU{T}Ref( WGPU{T} {T} ) : std::shared_ptr< std::remove_pointer<WGPU{T}>::type >( {T}, [](WGPU{T} {T}){{ if( {T} ) wgpu{T}Release( {T} ); }} ) {{}}
    #endif
        operator WGPU{T}() const {{ return get(); }}
    }};""" )
        print( f"inline WGPU{T}Ref ref( WGPU{T} {T} ) {{ return WGPU{T}Ref( {T} ); }}" )
    ## If the release function is 'FreeMembers', it's a struct.
    elif Release == 'FreeMembers':
        print( f"""struct WGPU{T}Ref : public WGPU{T} {{
        // A constructor to zero initialize the struct.
        WGPU{T}Ref() : WGPU{T}{{}} {{
    #ifdef WEBGPU_RAII_DEBUG
        std::cout << "Tracking a WGPU{T}: " << reinterpret_cast<std::uintptr_t>( this ) << '\\n';
    #endif
        }}
        
        // No copying.
        WGPU{T}Ref( const WGPU{T}Ref& ) = delete;
        WGPU{T}Ref& operator=( const WGPU{T}Ref& ) = delete;
        
        // A destructor to free the members.
        ~WGPU{T}Ref() {{
    #ifdef WEBGPU_RAII_DEBUG
            std::cout << "wgpu{T}FreeMembers(): " << reinterpret_cast<std::uintptr_t>( this ) << '\\n';
    #ifndef WEBGPU_RAII_LEAK
            wgpu{T}FreeMembers( *this );
            // Zero the fields after freeing.
            *static_cast<WGPU{T}*>(this) = WGPU{T}{{}};
    #endif
    #else
            wgpu{T}FreeMembers( *this );
    #endif
        }}
    }};""" )
    else:
        print( f'WARNING: Unknown release function "{Release}" for type "{T}"', file = sys.stderr )
    
    print()
