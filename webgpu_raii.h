#pragma once

#include <webgpu/webgpu.h>
#include <memory>

#ifdef DEBUG_WEBGPU_RAII
#include <iostream>
#endif

struct WGPUAdapterRef : public std::shared_ptr< std::remove_pointer<WGPUAdapter>::type > {
    WGPUAdapterRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUAdapterRef( WGPUAdapter Adapter ) : std::shared_ptr< std::remove_pointer<WGPUAdapter>::type >( Adapter, [](WGPUAdapter Adapter){ std::cout << "wgpuAdapterRelease(): " << reinterpret_cast<std::uintptr_t>(Adapter) << '\n'; } ) {}
#else
    WGPUAdapterRef( WGPUAdapter Adapter ) : std::shared_ptr< std::remove_pointer<WGPUAdapter>::type >( Adapter, [](WGPUAdapter Adapter){ if( Adapter ) wgpuAdapterRelease; } ) {}
#endif
    operator WGPUAdapter() const { return get(); }
};
WGPUAdapterRef ref( WGPUAdapter Adapter ) { return WGPUAdapterRef( Adapter ); }

struct WGPUBindGroupRef : public std::shared_ptr< std::remove_pointer<WGPUBindGroup>::type > {
    WGPUBindGroupRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUBindGroupRef( WGPUBindGroup BindGroup ) : std::shared_ptr< std::remove_pointer<WGPUBindGroup>::type >( BindGroup, [](WGPUBindGroup BindGroup){ std::cout << "wgpuBindGroupRelease(): " << reinterpret_cast<std::uintptr_t>(BindGroup) << '\n'; } ) {}
#else
    WGPUBindGroupRef( WGPUBindGroup BindGroup ) : std::shared_ptr< std::remove_pointer<WGPUBindGroup>::type >( BindGroup, [](WGPUBindGroup BindGroup){ if( BindGroup ) wgpuBindGroupRelease; } ) {}
#endif
    operator WGPUBindGroup() const { return get(); }
};
WGPUBindGroupRef ref( WGPUBindGroup BindGroup ) { return WGPUBindGroupRef( BindGroup ); }

struct WGPUBindGroupLayoutRef : public std::shared_ptr< std::remove_pointer<WGPUBindGroupLayout>::type > {
    WGPUBindGroupLayoutRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUBindGroupLayoutRef( WGPUBindGroupLayout BindGroupLayout ) : std::shared_ptr< std::remove_pointer<WGPUBindGroupLayout>::type >( BindGroupLayout, [](WGPUBindGroupLayout BindGroupLayout){ std::cout << "wgpuBindGroupLayoutRelease(): " << reinterpret_cast<std::uintptr_t>(BindGroupLayout) << '\n'; } ) {}
#else
    WGPUBindGroupLayoutRef( WGPUBindGroupLayout BindGroupLayout ) : std::shared_ptr< std::remove_pointer<WGPUBindGroupLayout>::type >( BindGroupLayout, [](WGPUBindGroupLayout BindGroupLayout){ if( BindGroupLayout ) wgpuBindGroupLayoutRelease; } ) {}
#endif
    operator WGPUBindGroupLayout() const { return get(); }
};
WGPUBindGroupLayoutRef ref( WGPUBindGroupLayout BindGroupLayout ) { return WGPUBindGroupLayoutRef( BindGroupLayout ); }

struct WGPUBufferRef : public std::shared_ptr< std::remove_pointer<WGPUBuffer>::type > {
    WGPUBufferRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUBufferRef( WGPUBuffer Buffer ) : std::shared_ptr< std::remove_pointer<WGPUBuffer>::type >( Buffer, [](WGPUBuffer Buffer){ std::cout << "wgpuBufferRelease(): " << reinterpret_cast<std::uintptr_t>(Buffer) << '\n'; } ) {}
#else
    WGPUBufferRef( WGPUBuffer Buffer ) : std::shared_ptr< std::remove_pointer<WGPUBuffer>::type >( Buffer, [](WGPUBuffer Buffer){ if( Buffer ) wgpuBufferRelease; } ) {}
#endif
    operator WGPUBuffer() const { return get(); }
};
WGPUBufferRef ref( WGPUBuffer Buffer ) { return WGPUBufferRef( Buffer ); }

struct WGPUCommandBufferRef : public std::shared_ptr< std::remove_pointer<WGPUCommandBuffer>::type > {
    WGPUCommandBufferRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUCommandBufferRef( WGPUCommandBuffer CommandBuffer ) : std::shared_ptr< std::remove_pointer<WGPUCommandBuffer>::type >( CommandBuffer, [](WGPUCommandBuffer CommandBuffer){ std::cout << "wgpuCommandBufferRelease(): " << reinterpret_cast<std::uintptr_t>(CommandBuffer) << '\n'; } ) {}
#else
    WGPUCommandBufferRef( WGPUCommandBuffer CommandBuffer ) : std::shared_ptr< std::remove_pointer<WGPUCommandBuffer>::type >( CommandBuffer, [](WGPUCommandBuffer CommandBuffer){ if( CommandBuffer ) wgpuCommandBufferRelease; } ) {}
#endif
    operator WGPUCommandBuffer() const { return get(); }
};
WGPUCommandBufferRef ref( WGPUCommandBuffer CommandBuffer ) { return WGPUCommandBufferRef( CommandBuffer ); }

struct WGPUCommandEncoderRef : public std::shared_ptr< std::remove_pointer<WGPUCommandEncoder>::type > {
    WGPUCommandEncoderRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUCommandEncoderRef( WGPUCommandEncoder CommandEncoder ) : std::shared_ptr< std::remove_pointer<WGPUCommandEncoder>::type >( CommandEncoder, [](WGPUCommandEncoder CommandEncoder){ std::cout << "wgpuCommandEncoderRelease(): " << reinterpret_cast<std::uintptr_t>(CommandEncoder) << '\n'; } ) {}
#else
    WGPUCommandEncoderRef( WGPUCommandEncoder CommandEncoder ) : std::shared_ptr< std::remove_pointer<WGPUCommandEncoder>::type >( CommandEncoder, [](WGPUCommandEncoder CommandEncoder){ if( CommandEncoder ) wgpuCommandEncoderRelease; } ) {}
#endif
    operator WGPUCommandEncoder() const { return get(); }
};
WGPUCommandEncoderRef ref( WGPUCommandEncoder CommandEncoder ) { return WGPUCommandEncoderRef( CommandEncoder ); }

struct WGPUComputePassEncoderRef : public std::shared_ptr< std::remove_pointer<WGPUComputePassEncoder>::type > {
    WGPUComputePassEncoderRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUComputePassEncoderRef( WGPUComputePassEncoder ComputePassEncoder ) : std::shared_ptr< std::remove_pointer<WGPUComputePassEncoder>::type >( ComputePassEncoder, [](WGPUComputePassEncoder ComputePassEncoder){ std::cout << "wgpuComputePassEncoderRelease(): " << reinterpret_cast<std::uintptr_t>(ComputePassEncoder) << '\n'; } ) {}
#else
    WGPUComputePassEncoderRef( WGPUComputePassEncoder ComputePassEncoder ) : std::shared_ptr< std::remove_pointer<WGPUComputePassEncoder>::type >( ComputePassEncoder, [](WGPUComputePassEncoder ComputePassEncoder){ if( ComputePassEncoder ) wgpuComputePassEncoderRelease; } ) {}
#endif
    operator WGPUComputePassEncoder() const { return get(); }
};
WGPUComputePassEncoderRef ref( WGPUComputePassEncoder ComputePassEncoder ) { return WGPUComputePassEncoderRef( ComputePassEncoder ); }

struct WGPUComputePipelineRef : public std::shared_ptr< std::remove_pointer<WGPUComputePipeline>::type > {
    WGPUComputePipelineRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUComputePipelineRef( WGPUComputePipeline ComputePipeline ) : std::shared_ptr< std::remove_pointer<WGPUComputePipeline>::type >( ComputePipeline, [](WGPUComputePipeline ComputePipeline){ std::cout << "wgpuComputePipelineRelease(): " << reinterpret_cast<std::uintptr_t>(ComputePipeline) << '\n'; } ) {}
#else
    WGPUComputePipelineRef( WGPUComputePipeline ComputePipeline ) : std::shared_ptr< std::remove_pointer<WGPUComputePipeline>::type >( ComputePipeline, [](WGPUComputePipeline ComputePipeline){ if( ComputePipeline ) wgpuComputePipelineRelease; } ) {}
#endif
    operator WGPUComputePipeline() const { return get(); }
};
WGPUComputePipelineRef ref( WGPUComputePipeline ComputePipeline ) { return WGPUComputePipelineRef( ComputePipeline ); }

struct WGPUDeviceRef : public std::shared_ptr< std::remove_pointer<WGPUDevice>::type > {
    WGPUDeviceRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUDeviceRef( WGPUDevice Device ) : std::shared_ptr< std::remove_pointer<WGPUDevice>::type >( Device, [](WGPUDevice Device){ std::cout << "wgpuDeviceRelease(): " << reinterpret_cast<std::uintptr_t>(Device) << '\n'; } ) {}
#else
    WGPUDeviceRef( WGPUDevice Device ) : std::shared_ptr< std::remove_pointer<WGPUDevice>::type >( Device, [](WGPUDevice Device){ if( Device ) wgpuDeviceRelease; } ) {}
#endif
    operator WGPUDevice() const { return get(); }
};
WGPUDeviceRef ref( WGPUDevice Device ) { return WGPUDeviceRef( Device ); }

struct WGPUInstanceRef : public std::shared_ptr< std::remove_pointer<WGPUInstance>::type > {
    WGPUInstanceRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUInstanceRef( WGPUInstance Instance ) : std::shared_ptr< std::remove_pointer<WGPUInstance>::type >( Instance, [](WGPUInstance Instance){ std::cout << "wgpuInstanceRelease(): " << reinterpret_cast<std::uintptr_t>(Instance) << '\n'; } ) {}
#else
    WGPUInstanceRef( WGPUInstance Instance ) : std::shared_ptr< std::remove_pointer<WGPUInstance>::type >( Instance, [](WGPUInstance Instance){ if( Instance ) wgpuInstanceRelease; } ) {}
#endif
    operator WGPUInstance() const { return get(); }
};
WGPUInstanceRef ref( WGPUInstance Instance ) { return WGPUInstanceRef( Instance ); }

struct WGPUPipelineLayoutRef : public std::shared_ptr< std::remove_pointer<WGPUPipelineLayout>::type > {
    WGPUPipelineLayoutRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUPipelineLayoutRef( WGPUPipelineLayout PipelineLayout ) : std::shared_ptr< std::remove_pointer<WGPUPipelineLayout>::type >( PipelineLayout, [](WGPUPipelineLayout PipelineLayout){ std::cout << "wgpuPipelineLayoutRelease(): " << reinterpret_cast<std::uintptr_t>(PipelineLayout) << '\n'; } ) {}
#else
    WGPUPipelineLayoutRef( WGPUPipelineLayout PipelineLayout ) : std::shared_ptr< std::remove_pointer<WGPUPipelineLayout>::type >( PipelineLayout, [](WGPUPipelineLayout PipelineLayout){ if( PipelineLayout ) wgpuPipelineLayoutRelease; } ) {}
#endif
    operator WGPUPipelineLayout() const { return get(); }
};
WGPUPipelineLayoutRef ref( WGPUPipelineLayout PipelineLayout ) { return WGPUPipelineLayoutRef( PipelineLayout ); }

struct WGPUQuerySetRef : public std::shared_ptr< std::remove_pointer<WGPUQuerySet>::type > {
    WGPUQuerySetRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUQuerySetRef( WGPUQuerySet QuerySet ) : std::shared_ptr< std::remove_pointer<WGPUQuerySet>::type >( QuerySet, [](WGPUQuerySet QuerySet){ std::cout << "wgpuQuerySetRelease(): " << reinterpret_cast<std::uintptr_t>(QuerySet) << '\n'; } ) {}
#else
    WGPUQuerySetRef( WGPUQuerySet QuerySet ) : std::shared_ptr< std::remove_pointer<WGPUQuerySet>::type >( QuerySet, [](WGPUQuerySet QuerySet){ if( QuerySet ) wgpuQuerySetRelease; } ) {}
#endif
    operator WGPUQuerySet() const { return get(); }
};
WGPUQuerySetRef ref( WGPUQuerySet QuerySet ) { return WGPUQuerySetRef( QuerySet ); }

struct WGPUQueueRef : public std::shared_ptr< std::remove_pointer<WGPUQueue>::type > {
    WGPUQueueRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUQueueRef( WGPUQueue Queue ) : std::shared_ptr< std::remove_pointer<WGPUQueue>::type >( Queue, [](WGPUQueue Queue){ std::cout << "wgpuQueueRelease(): " << reinterpret_cast<std::uintptr_t>(Queue) << '\n'; } ) {}
#else
    WGPUQueueRef( WGPUQueue Queue ) : std::shared_ptr< std::remove_pointer<WGPUQueue>::type >( Queue, [](WGPUQueue Queue){ if( Queue ) wgpuQueueRelease; } ) {}
#endif
    operator WGPUQueue() const { return get(); }
};
WGPUQueueRef ref( WGPUQueue Queue ) { return WGPUQueueRef( Queue ); }

struct WGPURenderBundleRef : public std::shared_ptr< std::remove_pointer<WGPURenderBundle>::type > {
    WGPURenderBundleRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPURenderBundleRef( WGPURenderBundle RenderBundle ) : std::shared_ptr< std::remove_pointer<WGPURenderBundle>::type >( RenderBundle, [](WGPURenderBundle RenderBundle){ std::cout << "wgpuRenderBundleRelease(): " << reinterpret_cast<std::uintptr_t>(RenderBundle) << '\n'; } ) {}
#else
    WGPURenderBundleRef( WGPURenderBundle RenderBundle ) : std::shared_ptr< std::remove_pointer<WGPURenderBundle>::type >( RenderBundle, [](WGPURenderBundle RenderBundle){ if( RenderBundle ) wgpuRenderBundleRelease; } ) {}
#endif
    operator WGPURenderBundle() const { return get(); }
};
WGPURenderBundleRef ref( WGPURenderBundle RenderBundle ) { return WGPURenderBundleRef( RenderBundle ); }

struct WGPURenderBundleEncoderRef : public std::shared_ptr< std::remove_pointer<WGPURenderBundleEncoder>::type > {
    WGPURenderBundleEncoderRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPURenderBundleEncoderRef( WGPURenderBundleEncoder RenderBundleEncoder ) : std::shared_ptr< std::remove_pointer<WGPURenderBundleEncoder>::type >( RenderBundleEncoder, [](WGPURenderBundleEncoder RenderBundleEncoder){ std::cout << "wgpuRenderBundleEncoderRelease(): " << reinterpret_cast<std::uintptr_t>(RenderBundleEncoder) << '\n'; } ) {}
#else
    WGPURenderBundleEncoderRef( WGPURenderBundleEncoder RenderBundleEncoder ) : std::shared_ptr< std::remove_pointer<WGPURenderBundleEncoder>::type >( RenderBundleEncoder, [](WGPURenderBundleEncoder RenderBundleEncoder){ if( RenderBundleEncoder ) wgpuRenderBundleEncoderRelease; } ) {}
#endif
    operator WGPURenderBundleEncoder() const { return get(); }
};
WGPURenderBundleEncoderRef ref( WGPURenderBundleEncoder RenderBundleEncoder ) { return WGPURenderBundleEncoderRef( RenderBundleEncoder ); }

struct WGPURenderPassEncoderRef : public std::shared_ptr< std::remove_pointer<WGPURenderPassEncoder>::type > {
    WGPURenderPassEncoderRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPURenderPassEncoderRef( WGPURenderPassEncoder RenderPassEncoder ) : std::shared_ptr< std::remove_pointer<WGPURenderPassEncoder>::type >( RenderPassEncoder, [](WGPURenderPassEncoder RenderPassEncoder){ std::cout << "wgpuRenderPassEncoderRelease(): " << reinterpret_cast<std::uintptr_t>(RenderPassEncoder) << '\n'; } ) {}
#else
    WGPURenderPassEncoderRef( WGPURenderPassEncoder RenderPassEncoder ) : std::shared_ptr< std::remove_pointer<WGPURenderPassEncoder>::type >( RenderPassEncoder, [](WGPURenderPassEncoder RenderPassEncoder){ if( RenderPassEncoder ) wgpuRenderPassEncoderRelease; } ) {}
#endif
    operator WGPURenderPassEncoder() const { return get(); }
};
WGPURenderPassEncoderRef ref( WGPURenderPassEncoder RenderPassEncoder ) { return WGPURenderPassEncoderRef( RenderPassEncoder ); }

struct WGPURenderPipelineRef : public std::shared_ptr< std::remove_pointer<WGPURenderPipeline>::type > {
    WGPURenderPipelineRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPURenderPipelineRef( WGPURenderPipeline RenderPipeline ) : std::shared_ptr< std::remove_pointer<WGPURenderPipeline>::type >( RenderPipeline, [](WGPURenderPipeline RenderPipeline){ std::cout << "wgpuRenderPipelineRelease(): " << reinterpret_cast<std::uintptr_t>(RenderPipeline) << '\n'; } ) {}
#else
    WGPURenderPipelineRef( WGPURenderPipeline RenderPipeline ) : std::shared_ptr< std::remove_pointer<WGPURenderPipeline>::type >( RenderPipeline, [](WGPURenderPipeline RenderPipeline){ if( RenderPipeline ) wgpuRenderPipelineRelease; } ) {}
#endif
    operator WGPURenderPipeline() const { return get(); }
};
WGPURenderPipelineRef ref( WGPURenderPipeline RenderPipeline ) { return WGPURenderPipelineRef( RenderPipeline ); }

struct WGPUSamplerRef : public std::shared_ptr< std::remove_pointer<WGPUSampler>::type > {
    WGPUSamplerRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUSamplerRef( WGPUSampler Sampler ) : std::shared_ptr< std::remove_pointer<WGPUSampler>::type >( Sampler, [](WGPUSampler Sampler){ std::cout << "wgpuSamplerRelease(): " << reinterpret_cast<std::uintptr_t>(Sampler) << '\n'; } ) {}
#else
    WGPUSamplerRef( WGPUSampler Sampler ) : std::shared_ptr< std::remove_pointer<WGPUSampler>::type >( Sampler, [](WGPUSampler Sampler){ if( Sampler ) wgpuSamplerRelease; } ) {}
#endif
    operator WGPUSampler() const { return get(); }
};
WGPUSamplerRef ref( WGPUSampler Sampler ) { return WGPUSamplerRef( Sampler ); }

struct WGPUShaderModuleRef : public std::shared_ptr< std::remove_pointer<WGPUShaderModule>::type > {
    WGPUShaderModuleRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUShaderModuleRef( WGPUShaderModule ShaderModule ) : std::shared_ptr< std::remove_pointer<WGPUShaderModule>::type >( ShaderModule, [](WGPUShaderModule ShaderModule){ std::cout << "wgpuShaderModuleRelease(): " << reinterpret_cast<std::uintptr_t>(ShaderModule) << '\n'; } ) {}
#else
    WGPUShaderModuleRef( WGPUShaderModule ShaderModule ) : std::shared_ptr< std::remove_pointer<WGPUShaderModule>::type >( ShaderModule, [](WGPUShaderModule ShaderModule){ if( ShaderModule ) wgpuShaderModuleRelease; } ) {}
#endif
    operator WGPUShaderModule() const { return get(); }
};
WGPUShaderModuleRef ref( WGPUShaderModule ShaderModule ) { return WGPUShaderModuleRef( ShaderModule ); }

struct WGPUSurfaceRef : public std::shared_ptr< std::remove_pointer<WGPUSurface>::type > {
    WGPUSurfaceRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUSurfaceRef( WGPUSurface Surface ) : std::shared_ptr< std::remove_pointer<WGPUSurface>::type >( Surface, [](WGPUSurface Surface){ std::cout << "wgpuSurfaceRelease(): " << reinterpret_cast<std::uintptr_t>(Surface) << '\n'; } ) {}
#else
    WGPUSurfaceRef( WGPUSurface Surface ) : std::shared_ptr< std::remove_pointer<WGPUSurface>::type >( Surface, [](WGPUSurface Surface){ if( Surface ) wgpuSurfaceRelease; } ) {}
#endif
    operator WGPUSurface() const { return get(); }
};
WGPUSurfaceRef ref( WGPUSurface Surface ) { return WGPUSurfaceRef( Surface ); }

struct WGPUTextureRef : public std::shared_ptr< std::remove_pointer<WGPUTexture>::type > {
    WGPUTextureRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUTextureRef( WGPUTexture Texture ) : std::shared_ptr< std::remove_pointer<WGPUTexture>::type >( Texture, [](WGPUTexture Texture){ std::cout << "wgpuTextureRelease(): " << reinterpret_cast<std::uintptr_t>(Texture) << '\n'; } ) {}
#else
    WGPUTextureRef( WGPUTexture Texture ) : std::shared_ptr< std::remove_pointer<WGPUTexture>::type >( Texture, [](WGPUTexture Texture){ if( Texture ) wgpuTextureRelease; } ) {}
#endif
    operator WGPUTexture() const { return get(); }
};
WGPUTextureRef ref( WGPUTexture Texture ) { return WGPUTextureRef( Texture ); }

struct WGPUTextureViewRef : public std::shared_ptr< std::remove_pointer<WGPUTextureView>::type > {
    WGPUTextureViewRef() {}
#ifdef DEBUG_WEBGPU_RAII
    WGPUTextureViewRef( WGPUTextureView TextureView ) : std::shared_ptr< std::remove_pointer<WGPUTextureView>::type >( TextureView, [](WGPUTextureView TextureView){ std::cout << "wgpuTextureViewRelease(): " << reinterpret_cast<std::uintptr_t>(TextureView) << '\n'; } ) {}
#else
    WGPUTextureViewRef( WGPUTextureView TextureView ) : std::shared_ptr< std::remove_pointer<WGPUTextureView>::type >( TextureView, [](WGPUTextureView TextureView){ if( TextureView ) wgpuTextureViewRelease; } ) {}
#endif
    operator WGPUTextureView() const { return get(); }
};
WGPUTextureViewRef ref( WGPUTextureView TextureView ) { return WGPUTextureViewRef( TextureView ); }

