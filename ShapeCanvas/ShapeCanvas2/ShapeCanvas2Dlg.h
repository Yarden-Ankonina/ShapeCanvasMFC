
//main dialog application header get all files
// ShapeCanvas2Dlg.h : header file
//

#pragma once
#include "MyPen.h"
#include "MyElipse.h"
#include "MyRectangle.h"
#include "MyLine.h"
#include "MyTriangle.h"
#include "MySquare.h"
#include "MyDiamond.h"
#include "MyShape.h"

// CShapeCanvas2Dlg dialog
class CShapeCanvas2Dlg : public CDialogEx
{
private:
	bool lButtonDown, isSelected;
	enum ShapeBank{ Pen, Line, Rectangle, Elipse, Triangle , Square, Diamond};//enum of all shapes
	int selectedShape;
	int currSize;
	COLORREF currColor;
	CPoint previousPoint;
	CTypedPtrArray<CObArray, MyShape*> Shapes;
	MyShape* currentShape;
	
// Construction
	void drawAllShapes(CDC *dc);
	MyShape * getCurrentShape(CPoint point);
	bool isInCanvas(CPoint point);
	void clearScreen();
public:
	CShapeCanvas2Dlg(CWnd* pParent = nullptr);	// standard constructor


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAPECANVAS2_DIALOG };
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
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadioRectangle();
	afx_msg void OnBnClickedRadioLine();
	afx_msg void OnBnClickedRadioElipse();
	afx_msg void OnBnClickedButtonPenColorPicker();
	afx_msg void OnBnClickedButtonUndo();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedRadioPen();
	afx_msg void OnBnClickedRadioTriangle();
	afx_msg void OnBnClickedRadioSquare();
	afx_msg void OnBnClickedRadioDiamond();
	afx_msg void OnFileNew();
	afx_msg void OnFileSave();
	afx_msg void OnFileLoad();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};
