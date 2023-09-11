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

for T in types:
    print( f"typedef std::unique_ptr< std::remove_pointer<WGPU{T}>::type, void(*)(WGPU{T}) > WGPU{T}Ref;" )
    print( f"WGPU{T}Ref ref( WGPU{T} {T} ) {{ return WGPU{T}Ref( {T}, wgpu{T}Release ); }}" )
    print()
