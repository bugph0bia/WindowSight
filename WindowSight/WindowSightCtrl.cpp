// WindowSightCtrl.cpp : CWindowSightCtrl ActiveX コントロール クラスの実装。

#include "pch.h"
#include "framework.h"
#include "WindowSight.h"
#include "WindowSightCtrl.h"
#include "WindowSightPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CWindowSightCtrl, COleControl)

// メッセージ マップ

BEGIN_MESSAGE_MAP(CWindowSightCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// ディスパッチ マップ

BEGIN_DISPATCH_MAP(CWindowSightCtrl, COleControl)
	//DISP_PROPERTY_EX_ID(CWindowSightCtrl, "FoundWindow", dispidFoundWindow, GetFoundWindow, SetFoundWindow, VT_HANDLE)
	//DISP_FUNCTION_ID(CWindowSightCtrl, "FlashFoundWindow", dispidFlashFoundWindow, FlashFoundWindow, VT_EMPTY, VTS_NONE)
	DISP_PROPERTY_EX(CWindowSightCtrl, "FoundWindow", GetFoundWindow, SetFoundWindow, VT_HANDLE)
	DISP_FUNCTION(CWindowSightCtrl, "FlashFoundWindow", FlashFoundWindow, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// イベント マップ

BEGIN_EVENT_MAP(CWindowSightCtrl, COleControl)
	EVENT_CUSTOM("DragStart", FireDragStart, VTS_NONE)
	EVENT_CUSTOM("DragEnd", FireDragEnd, VTS_HANDLE)
	EVENT_CUSTOM("ChangeTargetWindow", FireChangeTargetWindow, VTS_HANDLE)
END_EVENT_MAP()

// プロパティ ページ

// TODO: プロパティ ページを追加して、BEGIN 行の最後にあるカウントを増やしてください。
BEGIN_PROPPAGEIDS(CWindowSightCtrl, 1)
	PROPPAGEID(CWindowSightPropPage::guid)
END_PROPPAGEIDS(CWindowSightCtrl)

// クラス ファクトリおよび GUID を初期化します。

IMPLEMENT_OLECREATE_EX(CWindowSightCtrl, "MFCACTIVEXCONTRO.WindowSightCtrl.1",
	0xf2e384bf,0x7567,0x4362,0xba,0x1d,0xf1,0xc9,0x6c,0x43,0xdc,0xba)

// タイプ ライブラリ ID およびバージョン

IMPLEMENT_OLETYPELIB(CWindowSightCtrl, _tlid, _wVerMajor, _wVerMinor)

// インターフェイス ID

const IID IID_DWindowSight = {0x3401476e,0xdb81,0x4d5e,{0x97,0x51,0x50,0x73,0x19,0x4d,0xfa,0x47}};
const IID IID_DWindowSightEvents = {0x82f28959,0x1de5,0x41ce,{0xae,0xc9,0x32,0xe2,0x39,0xaa,0xe5,0xa4}};

// コントロールの種類の情報

static const DWORD _dwWindowSightOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CWindowSightCtrl, IDS_WINDOWSIGHT, _dwWindowSightOleMisc)

// CWindowSightCtrl::CWindowSightCtrlFactory::UpdateRegistry -
// CWindowSightCtrl のシステム レジストリ エントリを追加または削除します

BOOL CWindowSightCtrl::CWindowSightCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: コントロールが apartment モデルのスレッド処理の規則に従っていることを
	// 確認してください。詳細については MFC のテクニカル ノート 64 を参照してください。
	// アパートメント モデルのスレッド処理の規則に従わないコントロールの場合は、6 番目
	// のパラメーターを以下のように変更してください。
	// afxRegApartmentThreading を 0 に設定します。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_WINDOWSIGHT,
			IDB_WINDOWSIGHT,
			afxRegApartmentThreading,
			_dwWindowSightOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CWindowSightCtrl::CWindowSightCtrl - コンストラクター

CWindowSightCtrl::CWindowSightCtrl() :
	m_hCursorDragging(nullptr),
	m_hCursorOld(nullptr),
	m_pBmpOld(nullptr),
	m_hWndFinding(nullptr),
	m_hWndFound(nullptr),
	m_isDragging(FALSE)
{
	InitializeIIDs(&IID_DWindowSight, &IID_DWindowSightEvents);
	// TODO: この位置にコントロールのインスタンス データの初期化処理を追加してください
}

// CWindowSightCtrl::~CWindowSightCtrl - デストラクタ―

CWindowSightCtrl::~CWindowSightCtrl()
{
	// TODO: この位置にコントロールのインスタンス データの後処理用のコードを追加してください
}

// CWindowSightCtrl::OnDraw - 描画関数

void CWindowSightCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: 以下のコードを描画用のコードに置き換えてください
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);

	// 実行時
	if (AmbientUserMode()) {
		// メモリデバイスコンテキストからビットマップを転送
		pdc->BitBlt(0, 0, m_sizeBmp.cx, m_sizeBmp.cy, &m_memDC, 0, 0, SRCCOPY);

		// 自身を反転表示中の場合は、ビットマップ描画後に改めて反転表示する
		if (m_hWndFinding == m_hWnd) {
			InvertWindowBorder(m_hWnd);
		}
	}
	// デザインモード時
	else {
		// デザインモード用描画
		DrawDesignMode(pdc, rcBounds);
	}
}

// CWindowSightCtrl::DoPropExchange - 永続性のサポート

void CWindowSightCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 永続属性を持つ各カスタム プロパティ用の PX_ 関数を呼び出します。
}


// CWindowSightCtrl::OnResetState - コントロールを既定の状態にリセットします

void CWindowSightCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange を呼び出して既定値にリセット

	// TODO: この位置にコントロールの状態をリセットする処理を追加してください
}


BOOL CWindowSightCtrl::OnSetExtent(LPSIZEL lpSizeL)
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	// 通常時のビットマップをロード
	// ※デザインモード時に呼び出されるため、AfxGetApp()やCBitmap::LoadBitmap()は使用できない
	HBITMAP hBmpSight = ::LoadBitmap(theApp.m_hInstance, MAKEINTRESOURCE(IDB_SIGHT_NORMAL));

	if (hBmpSight) {
		// ビットマップ情報
		BITMAP info;
		::GetObject(hBmpSight, sizeof(BITMAP), &info);

		// デスクトップウィンドウのDCを取得して DPtoHIMETRIC() を使用する
		CWnd* pWnd = CWnd::FromHandle(::GetDesktopWindow());
		CClientDC dc(pWnd);

		// ビットマップのサイズをPixcel単位からHIMETRIC単位に変換
		CSize sizeNew(info.bmWidth, info.bmHeight);
		dc.DPtoHIMETRIC(&sizeNew);

		// コントロールのサイズをビットマップのサイズ固定とする
		lpSizeL->cx = sizeNew.cx;
		lpSizeL->cy = sizeNew.cy;

		// ビットマップ削除
		::DeleteObject(hBmpSight);
	}

	// デザインモード時のサイズ変更を抑制
	//return false;

	return COleControl::OnSetExtent(lpSizeL);
}


// CWindowSightCtrl メッセージ ハンドラー


// FoundWindowプロパティ：発見済みウィンドウを取得
OLE_HANDLE CWindowSightCtrl::GetFoundWindow()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: ここにディスパッチ ハンドラー コードを追加します

	return (OLE_HANDLE)HandleToULong(m_hWndFound);
}


// FoundWindowプロパティ：発見済みウィンドウを設定
void CWindowSightCtrl::SetFoundWindow(OLE_HANDLE newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: ここにプロパティ ハンドラー コードを追加します

	m_hWndFound = (HWND)ULongToHandle(newVal);

	SetModifiedFlag();
}


// FlashFoundWindowメソッド：発見済みウィンドウを点滅
void CWindowSightCtrl::FlashFoundWindow()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: ここにディスパッチ ハンドラー コードを追加します

	// 点滅回数
	static const int FLASH_COUNT = 3;
	// 点滅間隔(ms)
	static const int FLASH_INTERVAL_MS = 100;

	// 有効なウィンドウが見つかっている場合
	if (::IsWindow(m_hWndFound)) {
		// (指定回数 * 2)回だけ表示色の反転を繰り返すことで、点滅表示を行う
		for (int i = 0; i < FLASH_COUNT * 2; i++) {
			InvertWindowBorder(m_hWndFound);
			::Sleep(FLASH_INTERVAL_MS);
		}
	}
}


// イベントハンドラ：ウィンドウ生成
int CWindowSightCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: ここに特定な作成コードを追加してください。

	// 初期処理
	Initialize();

	return 0;
}


// イベントハンドラ：ウィンドウ破棄
void CWindowSightCtrl::OnDestroy()
{
	COleControl::OnDestroy();

	// TODO: ここにメッセージ ハンドラー コードを追加します。

	// 終了処理
	Terminate();
}


// イベントハンドラ：マウス左ボタンダブルクリック
void CWindowSightCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	// DragStartイベント発生
	FireDragStart();

	// ドラッグ開始
	SetIsDragging(TRUE);

	COleControl::OnLButtonDblClk(nFlags, point);
}


// イベントハンドラ：マウス左ボタンダウン
void CWindowSightCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	// DragStartイベント発生
	FireDragStart();

	// ドラッグ開始
	SetIsDragging(TRUE);

	COleControl::OnLButtonDown(nFlags, point);
}


// イベントハンドラ：マウス左ボタンアップ
void CWindowSightCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	// ドラッグ中
	if (m_isDragging) {

		// DragEndイベント発生
		// 最後に反転表示していたウィンドウを通知
		FireDragEnd((OLE_HANDLE)HandleToULong(m_hWndFinding));

		// ドラッグ終了
		SetIsDragging(FALSE);
	}

	COleControl::OnLButtonUp(nFlags, point);
}


// イベントハンドラ：マウス移動
void CWindowSightCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	// ドラッグ中
	if (m_isDragging) {
		// マウス位置をスクリーン座標系に変換
		CPoint pntCursor = point;
		ClientToScreen((LPPOINT)&pntCursor);

		// マウス直下のウィンドウを取得
		HWND hWndCursor = WindowFromPointEx(pntCursor);

		// 直前に反転表示していたウィンドウがから変化した場合
		if (hWndCursor && m_hWndFinding != hWndCursor) {
			// 以前に反転表示していたウィンドウを元に戻す
			InvertWindowBorder(m_hWndFinding);

			// 新しいウィンドウを反転表示
			InvertWindowBorder(hWndCursor);
			m_hWndFinding = hWndCursor;

			// ChangeTargetWindowイベント発生
			FireChangeTargetWindow((OLE_HANDLE)HandleToULong(m_hWndFinding));
		}
	}

	COleControl::OnMouseMove(nFlags, point);
}


// イベントハンドラ：ウィンドウサイズ変更
void CWindowSightCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	// TODO: ここにメッセージ ハンドラー コードを追加します。

	// OnSetExtent()で調整するように変更したため以下は削除

	// コントロールのサイズをビットマップに合わせる
	//SetControlSize(m_sizeBmp.cx, m_sizeBmp.cy);
}


/// @brief	初期処理
void CWindowSightCtrl::Initialize()
{
	// ビットマップのロード
	m_bmpSightNormal.LoadBitmap(IDB_SIGHT_NORMAL);
	m_bmpSightDragging.LoadBitmap(IDB_SIGHT_DRAGGING);
	// カーソルのロード
	m_hCursorDragging = AfxGetApp()->LoadCursor(IDC_SIGHT);

	// コントロールのデバイスコンテキストを取得
	CDC* pDC = GetDC();
	// メモリデバイスコンテキストの作成
	m_memDC.CreateCompatibleDC(pDC);
	// デバイスコンテキスト解放
	ReleaseDC(pDC);

	// 最初は通常時ビットマップを表示
	m_pBmpOld = m_memDC.SelectObject(&m_bmpSightNormal);

	// ビットマップのサイズを保存しておく
	// ※CBitmapオブジェクトから一度の操作でサイズを取得できないため
	BITMAP	info;	// ビットマップ情報
	m_bmpSightNormal.GetBitmap(&info);
	m_sizeBmp.cx = info.bmWidth;
	m_sizeBmp.cy = info.bmHeight;
}


/// @brief	終了処理
void CWindowSightCtrl::Terminate()
{
	// メモリデバイスコンテキストを削除
	m_memDC.SelectObject(m_pBmpOld);
	m_memDC.DeleteDC();
	// カーソル削除
	DestroyCursor(m_hCursorDragging);
	// ビットマップを削除
	m_bmpSightNormal.DeleteObject();
	m_bmpSightDragging.DeleteObject();
}


/// @brief	ドラッグ状態設定
/// @param[in]	isDragging	ドラッグ状態
void CWindowSightCtrl::SetIsDragging(BOOL isDragging)
{
	// ドラッグ中フラグ
	m_isDragging = isDragging;

	// ドラッグ開始
	if (m_isDragging) {
		// ドラッグ中ビットマップを表示
		m_memDC.SelectObject(&m_bmpSightDragging);

		// 再描画
		InvalidateRect(nullptr, FALSE);		// 領域を無効化
		UpdateWindow();						// 領域を無効化して呼ぶことで、WM_PAINTを送信する

		// ドラッグ開始した瞬間は自身を反転表示
		InvertWindowBorder(m_hWnd);
		m_hWndFinding = m_hWnd;
		m_hWndFound = nullptr;

		// マウスキャプチャ開始
		SetCapture();

		// ドラッグ中カーソルに変更
		m_hCursorOld = SetCursor(m_hCursorDragging);

	}
	// ドラッグ終了
	else {
		// 通常時ビットマップを表示
		m_memDC.SelectObject(&m_bmpSightNormal);

		// 再描画
		InvalidateRect(nullptr, FALSE);		// 領域を無効化
		UpdateWindow();						// 領域を無効化して呼ぶことで、WM_PAINTを送信する

		// 最後に反転表示していたウィンドウを元に戻す
		InvertWindowBorder(m_hWndFinding);

		// 発見したウィンドウを保存
		m_hWndFound = m_hWndFinding;
		m_hWndFinding = nullptr;

		// マウスキャプチャ終了
		ReleaseCapture();

		// カーソルを元に戻す
		SetCursor(m_hCursorOld);
	}
}


/// @brief ウィンドウ矩形の反転表示
/// @param[in]	hWndTarget	対象ウィンドウ
void CWindowSightCtrl::InvertWindowBorder(HWND hWndTarget)
{
	// 反転表示する幅のデフォルト値
	static const int INVERT_WIDTH = 3;

	if (!hWndTarget) return;

	// CWndオブジェクトを取得
	CWnd* pWndTarget = CWnd::FromHandle(hWndTarget);

	// ウィンドウ矩形取得 (スクリーン座標)
	CRect rectTarget;
	pWndTarget->GetWindowRect(&rectTarget);
	// クライアント座標に変換
	// ※pWndTarget->ScreenToClient() を使用するとタイトルバーを持つウィンドウでズレが発生する
	rectTarget.OffsetRect(-rectTarget.left, -rectTarget.top);

	// 反転表示する幅
	int nInvertWidth = INVERT_WIDTH;
	// ウィンドウの高さか幅が狭くて潰れてしまう場合は枠線の幅を小さくする
	if (rectTarget.bottom - nInvertWidth * 2 < 0) {
		nInvertWidth = 1;
	}
	if (rectTarget.right - nInvertWidth * 2 < 0) {
		nInvertWidth = 1;
	}

	// 対象ウィンドウのDCを取得
	CDC* pDcTarget = pWndTarget->GetWindowDC();
	if (!pDcTarget) return;

	// ウィンドウ矩形の一辺（反転表示する最小単位）
	CRect rectSide;

	// 上辺を反転表示
	rectSide.SetRect(0, 0, rectTarget.right, nInvertWidth);
	pDcTarget->InvertRect(&rectSide);

	// 左辺を反転表示
	rectSide.SetRect(0, nInvertWidth, nInvertWidth, rectTarget.bottom);
	pDcTarget->InvertRect(&rectSide);

	// 下辺を反転表示
	rectSide.SetRect(nInvertWidth, rectTarget.bottom - nInvertWidth, rectTarget.right, rectTarget.bottom);
	pDcTarget->InvertRect(&rectSide);

	// 右辺を反転表示
	rectSide.SetRect(rectTarget.right - nInvertWidth, nInvertWidth, rectTarget.right, rectTarget.bottom - nInvertWidth);
	pDcTarget->InvertRect(&rectSide);

	// DCを解放
	pWndTarget->ReleaseDC(pDcTarget);
}


/// @brief マウスカーソル位置のウィンドウを取得
/// @param[in]	pntCursor	マウスカーソル位置
/// @return	HWND	マウスカーソル直下のウィンドウ
/// @details	Win32APIのWindowFromPointの拡張版
HWND CWindowSightCtrl::WindowFromPointEx(CPoint pntCursor)
{
	// 子ウィンドウ情報を初期化
	CHILD_INFO childInfo;
	childInfo.pntCursor = pntCursor;
	childInfo.ulArea = 0xFFFFFFFF;
	childInfo.hWnd = nullptr;

	// マウス直下のウィンドウを取得
	HWND hWnd = ::WindowFromPoint(pntCursor);

	// 親ウィンドウを取得
	HWND hWndParent = ::GetParent(hWnd);
	// ウィンドウスタイルを取得
	DWORD dwStyle = ::GetWindowLong(hWnd, GWL_STYLE);

	// 親ウィンドウが存在する非ポップアップスタイルのウィンドウなら、親ウィンドウを採用
	if (hWndParent && !(dwStyle & WS_POPUP)) {
		hWnd = hWndParent;
	}

	// 子ウィンドウから最適なウィンドウを探す
	::EnumChildWindows(hWnd, FindOptimalChildProc, (LPARAM)&childInfo);
	if (childInfo.hWnd) {
		// 見つかった子ウィンドウを採用
		hWnd = childInfo.hWnd;
	}

	return hWnd;
}


/// @brief	デザインモード用描画
/// @param[in]	pDC			描画対象DC
/// @param[in]	rectDesign	描画対象領域
void CWindowSightCtrl::DrawDesignMode(CDC* pDC, const CRect& rectDesign)
{
	// 通常時のビットマップをロード
	CBitmap bmpSight;
	bmpSight.LoadBitmap(IDB_SIGHT_NORMAL);

	// ビットマップ情報
	BITMAP bmpInfo;
	bmpSight.GetBitmap(&bmpInfo);

	// メモリデバイスコンテキストを作成
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	// ビットマップをDCに関連付ける
	CBitmap* pOldBmp = memDC.SelectObject(&bmpSight);

	// ビットマップを転送
	pDC->BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &memDC, 0, 0, SRCCOPY);

	// メモリデバイスコンテキストを削除
	memDC.SelectObject(pOldBmp);
	memDC.DeleteDC();

	// ビットマップを削除
	bmpSight.DeleteObject();
}


/// @brief	最適な子ウィンドウを検索するためのコールバック関数
/// @param[in]	hWnd	列挙された子ウィンドウ
/// @param[in]	lParam	パラメータ
/// @return	BOOL	TRUE:列挙を継続 FALSE:列挙を中断
/// @details	EnumChildWindowsで使用する
BOOL CWindowSightCtrl::FindOptimalChildProc(HWND hWnd, LPARAM lParam)
{
	// 子ウィンドウ情報
	CHILD_INFO* pChild = (CHILD_INFO*)lParam;

	// 子ウィンドウの矩形を取得
	RECT rect;
	::GetWindowRect(hWnd, &rect);

	// マウス座標が子ウィンドウの領域内
	if (::PtInRect(&rect, pChild->pntCursor)) {
		// 子ウィンドウの面積を計算
		ULONG ulArea = labs((rect.right - rect.left) * (rect.bottom - rect.top));

		// より面積の小さいウィンドウを採用する
		// ※別のウィンドウの後ろに隠れていても取得できるように
		// 　小さいウィンドウ複数で覆われたウィンドウは取得できないことになるが、
		// 　実用上問題なしとする
		if (ulArea < pChild->ulArea && ::IsWindowVisible(hWnd)) {
			// 子ウィンドウを保存
			pChild->ulArea = ulArea;
			pChild->hWnd = hWnd;
		}
	}

	return TRUE;
}
