A minimal C++ RAII wrapper for WebGPU's C API. It's based on `std::shared_ptr`. It is guaranteed correct; the single WebGPU reference count will be managed by the shared pointer, and eventually released.

## Installation

Copy the `webgpu_raii.h` header next to your code.

## Usage

This header is for any type `Foo` in the WebGPU API that has a `wgpuFooRelease()` function.

For named values, use `FooRef` instead of `Foo` as the declared type. Everything else is automatic. The `FooRef` will automatically manage the lifetime of the type and call the appropriate release function at the end. For example:

```c++
WGPUBufferRef buffer = wgpuDeviceCreateBuffer( device, (WGPUBufferDescriptor[]){{
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

## Implementation

The implementation is a simple wrapper around an `std::shared_ptr` with a custom deleter and automatic decaying into a pointer. For every `wgpuFooRelease()` found in `webgpu.h`, the script generates the following code:

```c++
struct WGPUFooRef : public std::shared_ptr< std::remove_pointer<WGPUFoo>::type > {
    WGPUFooRef() {}
    WGPUFooRef( WGPUFoo Foo ) : std::shared_ptr< std::remove_pointer<WGPUFoo>::type >( Foo, [](WGPUFoo Foo){ if( Foo ) wgpuFooRelease( Foo ); } ) {}
    operator WGPUFoo() const { return get(); }
};
WGPUFooRef ref( WGPUFoo Foo ) { return WGPUFooRef( Foo ); }
```

## Regenerate

```
python3 webgpu_raii.py > webgpu_raii.h
```

You can optionally pass a path to a `webgpu.h` header:

```
python3 webgpu_raii.py webgpu.h > webgpu_raii.h
```

This may be necessary if your `webgpu.h` header differs from the one provided. For example, the `webgpu_raii.h` provided in the `main` branch of this repository doesn't have `wgpuSwapChainRelease()`, but [wgpu-native](https://github.com/gfx-rs/wgpu-native)'s [`webgpu.h`](https://github.com/webgpu-native/webgpu-headers/blob/8e9025e0fa4b33d5e7cc682b7604b021b29f36c6/webgpu.h) does. The `webgpu_raii.h` matching `wgpu-native`'s `webgpu.h` is in the `wgpu-native` branch of this repository.

## License

[CC0](https://creativecommons.org/share-your-work/public-domain/cc0/)
