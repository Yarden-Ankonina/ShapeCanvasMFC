#include "pch.h"
#include "MyShape.h"

MyShape::MyShape()
	:onCanvas(false), penColor(RGB(50, 0, 0)), bgColor(RGB(255, 255, 255)), penSize(1)
{
		pullRight = true;
		pullDown = true;
}

MyShape::MyShape(CPoint s, CPoint e)
	:start(s), end(e), onCanvas(false), penColor(RGB(50,0,0)), bgColor(RGB(255,255,255)), penSize(1)
{
	if (start.x < end.x)
		pullRight = true;
	else
		pullRight = false;

	if (start.y < end.y)
		pullDown = true;
	else
		pullDown = false;
}


CPoint MyShape::GetStart()const 
{ 
	return start;
}
CPoint MyShape::GetEnd()const 
{ 
	return end;

}

void MyShape::SetStart(CPoint p) 
{ 
	start = p; 
}

void MyShape::SetEnd(CPoint p)
{
	end = p;
	if (end.x < 15)
		end.x = 20;
	else if (end.x > 1080)
		end.x = 1075;
	if (end.y < 80)
		end.y = 81;
	else if (end.y > 650)
		end.y = 649;

	if (p.x > start.x)
		pullRight = true;
	else
		pullRight = false;
	if (p.y > start.y)
		pullDown = true;
	else
		pullDown = false;

}
void MyShape::SetPenColor(COLORREF c) 
{
	penColor = c; 
}
void MyShape::SetbgColor(COLORREF c) 
{
	bgColor = c; 
}
void MyShape::SetPenSize(int Size)
{ 
	penSize = Size; 
}
bool MyShape::GetOnCanvas() 
{ 
	return onCanvas; 
}
void MyShape::build(CPoint point)
{

}
CPoint MyShape::lastPoint() 
{ 
	return 0; 
}

void MyShape::SetOnCanvas(bool res)
{
	onCanvas = res;
}

void MyShape::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);

	if (archive.IsStoring()) {
		archive << start;
		archive << end;
		archive << penColor;
		archive << penSize;
	}
	else
	{
		archive >> start;
		archive >> end;
		archive >> penColor;
		archive >> penSize;

	}
}



bool MyShape::isInside(CPoint point)const
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
void MyShape::drawAsSelected(CDC* dc, bool flag)
{
	
	CBrush brush, * oldBrush;
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->Rectangle(start.x, start.y, end.x, end.y);
	if (!flag)
		bgColor = RGB(255, 255, 255);
	else
		bgColor = RGB(100, 100, 100);
	brush.CreateSolidBrush(bgColor);
	oldBrush = dc->SelectObject(&brush);
	draw(dc);
	dc->SelectObject(oldPen);
}
	


void MyShape::changeSelected(CPoint point)
{
	double length = fabs((double)end.x - (double)start.x);
	double height = fabs((double)end.y - (double)start.y);
	start.x = point.x - length / 2;
	start.y = point.y - height / 2;
	end.x = point.x + length / 2;
	end.y = point.y + height / 2;
	if (start.x < 15)
		start.x = 20;
	if (end.x < 15)
		end.x = 20;
	if (start.x > 1080)
		start.x = 1075;
	if (end.x > 1080)
		end.x = 1075;
	if (start.y < 80)
		start.y = 85;
	if (start.y > 650)
		start.y = 645;
	if (end.y < 80)
		end.y = 85;
	if (end.y > 650)
		end.y = 645;
}

