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

class MyLine : public MyShape
{
public:
	DECLARE_SERIAL(MyLine)

	MyLine();
	MyLine(CPoint,CPoint);
	virtual void draw(CDC* dc) const;
	virtual void clear(CDC* dc) const;
	virtual bool isInside(CPoint point)const;
};

