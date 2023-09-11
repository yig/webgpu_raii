A minimal C++ RAII wrapper for WebGPU's C API. It's based on `std::shared_ptr`. It is guaranteed correct; the single WebGPU reference count will be managed by the shared pointer, and eventually released.

## Installation

Copy the `webgpu_raii.h` header next to your code.

## Usage

This header is for any type `Foo` in the WebGPU API that has a `wgpuFooRelease()` function.

For named values, use `FooRef` instead of `Foo` as the declared type. Everything else is automatic. The `FooRef` will automatically manage the lifetime of the type and call the appropriate release function at the end. For example:

```c++
WGPUBufferRef = wgpuDeviceCreateBuffer( device, (WGPUBufferDescriptor[]){{
    .usage = WGPUBufferUsage_CopyDst | WGPUBufferUsage_Vertex,
    .size = bytes
    }} );
```

The `FooRef` type decays to a plain old `Foo` automatically, so you can pass it to any WebGPU API.

For unnamed (temporary) values, call `ref(...)` around something WebGPU gives you that you need to release later. The type of `ref()`'s return value is `FooRef`. For example:

```c++
#include "webgpu_raii.h"
...
wgpuDeviceCreateBindGroup( device, (WGPUBindGroupDescriptor[]){{
    .layout = ref(wgpuRenderPipelineGetBindGroupLayout( pipeline, 0 )),
    .entryCount = 1,
    .entries = (WGPUBindGroupEntry[]){{
        .binding = 0,
        .textureView = tex_view
        }}
    }} );
```

## Debugging

If you run into trouble, you can `#define WEBGPU_RAII_DEBUG` and you'll see a print statement with the pointer. You can further `#define WEBGPU_RAII_LEAK`, and then the release function won't actually be called. Memory will be leaked instead.

## Regenerate

```
python3 webgpu_raii.py > webgpu_raii.h
```

You can optionally pass a path to a `webgpu.h` header:

```
python3 webgpu_raii.py webgpu.h > webgpu_raii.h
```

## License

[CC0](https://creativecommons.org/share-your-work/public-domain/cc0/)
