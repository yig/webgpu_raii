#pragma once

#include <webgpu/webgpu.h>
#include <memory>

#ifdef WEBGPU_RAII_DEBUG
#include <iostream>
#endif

struct WGPUAdapterRef : public std::shared_ptr< std::remove_pointer<WGPUAdapter>::type > {
    WGPUAdapterRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUAdapterRef( WGPUAdapter Adapter ) : std::shared_ptr< std::remove_pointer<WGPUAdapter>::type >( Adapter, [](WGPUAdapter Adapter){
        std::cout << "wgpuAdapterRelease(): " << reinterpret_cast<std::uintptr_t>(Adapter) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( Adapter ) wgpuAdapterRelease( Adapter );
#endif
        } ) {
        std::cout << "Acquired a WGPUAdapter: " << reinterpret_cast<std::uintptr_t>(Adapter) << '\n';
        }
#else
    WGPUAdapterRef( WGPUAdapter Adapter ) : std::shared_ptr< std::remove_pointer<WGPUAdapter>::type >( Adapter, [](WGPUAdapter Adapter){ if( Adapter ) wgpuAdapterRelease( Adapter ); } ) {}
#endif
    operator WGPUAdapter() const { return get(); }
};
inline WGPUAdapterRef ref( WGPUAdapter Adapter ) { return WGPUAdapterRef( Adapter ); }

struct WGPUBindGroupRef : public std::shared_ptr< std::remove_pointer<WGPUBindGroup>::type > {
    WGPUBindGroupRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUBindGroupRef( WGPUBindGroup BindGroup ) : std::shared_ptr< std::remove_pointer<WGPUBindGroup>::type >( BindGroup, [](WGPUBindGroup BindGroup){
        std::cout << "wgpuBindGroupRelease(): " << reinterpret_cast<std::uintptr_t>(BindGroup) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( BindGroup ) wgpuBindGroupRelease( BindGroup );
#endif
        } ) {
        std::cout << "Acquired a WGPUBindGroup: " << reinterpret_cast<std::uintptr_t>(BindGroup) << '\n';
        }
#else
    WGPUBindGroupRef( WGPUBindGroup BindGroup ) : std::shared_ptr< std::remove_pointer<WGPUBindGroup>::type >( BindGroup, [](WGPUBindGroup BindGroup){ if( BindGroup ) wgpuBindGroupRelease( BindGroup ); } ) {}
#endif
    operator WGPUBindGroup() const { return get(); }
};
inline WGPUBindGroupRef ref( WGPUBindGroup BindGroup ) { return WGPUBindGroupRef( BindGroup ); }

struct WGPUBindGroupLayoutRef : public std::shared_ptr< std::remove_pointer<WGPUBindGroupLayout>::type > {
    WGPUBindGroupLayoutRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUBindGroupLayoutRef( WGPUBindGroupLayout BindGroupLayout ) : std::shared_ptr< std::remove_pointer<WGPUBindGroupLayout>::type >( BindGroupLayout, [](WGPUBindGroupLayout BindGroupLayout){
        std::cout << "wgpuBindGroupLayoutRelease(): " << reinterpret_cast<std::uintptr_t>(BindGroupLayout) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( BindGroupLayout ) wgpuBindGroupLayoutRelease( BindGroupLayout );
#endif
        } ) {
        std::cout << "Acquired a WGPUBindGroupLayout: " << reinterpret_cast<std::uintptr_t>(BindGroupLayout) << '\n';
        }
#else
    WGPUBindGroupLayoutRef( WGPUBindGroupLayout BindGroupLayout ) : std::shared_ptr< std::remove_pointer<WGPUBindGroupLayout>::type >( BindGroupLayout, [](WGPUBindGroupLayout BindGroupLayout){ if( BindGroupLayout ) wgpuBindGroupLayoutRelease( BindGroupLayout ); } ) {}
#endif
    operator WGPUBindGroupLayout() const { return get(); }
};
inline WGPUBindGroupLayoutRef ref( WGPUBindGroupLayout BindGroupLayout ) { return WGPUBindGroupLayoutRef( BindGroupLayout ); }

struct WGPUBufferRef : public std::shared_ptr< std::remove_pointer<WGPUBuffer>::type > {
    WGPUBufferRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUBufferRef( WGPUBuffer Buffer ) : std::shared_ptr< std::remove_pointer<WGPUBuffer>::type >( Buffer, [](WGPUBuffer Buffer){
        std::cout << "wgpuBufferRelease(): " << reinterpret_cast<std::uintptr_t>(Buffer) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( Buffer ) wgpuBufferRelease( Buffer );
#endif
        } ) {
        std::cout << "Acquired a WGPUBuffer: " << reinterpret_cast<std::uintptr_t>(Buffer) << '\n';
        }
#else
    WGPUBufferRef( WGPUBuffer Buffer ) : std::shared_ptr< std::remove_pointer<WGPUBuffer>::type >( Buffer, [](WGPUBuffer Buffer){ if( Buffer ) wgpuBufferRelease( Buffer ); } ) {}
#endif
    operator WGPUBuffer() const { return get(); }
};
inline WGPUBufferRef ref( WGPUBuffer Buffer ) { return WGPUBufferRef( Buffer ); }

struct WGPUCommandBufferRef : public std::shared_ptr< std::remove_pointer<WGPUCommandBuffer>::type > {
    WGPUCommandBufferRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUCommandBufferRef( WGPUCommandBuffer CommandBuffer ) : std::shared_ptr< std::remove_pointer<WGPUCommandBuffer>::type >( CommandBuffer, [](WGPUCommandBuffer CommandBuffer){
        std::cout << "wgpuCommandBufferRelease(): " << reinterpret_cast<std::uintptr_t>(CommandBuffer) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( CommandBuffer ) wgpuCommandBufferRelease( CommandBuffer );
#endif
        } ) {
        std::cout << "Acquired a WGPUCommandBuffer: " << reinterpret_cast<std::uintptr_t>(CommandBuffer) << '\n';
        }
#else
    WGPUCommandBufferRef( WGPUCommandBuffer CommandBuffer ) : std::shared_ptr< std::remove_pointer<WGPUCommandBuffer>::type >( CommandBuffer, [](WGPUCommandBuffer CommandBuffer){ if( CommandBuffer ) wgpuCommandBufferRelease( CommandBuffer ); } ) {}
#endif
    operator WGPUCommandBuffer() const { return get(); }
};
inline WGPUCommandBufferRef ref( WGPUCommandBuffer CommandBuffer ) { return WGPUCommandBufferRef( CommandBuffer ); }

struct WGPUCommandEncoderRef : public std::shared_ptr< std::remove_pointer<WGPUCommandEncoder>::type > {
    WGPUCommandEncoderRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUCommandEncoderRef( WGPUCommandEncoder CommandEncoder ) : std::shared_ptr< std::remove_pointer<WGPUCommandEncoder>::type >( CommandEncoder, [](WGPUCommandEncoder CommandEncoder){
        std::cout << "wgpuCommandEncoderRelease(): " << reinterpret_cast<std::uintptr_t>(CommandEncoder) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( CommandEncoder ) wgpuCommandEncoderRelease( CommandEncoder );
#endif
        } ) {
        std::cout << "Acquired a WGPUCommandEncoder: " << reinterpret_cast<std::uintptr_t>(CommandEncoder) << '\n';
        }
#else
    WGPUCommandEncoderRef( WGPUCommandEncoder CommandEncoder ) : std::shared_ptr< std::remove_pointer<WGPUCommandEncoder>::type >( CommandEncoder, [](WGPUCommandEncoder CommandEncoder){ if( CommandEncoder ) wgpuCommandEncoderRelease( CommandEncoder ); } ) {}
#endif
    operator WGPUCommandEncoder() const { return get(); }
};
inline WGPUCommandEncoderRef ref( WGPUCommandEncoder CommandEncoder ) { return WGPUCommandEncoderRef( CommandEncoder ); }

struct WGPUComputePassEncoderRef : public std::shared_ptr< std::remove_pointer<WGPUComputePassEncoder>::type > {
    WGPUComputePassEncoderRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUComputePassEncoderRef( WGPUComputePassEncoder ComputePassEncoder ) : std::shared_ptr< std::remove_pointer<WGPUComputePassEncoder>::type >( ComputePassEncoder, [](WGPUComputePassEncoder ComputePassEncoder){
        std::cout << "wgpuComputePassEncoderRelease(): " << reinterpret_cast<std::uintptr_t>(ComputePassEncoder) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( ComputePassEncoder ) wgpuComputePassEncoderRelease( ComputePassEncoder );
#endif
        } ) {
        std::cout << "Acquired a WGPUComputePassEncoder: " << reinterpret_cast<std::uintptr_t>(ComputePassEncoder) << '\n';
        }
#else
    WGPUComputePassEncoderRef( WGPUComputePassEncoder ComputePassEncoder ) : std::shared_ptr< std::remove_pointer<WGPUComputePassEncoder>::type >( ComputePassEncoder, [](WGPUComputePassEncoder ComputePassEncoder){ if( ComputePassEncoder ) wgpuComputePassEncoderRelease( ComputePassEncoder ); } ) {}
#endif
    operator WGPUComputePassEncoder() const { return get(); }
};
inline WGPUComputePassEncoderRef ref( WGPUComputePassEncoder ComputePassEncoder ) { return WGPUComputePassEncoderRef( ComputePassEncoder ); }

struct WGPUComputePipelineRef : public std::shared_ptr< std::remove_pointer<WGPUComputePipeline>::type > {
    WGPUComputePipelineRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUComputePipelineRef( WGPUComputePipeline ComputePipeline ) : std::shared_ptr< std::remove_pointer<WGPUComputePipeline>::type >( ComputePipeline, [](WGPUComputePipeline ComputePipeline){
        std::cout << "wgpuComputePipelineRelease(): " << reinterpret_cast<std::uintptr_t>(ComputePipeline) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( ComputePipeline ) wgpuComputePipelineRelease( ComputePipeline );
#endif
        } ) {
        std::cout << "Acquired a WGPUComputePipeline: " << reinterpret_cast<std::uintptr_t>(ComputePipeline) << '\n';
        }
#else
    WGPUComputePipelineRef( WGPUComputePipeline ComputePipeline ) : std::shared_ptr< std::remove_pointer<WGPUComputePipeline>::type >( ComputePipeline, [](WGPUComputePipeline ComputePipeline){ if( ComputePipeline ) wgpuComputePipelineRelease( ComputePipeline ); } ) {}
#endif
    operator WGPUComputePipeline() const { return get(); }
};
inline WGPUComputePipelineRef ref( WGPUComputePipeline ComputePipeline ) { return WGPUComputePipelineRef( ComputePipeline ); }

struct WGPUDeviceRef : public std::shared_ptr< std::remove_pointer<WGPUDevice>::type > {
    WGPUDeviceRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUDeviceRef( WGPUDevice Device ) : std::shared_ptr< std::remove_pointer<WGPUDevice>::type >( Device, [](WGPUDevice Device){
        std::cout << "wgpuDeviceRelease(): " << reinterpret_cast<std::uintptr_t>(Device) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( Device ) wgpuDeviceRelease( Device );
#endif
        } ) {
        std::cout << "Acquired a WGPUDevice: " << reinterpret_cast<std::uintptr_t>(Device) << '\n';
        }
#else
    WGPUDeviceRef( WGPUDevice Device ) : std::shared_ptr< std::remove_pointer<WGPUDevice>::type >( Device, [](WGPUDevice Device){ if( Device ) wgpuDeviceRelease( Device ); } ) {}
#endif
    operator WGPUDevice() const { return get(); }
};
inline WGPUDeviceRef ref( WGPUDevice Device ) { return WGPUDeviceRef( Device ); }

struct WGPUInstanceRef : public std::shared_ptr< std::remove_pointer<WGPUInstance>::type > {
    WGPUInstanceRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUInstanceRef( WGPUInstance Instance ) : std::shared_ptr< std::remove_pointer<WGPUInstance>::type >( Instance, [](WGPUInstance Instance){
        std::cout << "wgpuInstanceRelease(): " << reinterpret_cast<std::uintptr_t>(Instance) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( Instance ) wgpuInstanceRelease( Instance );
#endif
        } ) {
        std::cout << "Acquired a WGPUInstance: " << reinterpret_cast<std::uintptr_t>(Instance) << '\n';
        }
#else
    WGPUInstanceRef( WGPUInstance Instance ) : std::shared_ptr< std::remove_pointer<WGPUInstance>::type >( Instance, [](WGPUInstance Instance){ if( Instance ) wgpuInstanceRelease( Instance ); } ) {}
#endif
    operator WGPUInstance() const { return get(); }
};
inline WGPUInstanceRef ref( WGPUInstance Instance ) { return WGPUInstanceRef( Instance ); }

struct WGPUPipelineLayoutRef : public std::shared_ptr< std::remove_pointer<WGPUPipelineLayout>::type > {
    WGPUPipelineLayoutRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUPipelineLayoutRef( WGPUPipelineLayout PipelineLayout ) : std::shared_ptr< std::remove_pointer<WGPUPipelineLayout>::type >( PipelineLayout, [](WGPUPipelineLayout PipelineLayout){
        std::cout << "wgpuPipelineLayoutRelease(): " << reinterpret_cast<std::uintptr_t>(PipelineLayout) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( PipelineLayout ) wgpuPipelineLayoutRelease( PipelineLayout );
#endif
        } ) {
        std::cout << "Acquired a WGPUPipelineLayout: " << reinterpret_cast<std::uintptr_t>(PipelineLayout) << '\n';
        }
#else
    WGPUPipelineLayoutRef( WGPUPipelineLayout PipelineLayout ) : std::shared_ptr< std::remove_pointer<WGPUPipelineLayout>::type >( PipelineLayout, [](WGPUPipelineLayout PipelineLayout){ if( PipelineLayout ) wgpuPipelineLayoutRelease( PipelineLayout ); } ) {}
#endif
    operator WGPUPipelineLayout() const { return get(); }
};
inline WGPUPipelineLayoutRef ref( WGPUPipelineLayout PipelineLayout ) { return WGPUPipelineLayoutRef( PipelineLayout ); }

struct WGPUQuerySetRef : public std::shared_ptr< std::remove_pointer<WGPUQuerySet>::type > {
    WGPUQuerySetRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUQuerySetRef( WGPUQuerySet QuerySet ) : std::shared_ptr< std::remove_pointer<WGPUQuerySet>::type >( QuerySet, [](WGPUQuerySet QuerySet){
        std::cout << "wgpuQuerySetRelease(): " << reinterpret_cast<std::uintptr_t>(QuerySet) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( QuerySet ) wgpuQuerySetRelease( QuerySet );
#endif
        } ) {
        std::cout << "Acquired a WGPUQuerySet: " << reinterpret_cast<std::uintptr_t>(QuerySet) << '\n';
        }
#else
    WGPUQuerySetRef( WGPUQuerySet QuerySet ) : std::shared_ptr< std::remove_pointer<WGPUQuerySet>::type >( QuerySet, [](WGPUQuerySet QuerySet){ if( QuerySet ) wgpuQuerySetRelease( QuerySet ); } ) {}
#endif
    operator WGPUQuerySet() const { return get(); }
};
inline WGPUQuerySetRef ref( WGPUQuerySet QuerySet ) { return WGPUQuerySetRef( QuerySet ); }

struct WGPUQueueRef : public std::shared_ptr< std::remove_pointer<WGPUQueue>::type > {
    WGPUQueueRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUQueueRef( WGPUQueue Queue ) : std::shared_ptr< std::remove_pointer<WGPUQueue>::type >( Queue, [](WGPUQueue Queue){
        std::cout << "wgpuQueueRelease(): " << reinterpret_cast<std::uintptr_t>(Queue) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( Queue ) wgpuQueueRelease( Queue );
#endif
        } ) {
        std::cout << "Acquired a WGPUQueue: " << reinterpret_cast<std::uintptr_t>(Queue) << '\n';
        }
#else
    WGPUQueueRef( WGPUQueue Queue ) : std::shared_ptr< std::remove_pointer<WGPUQueue>::type >( Queue, [](WGPUQueue Queue){ if( Queue ) wgpuQueueRelease( Queue ); } ) {}
#endif
    operator WGPUQueue() const { return get(); }
};
inline WGPUQueueRef ref( WGPUQueue Queue ) { return WGPUQueueRef( Queue ); }

struct WGPURenderBundleRef : public std::shared_ptr< std::remove_pointer<WGPURenderBundle>::type > {
    WGPURenderBundleRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPURenderBundleRef( WGPURenderBundle RenderBundle ) : std::shared_ptr< std::remove_pointer<WGPURenderBundle>::type >( RenderBundle, [](WGPURenderBundle RenderBundle){
        std::cout << "wgpuRenderBundleRelease(): " << reinterpret_cast<std::uintptr_t>(RenderBundle) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( RenderBundle ) wgpuRenderBundleRelease( RenderBundle );
#endif
        } ) {
        std::cout << "Acquired a WGPURenderBundle: " << reinterpret_cast<std::uintptr_t>(RenderBundle) << '\n';
        }
#else
    WGPURenderBundleRef( WGPURenderBundle RenderBundle ) : std::shared_ptr< std::remove_pointer<WGPURenderBundle>::type >( RenderBundle, [](WGPURenderBundle RenderBundle){ if( RenderBundle ) wgpuRenderBundleRelease( RenderBundle ); } ) {}
#endif
    operator WGPURenderBundle() const { return get(); }
};
inline WGPURenderBundleRef ref( WGPURenderBundle RenderBundle ) { return WGPURenderBundleRef( RenderBundle ); }

struct WGPURenderBundleEncoderRef : public std::shared_ptr< std::remove_pointer<WGPURenderBundleEncoder>::type > {
    WGPURenderBundleEncoderRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPURenderBundleEncoderRef( WGPURenderBundleEncoder RenderBundleEncoder ) : std::shared_ptr< std::remove_pointer<WGPURenderBundleEncoder>::type >( RenderBundleEncoder, [](WGPURenderBundleEncoder RenderBundleEncoder){
        std::cout << "wgpuRenderBundleEncoderRelease(): " << reinterpret_cast<std::uintptr_t>(RenderBundleEncoder) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( RenderBundleEncoder ) wgpuRenderBundleEncoderRelease( RenderBundleEncoder );
#endif
        } ) {
        std::cout << "Acquired a WGPURenderBundleEncoder: " << reinterpret_cast<std::uintptr_t>(RenderBundleEncoder) << '\n';
        }
#else
    WGPURenderBundleEncoderRef( WGPURenderBundleEncoder RenderBundleEncoder ) : std::shared_ptr< std::remove_pointer<WGPURenderBundleEncoder>::type >( RenderBundleEncoder, [](WGPURenderBundleEncoder RenderBundleEncoder){ if( RenderBundleEncoder ) wgpuRenderBundleEncoderRelease( RenderBundleEncoder ); } ) {}
#endif
    operator WGPURenderBundleEncoder() const { return get(); }
};
inline WGPURenderBundleEncoderRef ref( WGPURenderBundleEncoder RenderBundleEncoder ) { return WGPURenderBundleEncoderRef( RenderBundleEncoder ); }

struct WGPURenderPassEncoderRef : public std::shared_ptr< std::remove_pointer<WGPURenderPassEncoder>::type > {
    WGPURenderPassEncoderRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPURenderPassEncoderRef( WGPURenderPassEncoder RenderPassEncoder ) : std::shared_ptr< std::remove_pointer<WGPURenderPassEncoder>::type >( RenderPassEncoder, [](WGPURenderPassEncoder RenderPassEncoder){
        std::cout << "wgpuRenderPassEncoderRelease(): " << reinterpret_cast<std::uintptr_t>(RenderPassEncoder) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( RenderPassEncoder ) wgpuRenderPassEncoderRelease( RenderPassEncoder );
#endif
        } ) {
        std::cout << "Acquired a WGPURenderPassEncoder: " << reinterpret_cast<std::uintptr_t>(RenderPassEncoder) << '\n';
        }
#else
    WGPURenderPassEncoderRef( WGPURenderPassEncoder RenderPassEncoder ) : std::shared_ptr< std::remove_pointer<WGPURenderPassEncoder>::type >( RenderPassEncoder, [](WGPURenderPassEncoder RenderPassEncoder){ if( RenderPassEncoder ) wgpuRenderPassEncoderRelease( RenderPassEncoder ); } ) {}
#endif
    operator WGPURenderPassEncoder() const { return get(); }
};
inline WGPURenderPassEncoderRef ref( WGPURenderPassEncoder RenderPassEncoder ) { return WGPURenderPassEncoderRef( RenderPassEncoder ); }

struct WGPURenderPipelineRef : public std::shared_ptr< std::remove_pointer<WGPURenderPipeline>::type > {
    WGPURenderPipelineRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPURenderPipelineRef( WGPURenderPipeline RenderPipeline ) : std::shared_ptr< std::remove_pointer<WGPURenderPipeline>::type >( RenderPipeline, [](WGPURenderPipeline RenderPipeline){
        std::cout << "wgpuRenderPipelineRelease(): " << reinterpret_cast<std::uintptr_t>(RenderPipeline) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( RenderPipeline ) wgpuRenderPipelineRelease( RenderPipeline );
#endif
        } ) {
        std::cout << "Acquired a WGPURenderPipeline: " << reinterpret_cast<std::uintptr_t>(RenderPipeline) << '\n';
        }
#else
    WGPURenderPipelineRef( WGPURenderPipeline RenderPipeline ) : std::shared_ptr< std::remove_pointer<WGPURenderPipeline>::type >( RenderPipeline, [](WGPURenderPipeline RenderPipeline){ if( RenderPipeline ) wgpuRenderPipelineRelease( RenderPipeline ); } ) {}
#endif
    operator WGPURenderPipeline() const { return get(); }
};
inline WGPURenderPipelineRef ref( WGPURenderPipeline RenderPipeline ) { return WGPURenderPipelineRef( RenderPipeline ); }

struct WGPUSamplerRef : public std::shared_ptr< std::remove_pointer<WGPUSampler>::type > {
    WGPUSamplerRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUSamplerRef( WGPUSampler Sampler ) : std::shared_ptr< std::remove_pointer<WGPUSampler>::type >( Sampler, [](WGPUSampler Sampler){
        std::cout << "wgpuSamplerRelease(): " << reinterpret_cast<std::uintptr_t>(Sampler) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( Sampler ) wgpuSamplerRelease( Sampler );
#endif
        } ) {
        std::cout << "Acquired a WGPUSampler: " << reinterpret_cast<std::uintptr_t>(Sampler) << '\n';
        }
#else
    WGPUSamplerRef( WGPUSampler Sampler ) : std::shared_ptr< std::remove_pointer<WGPUSampler>::type >( Sampler, [](WGPUSampler Sampler){ if( Sampler ) wgpuSamplerRelease( Sampler ); } ) {}
#endif
    operator WGPUSampler() const { return get(); }
};
inline WGPUSamplerRef ref( WGPUSampler Sampler ) { return WGPUSamplerRef( Sampler ); }

struct WGPUShaderModuleRef : public std::shared_ptr< std::remove_pointer<WGPUShaderModule>::type > {
    WGPUShaderModuleRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUShaderModuleRef( WGPUShaderModule ShaderModule ) : std::shared_ptr< std::remove_pointer<WGPUShaderModule>::type >( ShaderModule, [](WGPUShaderModule ShaderModule){
        std::cout << "wgpuShaderModuleRelease(): " << reinterpret_cast<std::uintptr_t>(ShaderModule) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( ShaderModule ) wgpuShaderModuleRelease( ShaderModule );
#endif
        } ) {
        std::cout << "Acquired a WGPUShaderModule: " << reinterpret_cast<std::uintptr_t>(ShaderModule) << '\n';
        }
#else
    WGPUShaderModuleRef( WGPUShaderModule ShaderModule ) : std::shared_ptr< std::remove_pointer<WGPUShaderModule>::type >( ShaderModule, [](WGPUShaderModule ShaderModule){ if( ShaderModule ) wgpuShaderModuleRelease( ShaderModule ); } ) {}
#endif
    operator WGPUShaderModule() const { return get(); }
};
inline WGPUShaderModuleRef ref( WGPUShaderModule ShaderModule ) { return WGPUShaderModuleRef( ShaderModule ); }

struct WGPUSurfaceRef : public std::shared_ptr< std::remove_pointer<WGPUSurface>::type > {
    WGPUSurfaceRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUSurfaceRef( WGPUSurface Surface ) : std::shared_ptr< std::remove_pointer<WGPUSurface>::type >( Surface, [](WGPUSurface Surface){
        std::cout << "wgpuSurfaceRelease(): " << reinterpret_cast<std::uintptr_t>(Surface) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( Surface ) wgpuSurfaceRelease( Surface );
#endif
        } ) {
        std::cout << "Acquired a WGPUSurface: " << reinterpret_cast<std::uintptr_t>(Surface) << '\n';
        }
#else
    WGPUSurfaceRef( WGPUSurface Surface ) : std::shared_ptr< std::remove_pointer<WGPUSurface>::type >( Surface, [](WGPUSurface Surface){ if( Surface ) wgpuSurfaceRelease( Surface ); } ) {}
#endif
    operator WGPUSurface() const { return get(); }
};
inline WGPUSurfaceRef ref( WGPUSurface Surface ) { return WGPUSurfaceRef( Surface ); }

struct WGPUSwapChainRef : public std::shared_ptr< std::remove_pointer<WGPUSwapChain>::type > {
    WGPUSwapChainRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUSwapChainRef( WGPUSwapChain SwapChain ) : std::shared_ptr< std::remove_pointer<WGPUSwapChain>::type >( SwapChain, [](WGPUSwapChain SwapChain){
        std::cout << "wgpuSwapChainRelease(): " << reinterpret_cast<std::uintptr_t>(SwapChain) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( SwapChain ) wgpuSwapChainRelease( SwapChain );
#endif
        } ) {
        std::cout << "Acquired a WGPUSwapChain: " << reinterpret_cast<std::uintptr_t>(SwapChain) << '\n';
        }
#else
    WGPUSwapChainRef( WGPUSwapChain SwapChain ) : std::shared_ptr< std::remove_pointer<WGPUSwapChain>::type >( SwapChain, [](WGPUSwapChain SwapChain){ if( SwapChain ) wgpuSwapChainRelease( SwapChain ); } ) {}
#endif
    operator WGPUSwapChain() const { return get(); }
};
inline WGPUSwapChainRef ref( WGPUSwapChain SwapChain ) { return WGPUSwapChainRef( SwapChain ); }

struct WGPUTextureRef : public std::shared_ptr< std::remove_pointer<WGPUTexture>::type > {
    WGPUTextureRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUTextureRef( WGPUTexture Texture ) : std::shared_ptr< std::remove_pointer<WGPUTexture>::type >( Texture, [](WGPUTexture Texture){
        std::cout << "wgpuTextureRelease(): " << reinterpret_cast<std::uintptr_t>(Texture) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( Texture ) wgpuTextureRelease( Texture );
#endif
        } ) {
        std::cout << "Acquired a WGPUTexture: " << reinterpret_cast<std::uintptr_t>(Texture) << '\n';
        }
#else
    WGPUTextureRef( WGPUTexture Texture ) : std::shared_ptr< std::remove_pointer<WGPUTexture>::type >( Texture, [](WGPUTexture Texture){ if( Texture ) wgpuTextureRelease( Texture ); } ) {}
#endif
    operator WGPUTexture() const { return get(); }
};
inline WGPUTextureRef ref( WGPUTexture Texture ) { return WGPUTextureRef( Texture ); }

struct WGPUTextureViewRef : public std::shared_ptr< std::remove_pointer<WGPUTextureView>::type > {
    WGPUTextureViewRef() {}
#ifdef WEBGPU_RAII_DEBUG
    WGPUTextureViewRef( WGPUTextureView TextureView ) : std::shared_ptr< std::remove_pointer<WGPUTextureView>::type >( TextureView, [](WGPUTextureView TextureView){
        std::cout << "wgpuTextureViewRelease(): " << reinterpret_cast<std::uintptr_t>(TextureView) << '\n';
#ifndef WEBGPU_RAII_LEAK
        if( TextureView ) wgpuTextureViewRelease( TextureView );
#endif
        } ) {
        std::cout << "Acquired a WGPUTextureView: " << reinterpret_cast<std::uintptr_t>(TextureView) << '\n';
        }
#else
    WGPUTextureViewRef( WGPUTextureView TextureView ) : std::shared_ptr< std::remove_pointer<WGPUTextureView>::type >( TextureView, [](WGPUTextureView TextureView){ if( TextureView ) wgpuTextureViewRelease( TextureView ); } ) {}
#endif
    operator WGPUTextureView() const { return get(); }
};
inline WGPUTextureViewRef ref( WGPUTextureView TextureView ) { return WGPUTextureViewRef( TextureView ); }

