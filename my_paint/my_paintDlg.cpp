
// my_paintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "my_paint.h"
#include "my_paintDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmypaintDlg dialog



CmypaintDlg::CmypaintDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_PAINT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmypaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmypaintDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Point, &CmypaintDlg::OnBnClickedPoint)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_Line, &CmypaintDlg::OnBnClickedLine)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_Pencil, &CmypaintDlg::OnBnClickedPencil)
	ON_BN_CLICKED(IDC_Rect, &CmypaintDlg::OnBnClickedRect)
	ON_BN_CLICKED(ID_Elipse, &CmypaintDlg::OnBnClickedElipse)
	ON_BN_CLICKED(IDC_Eraser, &CmypaintDlg::OnBnClickedEraser)
	ON_BN_CLICKED(IDC_Spray, &CmypaintDlg::OnBnClickedSpray)
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_Polygon, &CmypaintDlg::OnBnClickedPolygon)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_Color, &CmypaintDlg::OnBnClickedColor)
	ON_BN_CLICKED(IDC_OutLineColor, &CmypaintDlg::OnBnClickedOutlinecolor)
	ON_BN_CLICKED(IDC_incThick, &CmypaintDlg::OnBnClickedincthick)
	ON_BN_CLICKED(IDC_decThick, &CmypaintDlg::OnBnClickeddecthick)
END_MESSAGE_MAP()


// CmypaintDlg message handlers

BOOL CmypaintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
		CButton button();
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CmypaintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CmypaintDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		//colorBar
		/*
		CClientDC painter(this);
		CRect rect(100, 100, 300, 300);
		painter.Rectangle(rect);
		CMFCColorBar colorBar;
		colorBar.CreateControl(this,rect,0,4);
		*/
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CmypaintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmypaintDlg::OnBnClickedPoint()
{
	// TODO: Add your control notification handler code here
	flagButton = 1;//my code for Point button
	finishPolygonAfterBtnChange();//close the polygon if user click on this button
}
void CmypaintDlg::OnBnClickedLine()
{
	// TODO: Add your control notification handler code here
	flagButton = 2;//my code for Line button
	finishPolygonAfterBtnChange();//close the polygon if user click on this button
}
void CmypaintDlg::OnBnClickedPencil()
{
	// TODO: Add your control notification handler code here
	flagButton = 3;//my code for Pencil button
	finishPolygonAfterBtnChange();//close the polygon if user click on this button
}
void CmypaintDlg::OnBnClickedRect()
{
	// TODO: Add your control notification handler code here
	flagButton = 4;//my code for Rect button
	finishPolygonAfterBtnChange();//close the polygon if user click on this button
}
void CmypaintDlg::OnBnClickedElipse()
{
	// TODO: Add your control notification handler code here
	flagButton = 5;//my code for Elipse button
	finishPolygonAfterBtnChange();//close the polygon if user click on this button
}
void CmypaintDlg::OnBnClickedEraser()
{
	// TODO: Add your control notification handler code here
	flagButton = 6;//my code for Eraser button
	finishPolygonAfterBtnChange();//close the polygon if user click on this button
}
void CmypaintDlg::OnBnClickedSpray()
{
	// TODO: Add your control notification handler code here
	flagButton = 7;//my code for Spray button
	finishPolygonAfterBtnChange();//close the polygon if user click on this button
}
void CmypaintDlg::OnBnClickedPolygon()
{
	// TODO: Add your control notification handler code here
	flagButton = 8;//my code for Poligon button
	//set the flags on after return from other buttons
	isPolygonFinish = true;
	bool isPolygonFinish = true;
	finishPolygonAfterBtnChange();//close the polygon if user click on this button
}

void CmypaintDlg::polinomial(FLOAT a, FLOAT b, FLOAT c)//support method for my spray module
{
	//Polinomail Equation returns 2 results
	//On our needs  - return the max/min Y-Cordinate in relation to x
	maxY = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2.0*a);
	minY = (-b - sqrt(pow(b, 2) - 4 * a*c)) / (2.0*a);
}

void CmypaintDlg::spray(CPoint point) {

	INT x = 0;// = (-30) + (rand() % (30 - (-30) + 1));
	INT y = 0;// = (-30) + (rand() % (30 - (-30) + 1));
	CClientDC painter(this);
	CPoint sprayPoint = point;//sprayPoint = our point to make calculations
	painter.SetPixel(sprayPoint, fillColor);//draw the original users's clicked pixel
	//option 1 - square spray dispersion 
			/*
			for (INT i = 0; i < 30; i++)//set 30 new random sprayPoint to pain
			{
				x = (-30) + (rand() % (30 - (-30) + 1));
				y = (-30) + (rand() % (30 - (-30) + 1));
				sprayPoint.Offset(x, y);
				painter.SetPixel(sprayPoint, RGB(0, 0, 255));
				sprayPoint = point;
			}
			*/
	//option 2 - circle spray dispersion
	for (INT i = 0; i < 30; i++)//set 30 new random sprayPoint to pain
	{
		//set randomal x cordinate to paint in max 30 pixel radius from the clicked point
		x = (sprayPoint.x - 30) + (rand() % ((sprayPoint.x + 30) - (sprayPoint.x - 30) + 1));
		//set the calculate y cordinate for the randomal x above
		//using the Equation of a circle and Polinomail Equation for the calc
		// (x-a)^2+(y-b)^2=R^2, (a,b)=center of circle cordinate
		//e.g: (3,4) center of circle,R=30;
		//if we want to calc y cordinate for x cordinate in/on the circle: ==> x=10
		//(10-3)^2+(y-4)^2=30^2 =========> y^2-8y-835=0; a=1,b=-8,c=-835;
		FLOAT b = -2 * sprayPoint.y;
		FLOAT c = -pow(30, 2) + pow((sprayPoint.y), 2) + pow((x - sprayPoint.x), 2);
		//after Polinomail Equation: y = 33.172, -25.172
		polinomial(1, b, c);
		//so our randonmal y cordinate can be in range of this two y parameters
		y = (minY)+(rand() % (maxY - (minY)+1));
		//now we have (x,y) cordinate in range of 30 radius from the original user's clicked point
		painter.SetPixel(x, y, fillColor);
		//not necessary cause We didnt make any changes in sprayPoint
		sprayPoint = point;
	}
}


void CmypaintDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC painter(this);

	if (nFlags == MK_LBUTTON)
	{
		if (flagButton == 1)// User pressed on Point button
		{
			painter.SetPixel(point, fillColor);
		}
		if (flagButton == 2)// User pressed on Line button
		{
			painter.SelectObject(new CPen(PS_SOLID, thickness, fillColor));
			painter.SetROP2(R2_NOTXORPEN);

			//We are drawing the line at the second time ==> removing the line
			painter.MoveTo(firstPoint);
			painter.LineTo(endPoint);

			//We are drawing the line at the first time ==> showing the line
			painter.MoveTo(firstPoint);
			painter.LineTo(point);
			endPoint = point;
		}
		if (flagButton == 3)// User pressed on Pencil button
		{
			CPen pen(PS_SOLID, thickness,fillColor);
			painter.SelectObject(&pen);
			painter.MoveTo(firstPoint);
			painter.LineTo(point);
			firstPoint = point;
		}
		if (flagButton == 4)// User pressed on Rect button
		{
			/*
			painter.SetROP2(R2_NOP);
			CRect rect(firstPoint, endPoint);
			painter.SelectObject(new CPen (PS_SOLID, thickness, GetSysColor(COLOR_3DFACE)));
			painter.Rectangle(rect);
			painter.FillRect(rect, new CBrush(GetSysColor(COLOR_3DFACE)));

			CPen pen(PS_SOLID, thickness, OutLineColor);
			rect.SetRect(firstPoint, point);
			painter.SelectObject(&pen);
			painter.Rectangle(rect);
			painter.FillRect(rect, new CBrush(fillColor));
			endPoint = point;
			*/
			painter.SetROP2(R2_NOTXORPEN);
			CRect rect(firstPoint, endPoint);
			painter.SelectObject(new CPen(PS_SOLID, thickness, OutLineColor));
			painter.SelectObject(new CBrush(fillColor));
			painter.Rectangle(rect);

			rect.SetRect(firstPoint, point);
			painter.Rectangle(rect);
			endPoint = point;
		}
		if (flagButton == 5)// User pressed on Elipse button
		{
			/*
			//painter.SetROP2(R2_NOTXORPEN);
			CRect rect(firstPoint, endPoint);
			painter.SelectObject(new CPen(PS_SOLID, thickness, GetSysColor(COLOR_3DFACE)));
			painter.SelectObject(new CBrush(GetSysColor(COLOR_3DFACE)));
			painter.Ellipse(rect);
			

			rect.SetRect(firstPoint, point);
			painter.SelectObject(new CPen(PS_SOLID,thickness,OutLineColor));
			painter.SelectObject(new CBrush(fillColor));
			painter.Ellipse(rect);
			endPoint = point;
			*/

			painter.SetROP2(R2_NOTXORPEN);
			CRect rect(firstPoint, endPoint);
			painter.SelectObject(new CPen(PS_SOLID, thickness, OutLineColor));
			painter.SelectObject(new CBrush(fillColor));
			painter.Ellipse(rect);
			
			rect.SetRect(firstPoint, point);
			painter.Ellipse(rect);
			endPoint = point;

		}
		if (flagButton == 6)// User pressed on Eraser button 
		{
			painter.SelectObject(new CPen(PS_SOLID, thickness , GetSysColor(COLOR_3DFACE)));
			painter.MoveTo(firstPoint);
			painter.LineTo(point);
			firstPoint = point;
		}
		if (flagButton == 7)// User pressed on Spray button AND moving
		{
			spray(point);
		}
		if (flagButton == 8)// User pressed on Polygon button
		{
			if (isFirstLine && isPolygonFinish)
			{
				painter.SelectObject(new CPen(PS_SOLID, thickness, OutLineColor));
				painter.SetROP2(R2_NOTXORPEN);
				//We are drawing the line at the second time ==> removing the line
				painter.MoveTo(firstPoint);
				painter.LineTo(endPoint);

				//We are drawing the line at the first time ==> showing the line
				painter.MoveTo(firstPoint);
				painter.LineTo(point);
				endPoint = point;
				endPointPolygon = point;
				cameFromOnMouseMove = true;
			}
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CmypaintDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (flagButton == 8 && cameFromOnMouseMove)
	{
		//turn the flags off after drawing the first line on polygon
		isFirstLine = false;
		isPolygonFinish = false;
		polyPoints = (CPoint*)realloc(polyPoints, (++polyPointsCount) * sizeof(CPoint));
		polyPoints[0] = firstPointPolygon;//or firstPoint
		polyPoints = (CPoint*)realloc(polyPoints, (++polyPointsCount) * sizeof(CPoint));
		polyPoints[1] = endPointPolygon;
	}
	if (flagButton == 8 && !cameFromOnMouseMove)
	{
		polyPoints = (CPoint*)realloc(polyPoints, (++polyPointsCount) * sizeof(CPoint));
		polyPoints[polyPointsCount - 1] = endPointPolygon;
	}
	if (flagButton == 4)
	{
		CClientDC painter(this);
		CRect rect(firstPoint, point);
		painter.SelectObject(new CPen(PS_SOLID, thickness, OutLineColor));
		painter.SelectObject(new CBrush(fillColor));
		painter.Rectangle(rect);
	}
	if (flagButton == 5)
	{
		CClientDC painter(this);
		CRect rect(firstPoint, point);
		painter.SelectObject(new CPen(PS_SOLID, thickness, OutLineColor));
		painter.SelectObject(new CBrush(fillColor));
		painter.Ellipse(rect);
	}
	if (flagButton == 2)
	{
		CClientDC painter(this);
		painter.SelectObject(new CPen(PS_SOLID, thickness, fillColor));
		painter.MoveTo(firstPoint);
		painter.LineTo(point);
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CmypaintDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	firstPoint = endPoint = point;
	//~~~~~~~~~Spray session~~~~~~~~~~~
	if (flagButton == 7)// User pressed on Spray button without moving
	{
		spray(point);
	}
	//~~~~~~~~~Polygon session~~~~~~~~~~~
	//lock the firstPointPolygon in the first LMouse click
	if (flagButton == 8 && isFirstLine) {
		firstPointPolygon = point;
		free(polyPoints);//free to points array
		polyPointsCount = 0;//reset the count
		polyPoints = (CPoint*)malloc(0);//init again
	}
	// User set the line segments(ribs) by click
	if (flagButton == 8 && !isFirstLine && !isPolygonFinish)
	{
		CClientDC painter(this);
		painter.SelectObject(new CPen(PS_SOLID, thickness, OutLineColor));
		painter.MoveTo(endPointPolygon);
		painter.LineTo(point);
		endPointPolygon = point;
		cameFromOnMouseMove = false;//so no change affect after LMouseClick UP init
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CmypaintDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (flagButton == 8 && !isFirstLine && !isPolygonFinish)
	{
		finishPolygon(point);
	}
	CDialogEx::OnLButtonDblClk(nFlags, point);
}
void CmypaintDlg::finishPolygon(CPoint point)
{
	CClientDC painter(this);
	painter.SelectObject(new CPen(PS_SOLID, thickness, OutLineColor));
	painter.SelectObject(new CBrush(fillColor));
	painter.MoveTo(endPointPolygon);
	painter.LineTo(firstPointPolygon);
	//endPointPolygon = point;//no need
	painter.Polygon(polyPoints, polyPointsCount);
	//turn the flags on after drawing the last line on the polygon
	isPolygonFinish = true;
	isFirstLine = true;
	cameFromOnMouseMove = false;//so no change affect after LMouseClick UP init
}

void CmypaintDlg::finishPolygonAfterBtnChange()
{
	CClientDC painter(this);
	painter.SelectObject(new CPen(PS_SOLID, thickness, OutLineColor));
	painter.SelectObject(new CBrush(fillColor));
	painter.MoveTo(endPointPolygon);
	painter.LineTo(firstPointPolygon);
	//turn the flags on after drawing the last line on the polygon
	isPolygonFinish = true;
	isFirstLine = true;
	painter.Polygon(polyPoints, polyPointsCount);
}

void CmypaintDlg::OnBnClickedColor()
{
	// TODO: Add your control notification handler code here
	CColorDialog colorWin;
	if (colorWin.DoModal()==IDOK)
	{
		fillColor = colorWin.GetColor();
	}
}


void CmypaintDlg::OnBnClickedOutlinecolor()
{
	// TODO: Add your control notification handler code here
	CColorDialog colorWin;
	if (colorWin.DoModal() == IDOK)
	{
		OutLineColor = colorWin.GetColor();
	}
}


void CmypaintDlg::OnBnClickedincthick()
{
	// TODO: Add your control notification handler code here
	if (thickness != 10)
	{
		thickness++;
	}
}


void CmypaintDlg::OnBnClickeddecthick()
{
	// TODO: Add your control notification handler code here
	if (thickness != 1)
	{
		thickness--;
	}
}
