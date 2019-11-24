// WindowSight.cpp : CWindowSightApp および DLL 登録の実装。

#include "pch.h"
#include "framework.h"
#include "WindowSight.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CWindowSightApp theApp;

const GUID CDECL _tlid = {0x250e639c,0xd31d,0x4a2f,{0xb6,0x10,0x52,0x9c,0x1f,0x7c,0xb6,0x54}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CWindowSightApp::InitInstance - DLL 初期化

BOOL CWindowSightApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: この位置にモジュールの初期化処理コードを追加してください。
	}

	return bInit;
}



// CWindowSightApp::ExitInstance - DLL 終了

int CWindowSightApp::ExitInstance()
{
	// TODO: この位置にモジュールの終了処理を追加してください。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - エントリをシステム レジストリに追加します。

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - エントリをレジストリから削除します。

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
