#include "pch.h"
#include "MyRectangle.h"

IMPLEMENT_SERIAL(MyRectangle, MyShape, 1)


MyRectangle::MyRectangle()
{

}


MyRectangle::MyRectangle(CPoint s, CPoint e) :MyShape(s, e)
{

}

void MyRectangle::draw(CDC* dc)const
{
	CBrush brush, * oldBrush;
	brush.CreateSolidBrush(bgColor);
	oldBrush = dc->SelectObject(&brush);
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->Rectangle(GetStart().x, GetStart().y, GetEnd().x, GetEnd().y);
	dc->SelectObject(oldPen);
}

void MyRectangle::clear(CDC* dc) const
{
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->SetROP2(R2_NOTXORPEN);
	dc->Rectangle(GetStart().x, GetStart().y, GetEnd().x, GetEnd().y);
	dc->SelectObject(oldPen);
	dc->SetROP2(R2_COPYPEN);
}

bool MyRectangle::isInside(CPoint point)const
{
	if (pullRight)
	{
		if (GetStart().x > point.x  || point.x > GetEnd().x)
			return false;
	}
	else	//pull left
	{
		if (GetStart().x < point.x || point.x < GetEnd().x)
			return false;
	}
	if(pullDown)
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
