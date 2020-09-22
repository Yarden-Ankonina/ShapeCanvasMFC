#include "pch.h"
#include <math.h>
#include "MySquare.h"

IMPLEMENT_SERIAL(MySquare, MyShape, 1)


MySquare::MySquare()
{

}


MySquare::MySquare(CPoint s, CPoint e) 
	:MyRectangle(s, e)
{
	
}

void MySquare::draw(CDC* dc)const
{
	
	int height = GetHeight();
	int length = GetLength(height);
	CBrush brush, * oldBrush;
	brush.CreateSolidBrush(bgColor);
	oldBrush = dc->SelectObject(&brush);
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->Rectangle(GetStart().x, GetStart().y, GetStart().x + length, GetStart().y +height);
	dc->SelectObject(oldPen);
}



void MySquare::clear(CDC* dc) const
{
	int height = GetHeight();
	int length = GetLength(height);
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->SetROP2(R2_NOTXORPEN);
	dc->Rectangle(GetStart().x, GetStart().y, GetStart().x + length, GetStart().y + height);
	dc->SelectObject(oldPen);
	dc->SetROP2(R2_COPYPEN);
}
int MySquare::GetHeight()const
{
	return GetEnd().y - GetStart().y;
}
int MySquare::GetLength(int a)const
{
	if (GetEnd().x - GetStart().x > 0)
	{
		if (a > 0)
			return a;
		else return -a;
	}
	else
	{
		if (a > 0)
			return -a;
		else
			return a;
	}
}


bool MySquare::isInside(CPoint point)const
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
