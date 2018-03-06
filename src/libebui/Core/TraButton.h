#pragma once
#include <atlimage.h>

typedef enum TRA_BTNSTATE{//��ť״̬
	TRA_BTN_NOR,
	TRA_BTN_HOT,
	TRA_BTN_PRE,	// ���»�ѡ��
	TRA_BTN_DIS
};

typedef struct _TRATRAPNGINFO_
{
	int nWidth;
	int nHeight;
	CImage*  pImg;
}TRAPNGINFO;


class CTraButton : public CButton
{
	// ��׼���캯��
public:
	CTraButton();
	virtual ~CTraButton();

public:
	//���ã����뱳��ͼ
	void Load(UINT IDBkGroup, int width=-1, int height=0, const CString& resourceType = _T("PNG"));
	void Load(const CString& sFileName, int width=-1, int height=0, const CString& resourceType = _T("PNG"));
	//���ã�����Ӧ����ͼ
	void SetAutoSize(bool bAutoSize);

	void MovePoint(int x, int y, int nWidth=0, int nHeight=0);
	void SetChecked(bool b);
	bool GetChecked() const;

	int GetImgWidth(void) const {return m_btninfoNor.pImg==NULL?0:m_btninfoNor.pImg->GetWidth();}
	int GetImgHeight(void) const {return m_btninfoNor.pImg==NULL?0:m_btninfoNor.pImg->GetHeight();}
	void SetToolTipText(LPCTSTR s);
	void SetToolTipColor(COLORREF crText, COLORREF crBkgnd);
	void SetAutoFocus(bool v) {m_bAutoFocus = v;}
	void SetTextLeft(int v) {m_nTextLeft = v;}
	void SetTextTop(int v) {m_nTextTop = v;}

	void SetNorTextColor(COLORREF v) {m_crNorText = v;}
	void SetHotTextColor(COLORREF v) {m_crHotText = v;}
	void SetDrawPanel(bool bDrawPanel, COLORREF crNor, COLORREF crHot=-1, COLORREF crPre=-1, COLORREF crDis=-1);	// default -1=crNor
	void SetDrawPanelRgn(bool bCreateRgn = true) {m_bCreateRgn = bCreateRgn;}	// default true
	void SetDrawClosePic(bool bDrawClose, COLORREF crNor, COLORREF crHot, COLORREF crPre=-1, COLORREF crDis=-1, int nWidth=2);
	void SetDrawNewPic(bool bDrawNew, COLORREF crNor, COLORREF crHot, COLORREF crPre=-1, COLORREF crDis=-1, int nWidth=2, int nHeight=8);
	// nTriangleType: 0=disable, 1=up; 2=down; 3=left; 4=right
	void SetDrawTrianglePic(int nTriangleType, COLORREF crNor, COLORREF crHot, COLORREF crPre=-1, COLORREF crDis=-1, int nWidth=8,int nHeight=8);
	void SetDrawArrowPic(int nArrowType, bool bDrawLine, int nPenWidth, COLORREF crNor, COLORREF crHot, COLORREF crPre=-1, COLORREF crDis=-1, int nWidth=5);
	void SetDrawImage(bool bDestroyDelete, bool bGrayImage, Gdiplus::Image * pImage, const Gdiplus::Rect& rect);
	void SetDrawImage(bool bGrayImage);

	void SetTextHotMove(bool bTextHotMove) {m_bTextHotMove = bTextHotMove;}
	bool GetTextHotMove(void) const {return m_bTextHotMove;}

	//void SetWndFocus(CWnd* v) {m_pWndFocus = v;}
	//CWnd*m_pWndFocus;

protected:
	void Load(CImage& orgImg, int width=-1, int height=0, const CString& resourceType = _T("PNG"));
	//�ػ�
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
	//{{AFX_MSG(CTraButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	void RelayEvent(UINT message, WPARAM wParam, LPARAM lParam);

private:
	TRAPNGINFO		m_btninfoNor;				//Normalʱ��ͼƬ
	TRAPNGINFO		m_btninfoHot;				//Hotʱ��ͼƬ
	TRAPNGINFO		m_btninfoPre;				//Pressʱ��ͼƬ
	TRAPNGINFO		m_btninfoDis;				//Disableʱ��ͼƬ
	bool			m_bHot;						//�Ƿ�ΪHot
	bool			m_bPress;					//�Ƿ���
	bool			m_bSelected;				// �Ƿ�ѡ�� add by hd 

	bool			m_bAutoSize;				//�Զ���Ӧ
	bool			m_bAutoFocus;
	int				m_nTextLeft;
	int				m_nTextTop;
	CToolTipCtrl m_tooltip;
	COLORREF		m_crNorText;
	COLORREF		m_crHotText;
	bool			m_bDrawPanel;
	COLORREF		m_crNorPanel;
	COLORREF		m_crHotPanel;
	COLORREF		m_crPrePanel;
	COLORREF		m_crDisPanel;
	bool			m_bCreateRgn;
	bool			m_bDrawClosePic;
	COLORREF		m_crClosePicNor;
	COLORREF		m_crClosePicHot;
	COLORREF		m_crClosePicPre;
	COLORREF		m_crClosePicDis;
	int				m_nClosePicWidth;
	bool			m_bDrawNewPic;
	COLORREF		m_crNewPicNor;
	COLORREF		m_crNewPicHot;
	COLORREF		m_crNewPicPre;
	COLORREF		m_crNewPicDis;
	int				m_nNewPicWidth;
	int				m_nNewPicHeight;
	int				m_nDrawTriangleType;
	COLORREF		m_crTrianglePicNor;
	COLORREF		m_crTrianglePicHot;
	COLORREF		m_crTrianglePicPre;
	COLORREF		m_crTrianglePicDis;
	int				m_nTrianglePicWidth;
	int				m_nTrianglePicHeight;
	int				m_nDrawArrowType;
	int				m_nArrowPenWidth;
	bool			m_bDrawArrowLine;
	COLORREF		m_crArrowPicNor;
	COLORREF		m_crArrowPicHot;
	COLORREF		m_crArrowPicPre;
	COLORREF		m_crArrowPicDis;
	int				m_nArrowPicWidth;

	bool			m_bDestroyDelete;
	bool			m_bGrayImage;
	Gdiplus::Image* m_pImage;
	Gdiplus::Rect	m_rcImage;


	bool			m_bTextHotMove;				// ����ƶ�ʱ�����ֻ������ƶ���
	//CWnd*			m_pWndFocus;
private:
	//��ͼ
	void DrawBK(HDC dc, CImage* img,TRA_BTNSTATE btnstate);
	//д��
	void DrawBtnText(HDC dc, const CString& strText, int nMoveX, int nMoveY, TRA_BTNSTATE btnstate);
	//�ı䰴ť���
	virtual void PreSubclassWindow();
	LRESULT OnMsgReInvalidate(WPARAM wParam, LPARAM lParam);
};