#pragma once

// WindowSightPropPage.h : CWindowSightPropPage プロパティ ページ クラスの宣言。


// CWindowSightPropPage : 実装については WindowSightPropPage.cpp を参照してください。

class CWindowSightPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CWindowSightPropPage)
	DECLARE_OLECREATE_EX(CWindowSightPropPage)

// コンストラクター
public:
	CWindowSightPropPage();

// ダイアログ データ
	enum { IDD = IDD_PROPPAGE_WINDOWSIGHT };

// 実装
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// メッセージ マップ
protected:
	DECLARE_MESSAGE_MAP()
};

