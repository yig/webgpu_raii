import re
import sys

webgpu_h_path = 'webgpu.h' if len( sys.argv ) == 1 else sys.argv[1]

webgpu_h = open( webgpu_h_path, 'r' ).read()

types = []

for match in re.finditer( 'WGPU_EXPORT void wgpu([A-Za-z]+)Release\(WGPU([A-Za-z]+) [A-Za-z]+\) WGPU_FUNCTION_ATTRIBUTE;', webgpu_h ):
    assert match.group(1) == match.group(2)
    
    types.append( match.group(1) )

print("""#pragma once

#include <webgpu/webgpu.h>
#include <memory>
""")

## From: https://stackoverflow.com/questions/60568363/shared-ptr-custom-deleter
## From: https://stackoverflow.com/questions/56091228/implicit-conversion-of-stdshared-ptr-to-pointer-type
for T in types:
    print( f"""struct WGPU{T}Ref : public std::shared_ptr< std::remove_pointer<WGPU{T}>::type > {{
    WGPU{T}Ref() {{}}
    WGPU{T}Ref( WGPU{T} {T} ) : std::shared_ptr< std::remove_pointer<WGPU{T}>::type >( {T}, wgpu{T}Release ) {{}}
    operator WGPU{T}() const {{ return get(); }}
}};""" )
    print( f"WGPU{T}Ref ref( WGPU{T} {T} ) {{ return WGPU{T}Ref( {T} ); }}" )
    print()
