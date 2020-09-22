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


#include "MyShape.h"
#pragma once
class MyRectangle :public MyShape
{
public:
	DECLARE_SERIAL(MyRectangle)

	MyRectangle();
	MyRectangle(CPoint s, CPoint e);

	virtual void draw(CDC* dc)const;

	virtual void clear(CDC* dc) const;

	virtual bool isInside(CPoint point)const;

};

