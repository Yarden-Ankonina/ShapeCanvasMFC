#include "pch.h"
#include "MyPen.h"


IMPLEMENT_SERIAL(MyPen, MyShape, 1)


MyPen::MyPen()
{

}

MyPen::MyPen(CPoint p)
	:MyLine(p,p)
{
	pointArray.push_back(p);
}
void MyPen::draw(CDC* dc) const
{
	int max = pointArray.size();
	int i;
	CPen pen(PS_SOLID, penSize, penColor);
	CPen* oldPen = dc->SelectObject(&pen);
	dc->MoveTo(pointArray[0]);
	dc->SelectObject(&pen);
		for (i = 1; i < max; i++)
		{
			dc->LineTo(pointArray[i]);
		}
	dc->SelectObject(oldPen);

}
void MyPen::clear(CDC* dc) const
{
}


CPoint MyPen::lastPoint()
{
	return pointArray[pointArray.size() - 1];
}

void MyPen::build(CPoint currentPoint)
{
	pointArray.push_back(currentPoint);
}

