#include "pch.h"
#include "MyLine.h"


IMPLEMENT_SERIAL(MyLine, MyShape, 1)

MyLine::MyLine()
{

}

MyLine::MyLine(CPoint s, CPoint e)
	:MyShape(s,e)
{

}


void MyLine::draw(CDC* dc) const
{
	CBrush brush, * oldBrush;
	brush.CreateSolidBrush(bgColor);
	oldBrush = dc->SelectObject(&brush);
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->MoveTo(GetStart());
	dc->LineTo(GetEnd());
	dc->SelectObject(oldPen);
}
void MyLine::clear(CDC* dc) const
{
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->SetROP2(R2_NOTXORPEN);
	dc->MoveTo(GetStart());
	dc->LineTo(GetEnd());
	dc->SelectObject(oldPen);
	dc->SetROP2(R2_COPYPEN);
}
bool MyLine::isInside(CPoint point)const
{
	return false;
}
