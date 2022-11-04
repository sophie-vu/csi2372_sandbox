#pragma once

#include <iostream>

using namespace std;

class Line
{
private:
	double slope;
	double yintercept;
	//y = mx + b
	// ax + by + c = 0
	// aNxN + a(N-1)x(N-1) + .... + a0x0 = 0
	//No vertical line
public:
	Line(); //default constructor
	Line(double, double);
	Line(const Line &);
	double get_slope();
	double get_yintercept();
	void set_slope(double);
	void set_yintercept(double);
	bool is_parallel(Line);
	bool inersection_point(Line, double&, double&);
	double evaluate(double);
	//double x, y;
	//Line l1, l2;
	//if (l1.intersection_point(l2, x, y))




};