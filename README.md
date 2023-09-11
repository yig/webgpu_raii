A minimal C++ RAII wrapper for WebGPU's C API.

## Installation

Copy the `webgpu_raii.h` header next to your code.

## Usage

Call `ref(...).get()` around something WebGPU gives you that you need to release later. It's based on `std::unique_ptr`, so it's only useful for single-owner scenarios. The type of `ref()`'s return value is `FooRef`, where `Foo` is any type in the WebGPU API that has a `wgpuFooRelease()` function.

Example:

```
#include "webgpu_raii.h"
...
wgpuDeviceCreateBindGroup( device, (WGPUBindGroupDescriptor[]){{
    .layout = ref(wgpuRenderPipelineGetBindGroupLayout( pipeline, 0 )).get(),
    .entryCount = 1,
    .entries = (WGPUBindGroupEntry[]){{
        .binding = 0,
        .textureView = tex_view
        }}
    }} );
```

## Regenerate

```
python3 webgpu_raii.py > webgpu_raii.h
```

## License

[CC0](https://creativecommons.org/share-your-work/public-domain/cc0/)
