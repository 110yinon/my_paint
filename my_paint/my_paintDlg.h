
// my_paintDlg.h : header file
//

#pragma once


// CmypaintDlg dialog
class CmypaintDlg : public CDialogEx
{
// Construction
public:
	CmypaintDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_PAINT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

//~~~~~~~~~~~~~~  my definition ~~~~~~~~~~~~~~~~~
private:
	CPoint firstPoint, endPoint, endPointPolygon, firstPointPolygon;
	int flagButton;//code of button types
	INT maxY; //max y cordinate for spray on pixel
	INT minY; //max x cordinate for spray on pixel
	bool isFirstLine = true;// if you going to draw the first line in the polygon
	bool isPolygonFinish = true;// if there is no polygon under build right now
	bool cameFromOnMouseMove = true;//flag that needs in the OnLButtonUp
	COLORREF fillColor = RGB(0, 0, 0);//Black by default
	COLORREF OutLineColor = RGB(0, 0, 0);//Black by default
	INT thickness = 4;//Line thickness
	CPoint *polyPoints=(CPoint*)malloc(0);//array of points for polygon
	INT polyPointsCount = 0;//count of the polyPoints array

public:
	afx_msg void OnBnClickedPoint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedLine();
	afx_msg void OnBnClickedPencil();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRect();
	afx_msg void OnBnClickedElipse();
	afx_msg void OnBnClickedEraser();
	afx_msg void OnBnClickedSpray();
	void polinomial(FLOAT a, FLOAT b, FLOAT c);
	void CmypaintDlg::spray(CPoint point);
	afx_msg void OnBnClickedPolygon();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	void CmypaintDlg::finishPolygon(CPoint point);
	//if user turn to other button in the middle of polygon build
	void CmypaintDlg::finishPolygonAfterBtnChange();
	afx_msg void OnBnClickedColor();
	afx_msg void OnBnClickedOutlinecolor();
	afx_msg void OnBnClickedincthick();
	afx_msg void OnBnClickeddecthick();
};
