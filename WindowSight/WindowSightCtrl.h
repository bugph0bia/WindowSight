#pragma once

// WindowSightCtrl.h : CWindowSightCtrl ActiveX コントロール クラスの宣言。


// CWindowSightCtrl : 実装については WindowSightCtrl.cpp を参照してください。

class CWindowSightCtrl : public COleControl
{
	DECLARE_DYNCREATE(CWindowSightCtrl)

	// 子ウィンドウ情報構造体
	typedef struct {
		// 現在のマウス座標
		POINT	pntCursor;
		// ウィンドウ矩形の面積
		ULONG	ulArea;
		// ウィンドウハンドル
		HWND	hWnd;
	} CHILD_INFO;

// コンストラクター
public:
	CWindowSightCtrl();

// オーバーライド
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual BOOL OnSetExtent(LPSIZEL lpSizeL);

// 実装
protected:
	~CWindowSightCtrl();

	DECLARE_OLECREATE_EX(CWindowSightCtrl)	// クラス ファクトリ と guid
	DECLARE_OLETYPELIB(CWindowSightCtrl)	// GetTypeInfo
	DECLARE_PROPPAGEIDS(CWindowSightCtrl)	// プロパティ ページ ID
	DECLARE_OLECTLTYPE(CWindowSightCtrl)	// タイプ名とその他のステータス

// メッセージ マップ
	DECLARE_MESSAGE_MAP()

// ディスパッチ マップ
	DECLARE_DISPATCH_MAP()

// イベント マップ
	DECLARE_EVENT_MAP()

// ディスパッチ と イベント ID
public:
	enum {
		dispidFoundWindow = 1L,
		dispidFlashFoundWindow = 2L,
		eventidDragStart = 1L,
		eventidDragEnd = 2L,
		eventidChangeTargetWindow = 3L,
	};

protected:
// ActiveX コントロールのプロパティ／メソッド
	// FoundWindowプロパティ：発見済みウィンドウを取得
	OLE_HANDLE GetFoundWindow();
	// FoundWindowプロパティ：発見済みウィンドウを設定
	void SetFoundWindow(OLE_HANDLE newVal);
	// FlashFoundWindowメソッド：発見済みウィンドウを点滅
	void FlashFoundWindow();

// ActiveX コントロールのイベント
	// DragStartイベント：ドラッグ開始を通知
	void FireDragStart(){ FireEvent(eventidDragStart, EVENT_PARAM(VTS_NONE)); }
	// DragEndイベント：ドラッグ終了を通知
	void FireDragEnd(OLE_HANDLE hWnd){ FireEvent(eventidDragEnd, EVENT_PARAM(VTS_HANDLE), hWnd); }
	// ChangeTargetWindowイベント：ドラッグ中の対象ウィンドウの変化を通知
	void FireChangeTargetWindow(OLE_HANDLE hWnd){ FireEvent(eventidChangeTargetWindow, EVENT_PARAM(VTS_HANDLE), hWnd); }

public:
	// イベントハンドラ：ウィンドウ生成
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	// イベントハンドラ：ウィンドウ破棄
	afx_msg void OnDestroy();
	// イベントハンドラ：マウス左ボタンダブルクリック
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	// イベントハンドラ：マウス左ボタンダウン
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	// イベントハンドラ：マウス左ボタンアップ
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	// イベントハンドラ：マウス移動
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	// イベントハンドラ：ウィンドウサイズ変更
	afx_msg void OnSize(UINT nType, int cx, int cy);

private:
	// 通常時ビットマップ（照準あり）
	CBitmap		m_bmpSightNormal;
	// ドラッグ中ビットマップ（照準なし）
	CBitmap		m_bmpSightDragging;
	// ドラッグ中カーソル
	HCURSOR		m_hCursorDragging;
	// 変更前カーソル
	HCURSOR		m_hCursorOld;
	// メモリデバイスコンテキスト
	CDC			m_memDC;
	// メモリデバイスコンテキストの変更前オブジェクト
	CBitmap*	m_pBmpOld;
	// ビットマップのサイズ
	CSize		m_sizeBmp;
	// （ドラッグ中）発見中のウィンドウ
	HWND		m_hWndFinding;
	// （ドロップ後）発見済みウィンドウ
	HWND		m_hWndFound;
	// ドラッグ状態
	BOOL		m_isDragging;

	// 初期処理
	void	Initialize();
	// 終了処理
	void	Terminate();
	// ドラッグ状態設定
	void	SetIsDragging(BOOL isDragging);
	// ウィンドウ矩形の反転表示
	void	InvertWindowBorder(HWND hWndTarget);
	// ::WindowFromPoint() 拡張版
	HWND	WindowFromPointEx(CPoint pntCursor);
	// デザインモード用描画処理
	void DrawDesignMode(CDC* pDC, const CRect& rectDesign);

	// 最適な子ウィンドウを検索するためのコールバック関数
	static BOOL CALLBACK FindOptimalChildProc(HWND hWnd, LPARAM lParam);
};

