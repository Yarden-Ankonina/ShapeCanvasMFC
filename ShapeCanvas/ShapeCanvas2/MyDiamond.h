
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
class MyDiamond : public MyRectangle
{
	DECLARE_SERIAL(MyDiamond)

	MyDiamond();
	MyDiamond(CPoint s, CPoint e);
	
	void draw(CDC* dc)const;

	void clear(CDC* dc) const;

};

