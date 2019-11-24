#pragma once

// WindowSight.h : WindowSight.DLL のメイン ヘッダー ファイル

#if !defined( __AFXCTL_H__ )
#error "このファイルをインクルードする前に 'afxctl.h' をインクルードしてください。"
#endif

#include "resource.h"       // メイン シンボル


// CWindowSightApp : 実装については WindowSight.cpp を参照してください。

class CWindowSightApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

extern CWindowSightApp theApp;
