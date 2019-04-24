#include "d3d11_context.h"

namespace dxvk {
  
  D3D11DeviceContextExt::D3D11DeviceContextExt(
          D3D11DeviceContext*     pContext)
  : m_ctx(pContext) {
    
  }
  
  
  ULONG STDMETHODCALLTYPE D3D11DeviceContextExt::AddRef() {
    return m_ctx->AddRef();
  }
  
  
  ULONG STDMETHODCALLTYPE D3D11DeviceContextExt::Release() {
    return m_ctx->Release();
  }
  
  
  HRESULT STDMETHODCALLTYPE D3D11DeviceContextExt::QueryInterface(
          REFIID                  riid,
          void**                  ppvObject) {
    return m_ctx->QueryInterface(riid, ppvObject);
  }
  
  
  void STDMETHODCALLTYPE D3D11DeviceContextExt::MultiDrawIndirect(
          UINT                    DrawCount,
          ID3D11Buffer*           pBufferForArgs,
          UINT                    ByteOffsetForArgs,
          UINT                    ByteStrideForArgs) {
    
  }
  
  
  void STDMETHODCALLTYPE D3D11DeviceContextExt::MultiDrawIndexedIndirect(
          UINT                    DrawCount,
          ID3D11Buffer*           pBufferForArgs,
          UINT                    ByteOffsetForArgs,
          UINT                    ByteStrideForArgs) {
    
  }
  
  
  void STDMETHODCALLTYPE D3D11DeviceContextExt::MultiDrawIndirectCount(
          UINT                    MaxDrawCount,
          ID3D11Buffer*           pBufferForCount,
          UINT                    ByteOffsetForCount,
          ID3D11Buffer*           pBufferForArgs,
          UINT                    ByteOffsetForArgs,
          UINT                    ByteStrideForArgs) {
    
  }
  
  
  void STDMETHODCALLTYPE D3D11DeviceContextExt::MultiDrawIndexedIndirectCount(
          UINT                    MaxDrawCount,
          ID3D11Buffer*           pBufferForCount,
          UINT                    ByteOffsetForCount,
          ID3D11Buffer*           pBufferForArgs,
          UINT                    ByteOffsetForArgs,
          UINT                    ByteStrideForArgs) {
    
  }
  
  
  void STDMETHODCALLTYPE D3D11DeviceContextExt::SetDepthBoundsTest(
          BOOL                    Enable,
          FLOAT                   MinDepthBounds,
          FLOAT                   MaxDepthBounds) {
    
  }
  
  
  void STDMETHODCALLTYPE D3D11DeviceContextExt::SetBarrierControl(
          UINT                    ControlFlags) {
    D3D10DeviceLock lock = m_ctx->LockContext();
    DxvkBarrierControlFlags flags;
    
    if (ControlFlags & D3D11_VK_BARRIER_CONTROL_IGNORE_WRITE_AFTER_WRITE)
      flags.set(DxvkBarrierControl::IgnoreWriteAfterWrite);
    
    m_ctx->EmitCs([cFlags = flags] (DxvkContext* ctx) {
      ctx->setBarrierControl(cFlags);
    });
  }
  
}
