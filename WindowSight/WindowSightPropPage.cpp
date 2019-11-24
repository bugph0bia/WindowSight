// WindowSightPropPage.cpp : CWindowSightPropPage プロパティ ページ クラスの実装。

#include "pch.h"
#include "framework.h"
#include "WindowSight.h"
#include "WindowSightPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CWindowSightPropPage, COlePropertyPage)

// メッセージ マップ

BEGIN_MESSAGE_MAP(CWindowSightPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// クラス ファクトリおよび GUID を初期化します。

IMPLEMENT_OLECREATE_EX(CWindowSightPropPage, "MFCACTIVEXCONT.WindowSightPropPage.1",
	0x554b23b9,0x6c4e,0x4f31,0x9e,0x77,0x4b,0x03,0x1b,0x83,0x44,0x79)

// CWindowSightPropPage::CWindowSightPropPageFactory::UpdateRegistry -
// CWindowSightPropPage のシステム レジストリ エントリを追加または削除します

BOOL CWindowSightPropPage::CWindowSightPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_WINDOWSIGHT_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CWindowSightPropPage::CWindowSightPropPage - コンストラクター

CWindowSightPropPage::CWindowSightPropPage() :
	COlePropertyPage(IDD, IDS_WINDOWSIGHT_PPG_CAPTION)
{
}

// CWindowSightPropPage::DoDataExchange - ページおよびプロパティ間でデータを移動します

void CWindowSightPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CWindowSightPropPage メッセージ ハンドラー
