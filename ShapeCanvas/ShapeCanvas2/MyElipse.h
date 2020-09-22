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
class MyElipse : public MyShape
{
protected:
	CPoint center;
	double radius;
public:
	DECLARE_SERIAL(MyElipse)


	MyElipse();
	MyElipse(CPoint s, CPoint e);
	virtual void draw(CDC* dc) const;
	virtual void clear(CDC* dc) const;
};

