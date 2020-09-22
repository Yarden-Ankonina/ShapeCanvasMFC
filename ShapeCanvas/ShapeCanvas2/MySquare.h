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


#include "MyRectangle.h"
#pragma once
class MySquare : public MyRectangle
{
public:
	DECLARE_SERIAL(MySquare)

	MySquare();
	MySquare(CPoint s, CPoint e);
	int GetLength(int) const;
	int GetHeight() const;
	void draw(CDC* dc)const;

	void clear(CDC* dc) const;

	bool isInside(CPoint point)const;

};

