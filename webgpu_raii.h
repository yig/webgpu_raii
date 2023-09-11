#pragma once

#include <webgpu/webgpu.h>
#include <memory>

typedef std::unique_ptr< std::remove_pointer<WGPUAdapter>::type, void(*)(WGPUAdapter) > WGPUAdapterRef;
WGPUAdapterRef ref( WGPUAdapter Adapter ) { return WGPUAdapterRef( Adapter, wgpuAdapterRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUBindGroup>::type, void(*)(WGPUBindGroup) > WGPUBindGroupRef;
WGPUBindGroupRef ref( WGPUBindGroup BindGroup ) { return WGPUBindGroupRef( BindGroup, wgpuBindGroupRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUBindGroupLayout>::type, void(*)(WGPUBindGroupLayout) > WGPUBindGroupLayoutRef;
WGPUBindGroupLayoutRef ref( WGPUBindGroupLayout BindGroupLayout ) { return WGPUBindGroupLayoutRef( BindGroupLayout, wgpuBindGroupLayoutRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUBuffer>::type, void(*)(WGPUBuffer) > WGPUBufferRef;
WGPUBufferRef ref( WGPUBuffer Buffer ) { return WGPUBufferRef( Buffer, wgpuBufferRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUCommandBuffer>::type, void(*)(WGPUCommandBuffer) > WGPUCommandBufferRef;
WGPUCommandBufferRef ref( WGPUCommandBuffer CommandBuffer ) { return WGPUCommandBufferRef( CommandBuffer, wgpuCommandBufferRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUCommandEncoder>::type, void(*)(WGPUCommandEncoder) > WGPUCommandEncoderRef;
WGPUCommandEncoderRef ref( WGPUCommandEncoder CommandEncoder ) { return WGPUCommandEncoderRef( CommandEncoder, wgpuCommandEncoderRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUComputePassEncoder>::type, void(*)(WGPUComputePassEncoder) > WGPUComputePassEncoderRef;
WGPUComputePassEncoderRef ref( WGPUComputePassEncoder ComputePassEncoder ) { return WGPUComputePassEncoderRef( ComputePassEncoder, wgpuComputePassEncoderRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUComputePipeline>::type, void(*)(WGPUComputePipeline) > WGPUComputePipelineRef;
WGPUComputePipelineRef ref( WGPUComputePipeline ComputePipeline ) { return WGPUComputePipelineRef( ComputePipeline, wgpuComputePipelineRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUDevice>::type, void(*)(WGPUDevice) > WGPUDeviceRef;
WGPUDeviceRef ref( WGPUDevice Device ) { return WGPUDeviceRef( Device, wgpuDeviceRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUInstance>::type, void(*)(WGPUInstance) > WGPUInstanceRef;
WGPUInstanceRef ref( WGPUInstance Instance ) { return WGPUInstanceRef( Instance, wgpuInstanceRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUPipelineLayout>::type, void(*)(WGPUPipelineLayout) > WGPUPipelineLayoutRef;
WGPUPipelineLayoutRef ref( WGPUPipelineLayout PipelineLayout ) { return WGPUPipelineLayoutRef( PipelineLayout, wgpuPipelineLayoutRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUQuerySet>::type, void(*)(WGPUQuerySet) > WGPUQuerySetRef;
WGPUQuerySetRef ref( WGPUQuerySet QuerySet ) { return WGPUQuerySetRef( QuerySet, wgpuQuerySetRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUQueue>::type, void(*)(WGPUQueue) > WGPUQueueRef;
WGPUQueueRef ref( WGPUQueue Queue ) { return WGPUQueueRef( Queue, wgpuQueueRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPURenderBundle>::type, void(*)(WGPURenderBundle) > WGPURenderBundleRef;
WGPURenderBundleRef ref( WGPURenderBundle RenderBundle ) { return WGPURenderBundleRef( RenderBundle, wgpuRenderBundleRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPURenderBundleEncoder>::type, void(*)(WGPURenderBundleEncoder) > WGPURenderBundleEncoderRef;
WGPURenderBundleEncoderRef ref( WGPURenderBundleEncoder RenderBundleEncoder ) { return WGPURenderBundleEncoderRef( RenderBundleEncoder, wgpuRenderBundleEncoderRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPURenderPassEncoder>::type, void(*)(WGPURenderPassEncoder) > WGPURenderPassEncoderRef;
WGPURenderPassEncoderRef ref( WGPURenderPassEncoder RenderPassEncoder ) { return WGPURenderPassEncoderRef( RenderPassEncoder, wgpuRenderPassEncoderRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPURenderPipeline>::type, void(*)(WGPURenderPipeline) > WGPURenderPipelineRef;
WGPURenderPipelineRef ref( WGPURenderPipeline RenderPipeline ) { return WGPURenderPipelineRef( RenderPipeline, wgpuRenderPipelineRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUSampler>::type, void(*)(WGPUSampler) > WGPUSamplerRef;
WGPUSamplerRef ref( WGPUSampler Sampler ) { return WGPUSamplerRef( Sampler, wgpuSamplerRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUShaderModule>::type, void(*)(WGPUShaderModule) > WGPUShaderModuleRef;
WGPUShaderModuleRef ref( WGPUShaderModule ShaderModule ) { return WGPUShaderModuleRef( ShaderModule, wgpuShaderModuleRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUSurface>::type, void(*)(WGPUSurface) > WGPUSurfaceRef;
WGPUSurfaceRef ref( WGPUSurface Surface ) { return WGPUSurfaceRef( Surface, wgpuSurfaceRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUTexture>::type, void(*)(WGPUTexture) > WGPUTextureRef;
WGPUTextureRef ref( WGPUTexture Texture ) { return WGPUTextureRef( Texture, wgpuTextureRelease ); }

typedef std::unique_ptr< std::remove_pointer<WGPUTextureView>::type, void(*)(WGPUTextureView) > WGPUTextureViewRef;
WGPUTextureViewRef ref( WGPUTextureView TextureView ) { return WGPUTextureViewRef( TextureView, wgpuTextureViewRelease ); }

