

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for WindowSight.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __WindowSightidl_h__
#define __WindowSightidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DWindowSight_FWD_DEFINED__
#define ___DWindowSight_FWD_DEFINED__
typedef interface _DWindowSight _DWindowSight;

#endif 	/* ___DWindowSight_FWD_DEFINED__ */


#ifndef ___DWindowSightEvents_FWD_DEFINED__
#define ___DWindowSightEvents_FWD_DEFINED__
typedef interface _DWindowSightEvents _DWindowSightEvents;

#endif 	/* ___DWindowSightEvents_FWD_DEFINED__ */


#ifndef __WindowSight_FWD_DEFINED__
#define __WindowSight_FWD_DEFINED__

#ifdef __cplusplus
typedef class WindowSight WindowSight;
#else
typedef struct WindowSight WindowSight;
#endif /* __cplusplus */

#endif 	/* __WindowSight_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_WindowSight_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_WindowSight_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WindowSight_0000_0000_v0_0_s_ifspec;


#ifndef __WindowSightLib_LIBRARY_DEFINED__
#define __WindowSightLib_LIBRARY_DEFINED__

/* library WindowSightLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_WindowSightLib;

#ifndef ___DWindowSight_DISPINTERFACE_DEFINED__
#define ___DWindowSight_DISPINTERFACE_DEFINED__

/* dispinterface _DWindowSight */
/* [hidden][uuid] */ 


EXTERN_C const IID DIID__DWindowSight;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3401476e-db81-4d5e-9751-5073194dfa47")
    _DWindowSight : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DWindowSightVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DWindowSight * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DWindowSight * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DWindowSight * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DWindowSight * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DWindowSight * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DWindowSight * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DWindowSight * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DWindowSightVtbl;

    interface _DWindowSight
    {
        CONST_VTBL struct _DWindowSightVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DWindowSight_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DWindowSight_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DWindowSight_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DWindowSight_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DWindowSight_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DWindowSight_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DWindowSight_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DWindowSight_DISPINTERFACE_DEFINED__ */


#ifndef ___DWindowSightEvents_DISPINTERFACE_DEFINED__
#define ___DWindowSightEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DWindowSightEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DWindowSightEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("82f28959-1de5-41ce-aec9-32e239aae5a4")
    _DWindowSightEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DWindowSightEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DWindowSightEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DWindowSightEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DWindowSightEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DWindowSightEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DWindowSightEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DWindowSightEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DWindowSightEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DWindowSightEventsVtbl;

    interface _DWindowSightEvents
    {
        CONST_VTBL struct _DWindowSightEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DWindowSightEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DWindowSightEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DWindowSightEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DWindowSightEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DWindowSightEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DWindowSightEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DWindowSightEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DWindowSightEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_WindowSight;

#ifdef __cplusplus

class DECLSPEC_UUID("f2e384bf-7567-4362-ba1d-f1c96c43dcba")
WindowSight;
#endif
#endif /* __WindowSightLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


