
// TestDlg.h : ヘッダー ファイル
//

#pragma once

#include "CChildDlg.h"


// CTestDlg ダイアログ
class CTestDlg : public CDialogEx
{
// コンストラクション
public:
	CTestDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	// 子ダイアログ
	CChildDlg	m_dlgChild;

public:
	CEdit m_EdHwnd;
//	COCX m_ocxWindowSight;

	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtFlash();
};
