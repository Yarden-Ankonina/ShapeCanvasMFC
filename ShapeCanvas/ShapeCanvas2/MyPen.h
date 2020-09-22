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


#include "MyLine.h"
#include <vector>
#pragma once
using namespace std;
class MyPen : public MyLine
{
private:
	vector<CPoint> pointArray;
public:
	DECLARE_SERIAL(MyPen)

	MyPen();
	MyPen(CPoint);

	CPoint lastPoint();
	void build(CPoint currentPoint) override;
	void draw(CDC* dc) const override;
	void clear(CDC* dc) const override;

};

