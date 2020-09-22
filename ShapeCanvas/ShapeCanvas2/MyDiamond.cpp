#include "pch.h"
#include "MyDiamond.h"
IMPLEMENT_SERIAL(MyDiamond, MyShape, 1);

MyDiamond::MyDiamond()
{

}


MyDiamond::MyDiamond(CPoint s, CPoint e)
	:MyRectangle(s, e)
{

}


void MyDiamond::draw(CDC* dc)const
{

	CPoint points[4];
	points[0].SetPoint(GetStart().x, (GetStart().y+GetEnd().y)/2);
	points[1].SetPoint((GetStart().x + GetEnd().x) / 2, GetStart().y);
	points[2].SetPoint(GetEnd().x, (GetStart().y + GetEnd().y) / 2);
	points[3].SetPoint((GetStart().x + GetEnd().x) / 2, GetEnd().y);
	CBrush brush, * oldBrush;
	brush.CreateSolidBrush(bgColor);
	oldBrush = dc->SelectObject(&brush);
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->Polygon(points, 4);
	dc->SelectObject(oldPen);
}



void MyDiamond::clear(CDC* dc) const
{
	CPoint points[4];
	points[0].SetPoint(GetStart().x, (GetStart().y + GetEnd().y) / 2);
	points[1].SetPoint((GetStart().x + GetEnd().x) / 2, GetStart().y);
	points[2].SetPoint(GetEnd().x, (GetStart().y + GetEnd().y) / 2);
	points[3].SetPoint((GetStart().x + GetEnd().x) / 2, GetEnd().y);
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->SetROP2(R2_NOTXORPEN);
	dc->Polygon(points, 4);
	dc->SelectObject(oldPen);
	dc->SetROP2(R2_COPYPEN);
}