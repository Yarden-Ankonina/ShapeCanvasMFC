#include "pch.h"
#include "MyTriangle.h"

IMPLEMENT_SERIAL(MyTriangle, MyShape, 1);
MyTriangle::MyTriangle()
{

}
MyTriangle::MyTriangle(CPoint s, CPoint e)
	:MyShape(s, e)
{

}

void MyTriangle::draw(CDC* dc)const
{
	CPoint points[3];
	points[0].SetPoint(GetStart().x, GetEnd().y);
	points[1].SetPoint(GetEnd().x, GetEnd().y);
	points[2].SetPoint((GetStart().x + GetEnd().x) / 2, GetStart().y);
	CBrush brush, * oldBrush;
	brush.CreateSolidBrush(bgColor);
	oldBrush = dc->SelectObject(&brush);
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->Polygon(points, 3);
	dc->SelectObject(oldPen);
}

void MyTriangle::clear(CDC* dc) const
{
	CPoint points[3];
	points[0].SetPoint(GetStart().x, GetEnd().y);
	points[1].SetPoint(GetEnd().x, GetEnd().y);
	points[2].SetPoint((GetStart().x + GetEnd().x) / 2, GetStart().y);
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->SetROP2(R2_NOTXORPEN);
	dc->Polygon(points, 3);
	dc->SelectObject(oldPen);
	dc->SetROP2(R2_COPYPEN);
}

bool MyTriangle::isInside(CPoint point)const
{
	if (pullRight)
	{
		if (GetStart().x > point.x || point.x > GetEnd().x)
			return false;
	}
	else	//pull left
	{
		if (GetStart().x < point.x || point.x < GetEnd().x)
			return false;
	}
	if (pullDown)
	{
		if (GetStart().y > point.y || point.y > GetEnd().y)
			return false;
	}
	else
	{
		if (GetStart().y < point.y || point.y < GetEnd().y)
			return false;
	}
	return true;
}