#pragma once

#include <webgpu/webgpu.h>
#include <memory>

struct WGPUAdapterRef : public std::shared_ptr< std::remove_pointer<WGPUAdapter>::type > {
    WGPUAdapterRef( WGPUAdapter Adapter ) : std::shared_ptr< std::remove_pointer<WGPUAdapter>::type >( Adapter, wgpuAdapterRelease ) {}
    operator WGPUAdapter() const { return get(); }
};
WGPUAdapterRef ref( WGPUAdapter Adapter ) { return WGPUAdapterRef( Adapter ); }

struct WGPUBindGroupRef : public std::shared_ptr< std::remove_pointer<WGPUBindGroup>::type > {
    WGPUBindGroupRef( WGPUBindGroup BindGroup ) : std::shared_ptr< std::remove_pointer<WGPUBindGroup>::type >( BindGroup, wgpuBindGroupRelease ) {}
    operator WGPUBindGroup() const { return get(); }
};
WGPUBindGroupRef ref( WGPUBindGroup BindGroup ) { return WGPUBindGroupRef( BindGroup ); }

struct WGPUBindGroupLayoutRef : public std::shared_ptr< std::remove_pointer<WGPUBindGroupLayout>::type > {
    WGPUBindGroupLayoutRef( WGPUBindGroupLayout BindGroupLayout ) : std::shared_ptr< std::remove_pointer<WGPUBindGroupLayout>::type >( BindGroupLayout, wgpuBindGroupLayoutRelease ) {}
    operator WGPUBindGroupLayout() const { return get(); }
};
WGPUBindGroupLayoutRef ref( WGPUBindGroupLayout BindGroupLayout ) { return WGPUBindGroupLayoutRef( BindGroupLayout ); }

struct WGPUBufferRef : public std::shared_ptr< std::remove_pointer<WGPUBuffer>::type > {
    WGPUBufferRef( WGPUBuffer Buffer ) : std::shared_ptr< std::remove_pointer<WGPUBuffer>::type >( Buffer, wgpuBufferRelease ) {}
    operator WGPUBuffer() const { return get(); }
};
WGPUBufferRef ref( WGPUBuffer Buffer ) { return WGPUBufferRef( Buffer ); }

struct WGPUCommandBufferRef : public std::shared_ptr< std::remove_pointer<WGPUCommandBuffer>::type > {
    WGPUCommandBufferRef( WGPUCommandBuffer CommandBuffer ) : std::shared_ptr< std::remove_pointer<WGPUCommandBuffer>::type >( CommandBuffer, wgpuCommandBufferRelease ) {}
    operator WGPUCommandBuffer() const { return get(); }
};
WGPUCommandBufferRef ref( WGPUCommandBuffer CommandBuffer ) { return WGPUCommandBufferRef( CommandBuffer ); }

struct WGPUCommandEncoderRef : public std::shared_ptr< std::remove_pointer<WGPUCommandEncoder>::type > {
    WGPUCommandEncoderRef( WGPUCommandEncoder CommandEncoder ) : std::shared_ptr< std::remove_pointer<WGPUCommandEncoder>::type >( CommandEncoder, wgpuCommandEncoderRelease ) {}
    operator WGPUCommandEncoder() const { return get(); }
};
WGPUCommandEncoderRef ref( WGPUCommandEncoder CommandEncoder ) { return WGPUCommandEncoderRef( CommandEncoder ); }

struct WGPUComputePassEncoderRef : public std::shared_ptr< std::remove_pointer<WGPUComputePassEncoder>::type > {
    WGPUComputePassEncoderRef( WGPUComputePassEncoder ComputePassEncoder ) : std::shared_ptr< std::remove_pointer<WGPUComputePassEncoder>::type >( ComputePassEncoder, wgpuComputePassEncoderRelease ) {}
    operator WGPUComputePassEncoder() const { return get(); }
};
WGPUComputePassEncoderRef ref( WGPUComputePassEncoder ComputePassEncoder ) { return WGPUComputePassEncoderRef( ComputePassEncoder ); }

struct WGPUComputePipelineRef : public std::shared_ptr< std::remove_pointer<WGPUComputePipeline>::type > {
    WGPUComputePipelineRef( WGPUComputePipeline ComputePipeline ) : std::shared_ptr< std::remove_pointer<WGPUComputePipeline>::type >( ComputePipeline, wgpuComputePipelineRelease ) {}
    operator WGPUComputePipeline() const { return get(); }
};
WGPUComputePipelineRef ref( WGPUComputePipeline ComputePipeline ) { return WGPUComputePipelineRef( ComputePipeline ); }

struct WGPUDeviceRef : public std::shared_ptr< std::remove_pointer<WGPUDevice>::type > {
    WGPUDeviceRef( WGPUDevice Device ) : std::shared_ptr< std::remove_pointer<WGPUDevice>::type >( Device, wgpuDeviceRelease ) {}
    operator WGPUDevice() const { return get(); }
};
WGPUDeviceRef ref( WGPUDevice Device ) { return WGPUDeviceRef( Device ); }

struct WGPUInstanceRef : public std::shared_ptr< std::remove_pointer<WGPUInstance>::type > {
    WGPUInstanceRef( WGPUInstance Instance ) : std::shared_ptr< std::remove_pointer<WGPUInstance>::type >( Instance, wgpuInstanceRelease ) {}
    operator WGPUInstance() const { return get(); }
};
WGPUInstanceRef ref( WGPUInstance Instance ) { return WGPUInstanceRef( Instance ); }

struct WGPUPipelineLayoutRef : public std::shared_ptr< std::remove_pointer<WGPUPipelineLayout>::type > {
    WGPUPipelineLayoutRef( WGPUPipelineLayout PipelineLayout ) : std::shared_ptr< std::remove_pointer<WGPUPipelineLayout>::type >( PipelineLayout, wgpuPipelineLayoutRelease ) {}
    operator WGPUPipelineLayout() const { return get(); }
};
WGPUPipelineLayoutRef ref( WGPUPipelineLayout PipelineLayout ) { return WGPUPipelineLayoutRef( PipelineLayout ); }

struct WGPUQuerySetRef : public std::shared_ptr< std::remove_pointer<WGPUQuerySet>::type > {
    WGPUQuerySetRef( WGPUQuerySet QuerySet ) : std::shared_ptr< std::remove_pointer<WGPUQuerySet>::type >( QuerySet, wgpuQuerySetRelease ) {}
    operator WGPUQuerySet() const { return get(); }
};
WGPUQuerySetRef ref( WGPUQuerySet QuerySet ) { return WGPUQuerySetRef( QuerySet ); }

struct WGPUQueueRef : public std::shared_ptr< std::remove_pointer<WGPUQueue>::type > {
    WGPUQueueRef( WGPUQueue Queue ) : std::shared_ptr< std::remove_pointer<WGPUQueue>::type >( Queue, wgpuQueueRelease ) {}
    operator WGPUQueue() const { return get(); }
};
WGPUQueueRef ref( WGPUQueue Queue ) { return WGPUQueueRef( Queue ); }

struct WGPURenderBundleRef : public std::shared_ptr< std::remove_pointer<WGPURenderBundle>::type > {
    WGPURenderBundleRef( WGPURenderBundle RenderBundle ) : std::shared_ptr< std::remove_pointer<WGPURenderBundle>::type >( RenderBundle, wgpuRenderBundleRelease ) {}
    operator WGPURenderBundle() const { return get(); }
};
WGPURenderBundleRef ref( WGPURenderBundle RenderBundle ) { return WGPURenderBundleRef( RenderBundle ); }

struct WGPURenderBundleEncoderRef : public std::shared_ptr< std::remove_pointer<WGPURenderBundleEncoder>::type > {
    WGPURenderBundleEncoderRef( WGPURenderBundleEncoder RenderBundleEncoder ) : std::shared_ptr< std::remove_pointer<WGPURenderBundleEncoder>::type >( RenderBundleEncoder, wgpuRenderBundleEncoderRelease ) {}
    operator WGPURenderBundleEncoder() const { return get(); }
};
WGPURenderBundleEncoderRef ref( WGPURenderBundleEncoder RenderBundleEncoder ) { return WGPURenderBundleEncoderRef( RenderBundleEncoder ); }

struct WGPURenderPassEncoderRef : public std::shared_ptr< std::remove_pointer<WGPURenderPassEncoder>::type > {
    WGPURenderPassEncoderRef( WGPURenderPassEncoder RenderPassEncoder ) : std::shared_ptr< std::remove_pointer<WGPURenderPassEncoder>::type >( RenderPassEncoder, wgpuRenderPassEncoderRelease ) {}
    operator WGPURenderPassEncoder() const { return get(); }
};
WGPURenderPassEncoderRef ref( WGPURenderPassEncoder RenderPassEncoder ) { return WGPURenderPassEncoderRef( RenderPassEncoder ); }

struct WGPURenderPipelineRef : public std::shared_ptr< std::remove_pointer<WGPURenderPipeline>::type > {
    WGPURenderPipelineRef( WGPURenderPipeline RenderPipeline ) : std::shared_ptr< std::remove_pointer<WGPURenderPipeline>::type >( RenderPipeline, wgpuRenderPipelineRelease ) {}
    operator WGPURenderPipeline() const { return get(); }
};
WGPURenderPipelineRef ref( WGPURenderPipeline RenderPipeline ) { return WGPURenderPipelineRef( RenderPipeline ); }

struct WGPUSamplerRef : public std::shared_ptr< std::remove_pointer<WGPUSampler>::type > {
    WGPUSamplerRef( WGPUSampler Sampler ) : std::shared_ptr< std::remove_pointer<WGPUSampler>::type >( Sampler, wgpuSamplerRelease ) {}
    operator WGPUSampler() const { return get(); }
};
WGPUSamplerRef ref( WGPUSampler Sampler ) { return WGPUSamplerRef( Sampler ); }

struct WGPUShaderModuleRef : public std::shared_ptr< std::remove_pointer<WGPUShaderModule>::type > {
    WGPUShaderModuleRef( WGPUShaderModule ShaderModule ) : std::shared_ptr< std::remove_pointer<WGPUShaderModule>::type >( ShaderModule, wgpuShaderModuleRelease ) {}
    operator WGPUShaderModule() const { return get(); }
};
WGPUShaderModuleRef ref( WGPUShaderModule ShaderModule ) { return WGPUShaderModuleRef( ShaderModule ); }

struct WGPUSurfaceRef : public std::shared_ptr< std::remove_pointer<WGPUSurface>::type > {
    WGPUSurfaceRef( WGPUSurface Surface ) : std::shared_ptr< std::remove_pointer<WGPUSurface>::type >( Surface, wgpuSurfaceRelease ) {}
    operator WGPUSurface() const { return get(); }
};
WGPUSurfaceRef ref( WGPUSurface Surface ) { return WGPUSurfaceRef( Surface ); }

struct WGPUTextureRef : public std::shared_ptr< std::remove_pointer<WGPUTexture>::type > {
    WGPUTextureRef( WGPUTexture Texture ) : std::shared_ptr< std::remove_pointer<WGPUTexture>::type >( Texture, wgpuTextureRelease ) {}
    operator WGPUTexture() const { return get(); }
};
WGPUTextureRef ref( WGPUTexture Texture ) { return WGPUTextureRef( Texture ); }

struct WGPUTextureViewRef : public std::shared_ptr< std::remove_pointer<WGPUTextureView>::type > {
    WGPUTextureViewRef( WGPUTextureView TextureView ) : std::shared_ptr< std::remove_pointer<WGPUTextureView>::type >( TextureView, wgpuTextureViewRelease ) {}
    operator WGPUTextureView() const { return get(); }
};
WGPUTextureViewRef ref( WGPUTextureView TextureView ) { return WGPUTextureViewRef( TextureView ); }

