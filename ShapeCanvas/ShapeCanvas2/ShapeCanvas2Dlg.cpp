
// ShapeCanvas2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ShapeCanvas2.h"
#include "ShapeCanvas2Dlg.h"
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





CShapeCanvas2Dlg::CShapeCanvas2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPECANVAS2_DIALOG, pParent), currentShape(nullptr), lButtonDown(false), previousPoint(NULL), selectedShape(0),currColor(RGB(0,0,0)),currSize(5), isSelected(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CShapeCanvas2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapeCanvas2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CShapeCanvas2Dlg::OnBnClickedRadioRectangle)
	ON_BN_CLICKED(IDC_RADIO2, &CShapeCanvas2Dlg::OnBnClickedRadioLine)
	ON_BN_CLICKED(IDC_BUTTON1, &CShapeCanvas2Dlg::OnBnClickedButtonPenColorPicker)
	ON_BN_CLICKED(IDC_BUTTON2, &CShapeCanvas2Dlg::OnBnClickedButtonUndo)
	ON_BN_CLICKED(IDC_RADIO3, &CShapeCanvas2Dlg::OnBnClickedRadioElipse)
	ON_BN_CLICKED(IDC_RADIO4, &CShapeCanvas2Dlg::OnBnClickedRadioPen)
	ON_COMMAND(ID_FILE_NEW32774, &CShapeCanvas2Dlg::OnFileNew)
	ON_COMMAND(ID_FILE_SAVE32772, &CShapeCanvas2Dlg::OnFileSave)
	ON_COMMAND(ID_FILE_LOAD, &CShapeCanvas2Dlg::OnFileLoad)
	ON_BN_CLICKED(IDC_RADIO5, &CShapeCanvas2Dlg::OnBnClickedRadioTriangle)
	ON_BN_CLICKED(IDC_RADIO6, &CShapeCanvas2Dlg::OnBnClickedRadioSquare)
	ON_BN_CLICKED(IDC_RADIO7, &CShapeCanvas2Dlg::OnBnClickedRadioDiamond)
	ON_WM_HSCROLL()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON3, &CShapeCanvas2Dlg::OnBnClickedDelete)
END_MESSAGE_MAP()


// CShapeCanvas2Dlg message handlers

BOOL CShapeCanvas2Dlg::OnInitDialog()
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
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapeCanvas2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShapeCanvas2Dlg::OnPaint()
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
		CClientDC dc(this);
		CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
		CPen* oldPen = dc.SelectObject(&pen);
		dc.Rectangle(15, 80, 1080, 650);
		dc.SelectObject(oldPen);
		if (!selectedShape)
		{
			CButton* pButton = (CButton*)GetDlgItem(IDC_RADIO4);//default is pen
			pButton->SetCheck(true);
		}
		if (isSelected)
		{
			currentShape->drawAsSelected(&dc, isSelected);
		}
		drawAllShapes(&dc);
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapeCanvas2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



MyShape* CShapeCanvas2Dlg::getCurrentShape(CPoint Point)
{
	switch (selectedShape)
	{
		case(ShapeBank::Line):
			{
			return new MyLine(Point, Point);
				break;
			}
		case(ShapeBank::Rectangle):
		{
			return new MyRectangle(Point, Point);
			break;
		}
		case(ShapeBank::Elipse):
		{
			return new MyElipse(Point, Point);
			break;
		}
		case(ShapeBank::Triangle):
		{
			return new MyTriangle(Point, Point);
			break;
		}
		case(ShapeBank::Square):
		{
			return new MySquare(Point, Point);
			break;
		}
		case(ShapeBank::Diamond):
		{
			return new MyDiamond(Point, Point);
			break;
		}
	}
		return new MyPen(Point);

}

bool CShapeCanvas2Dlg::isInCanvas(CPoint point)
{
	if (point.x > 20 && point.x < 1075 && point.y > 85 && point.y < 645)
		return true;
	else
		return false;
}

void CShapeCanvas2Dlg::drawAllShapes(CDC* dc)
{
	int max = Shapes.GetCount();
	for (int i = 0; i < max; i++)
	{
		MyShape* tempShape = Shapes[i];
			tempShape->draw(dc);
	}
}



void CShapeCanvas2Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	if (isInCanvas(point)) 
	{
		if (isSelected)
		{
			currentShape->changeSelected(point);
			Invalidate(false);
		}
		else
		{
			lButtonDown = true;
			previousPoint = point;
			currentShape = getCurrentShape(point);
			currentShape->SetPenColor(currColor);
			currentShape->SetPenSize(currSize);
			Shapes.Add(currentShape);
			currentShape->draw(&dc);
		}
		
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}




void CShapeCanvas2Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
		if (lButtonDown)
		{
			if (isSelected)
			{

			}
			else
			{
				CClientDC dc(this);
				currentShape->clear(&dc);
				currentShape->SetEnd(point);
				drawAllShapes(&dc);
				Invalidate(false);
			}
		}
	lButtonDown = false;

	
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CShapeCanvas2Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	//check if lbutton is pressed
	if (lButtonDown) {
		//set the end point of the line to the point of the mouse
		if (isSelected)
		{

		}
		else
		{
			if (isInCanvas(point))
			{
				int max = Shapes.GetSize();
				CClientDC dc(this);
				if (selectedShape == ShapeBank::Pen && max > 0)
				{
					Shapes[max - 1]->build(point);
				}
				currentShape->clear(&dc);
				currentShape->SetEnd(point);
				dc.SetROP2(R2_NOTXORPEN);
				currentShape->draw(&dc);
				//Invalidate(false);
			}
			previousPoint = point;
		}

	}
	CDialogEx::OnMouseMove(nFlags, point);
}



void CShapeCanvas2Dlg::OnBnClickedRadioRectangle()
{
	selectedShape = ShapeBank::Rectangle;
}


void CShapeCanvas2Dlg::OnBnClickedRadioLine()
{
	selectedShape = ShapeBank::Line;
}


void CShapeCanvas2Dlg::OnBnClickedRadioElipse()
{
	selectedShape = ShapeBank::Elipse;
}

void CShapeCanvas2Dlg::OnBnClickedRadioPen()
{
	selectedShape = ShapeBank::Pen;

}

void CShapeCanvas2Dlg::OnBnClickedRadioTriangle()
{
	selectedShape = ShapeBank::Triangle;

}
void CShapeCanvas2Dlg::OnBnClickedRadioSquare()
{
	selectedShape = ShapeBank::Square;
}

void CShapeCanvas2Dlg::OnBnClickedRadioDiamond()
{
	selectedShape = ShapeBank::Diamond;
}

void CShapeCanvas2Dlg::OnBnClickedButtonUndo()
{
	if (Shapes.IsEmpty())
		return;
	int max = Shapes.GetSize();
	{
		Shapes.RemoveAt(max - 1);
		Invalidate(false);
	}
}

void CShapeCanvas2Dlg::OnBnClickedButtonPenColorPicker()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		currColor = dlg.GetColor();

	}
}

void CShapeCanvas2Dlg::OnBnClickedDelete()
{
	if (Shapes.IsEmpty())
		return;
	if (isSelected)
	{
		int max = Shapes.GetSize();
		for (int i = 0; i < max; i++)
		{
			if (currentShape == Shapes[i])
			{
				isSelected = false;
				CClientDC dc(this);
				currentShape->drawAsSelected(&dc, false);
				Shapes.RemoveAt(i);
				Invalidate(false);
				break;
			}
				
		}

	}
}

void CShapeCanvas2Dlg::OnFileNew()
{
	this->clearScreen();
}


void CShapeCanvas2Dlg::OnFileSave()
{
	const TCHAR czFilter[] = _T("Shape files (*.shape)|*.shape|All Files (*.*)|*.*||");
		CFileDialog fDialog(FALSE, _T("shape"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);
	
		if (fDialog.DoModal() == IDOK) {
			CString fileName = fDialog.GetPathName();
			CFile file(fileName, CFile::modeCreate | CFile::modeWrite);
			CArchive ar(&file, CArchive::store);
			Shapes.Serialize(ar);
			ar.Close();
			file.Close();
		}
}


void CShapeCanvas2Dlg::OnFileLoad()
{
	const TCHAR czFilter[] = _T("Shape files (*.shape)|*.shape|All Files (*.*)|*.*||");
		CFileDialog fDialog(TRUE, _T("shape"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);
	
		if (fDialog.DoModal() == IDOK) {
			CString fileName = fDialog.GetPathName();
			CFile file(fileName, CFile::modeRead);
			CArchive ar(&file, CArchive::load);
			Shapes.Serialize(ar);
			ar.Close();
			file.Close();
			isSelected = false;
			Invalidate(false);
		}
}

void CShapeCanvas2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (nPos != 0)
	{
		currSize = nPos;
		Invalidate(false);
	}
		
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}



void CShapeCanvas2Dlg::clearScreen()
{
	Shapes.RemoveAll();
	Invalidate(false);
}




void CShapeCanvas2Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	int max = Shapes.GetCount();
	if (!lButtonDown) {
		for (int i = max - 1; i > -1; i--) {
			if (Shapes[i]->isInside(point)) 
			{
				currentShape = Shapes[i];
				if (isSelected)
				{
					isSelected = false;
					currentShape->drawAsSelected(&dc, false);
				}
				else
				isSelected = true;
				break;
			}
		}
	}
	Invalidate(false);
	CDialogEx::OnRButtonDown(nFlags, point);
}




