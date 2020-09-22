/*
******************************************************************************************
*					  Final Project - ShapeCanvas - OOP - Summer Semester - 2020       	 *
*																						 *
*																						 *
*								       Submitted By										 *
*																						 *
*			     	Hadar Arbiv 312274384	&	Yarden Ankonina 205415664				 *
*																						 *
*																						 *
******************************************************************************************
*/

//Abstract class uses polymorphism

#pragma once
class MyShape :public CObject
{
protected:

	CPoint start, end;
	bool pullRight, pullDown;
	bool onCanvas;
	COLORREF penColor, bgColor;
	int penSize;
public:
	MyShape();
	MyShape(CPoint s, CPoint e);
	CPoint GetStart()const;
	CPoint GetEnd()const;
	void SetStart(CPoint p);
	void SetEnd(CPoint p);
	void SetPenColor(COLORREF c);
	void SetbgColor(COLORREF c);
	void SetPenSize(int Size);
	bool GetOnCanvas();
	void SetOnCanvas(bool);
	virtual void Serialize(CArchive& archive);
	virtual CPoint lastPoint();
	virtual void build(CPoint);
	virtual void draw(CDC *dc) const = 0;
	virtual void clear(CDC *dc) const = 0;
	virtual bool isInside(CPoint point)const;
	virtual void drawAsSelected(CDC* dc, bool);
	virtual void changeSelected(CPoint point);
};

