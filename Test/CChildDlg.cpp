// CChildDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "Test.h"
#include "CChildDlg.h"
#include "afxdialogex.h"


// CChildDlg ダイアログ

IMPLEMENT_DYNAMIC(CChildDlg, CDialogEx)

CChildDlg::CChildDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHILD_DLG, pParent)
{

}

CChildDlg::~CChildDlg()
{
}

void CChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChildDlg, CDialogEx)
END_MESSAGE_MAP()


// CChildDlg メッセージ ハンドラー
