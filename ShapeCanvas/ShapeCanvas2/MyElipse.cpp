#include "pch.h"
#include "MyElipse.h"

IMPLEMENT_SERIAL(MyElipse, MyShape, 1)

MyElipse::MyElipse()
	:radius(0)
{

}

MyElipse::MyElipse(CPoint s, CPoint e)
	:MyShape(s, e), radius(0), center(((s.x+e.x)/2), ((s.y+e.y)/2))
{
}


void MyElipse::draw(CDC* dc) const
{
	CBrush brush, * oldBrush;
	brush.CreateSolidBrush(bgColor);
	oldBrush = dc->SelectObject(&brush);
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->Ellipse(GetStart().x, GetStart().y, GetEnd().x, GetEnd().y);
	dc->SelectObject(oldPen);
}
void MyElipse::clear(CDC* dc) const
{
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->SetROP2(R2_NOTXORPEN);
	dc->Ellipse(GetStart().x, GetStart().y, GetEnd().x, GetEnd().y);
	dc->SelectObject(oldPen);
	dc->SetROP2(R2_COPYPEN);

}
