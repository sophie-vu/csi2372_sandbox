#include <iostream>
#include "Line_Equation.h"

using namespace std;

Line::Line()
{
	slope = 1.0;
	yintercept = 0.0;
}

Line::Line(double m, double b)
{
	slope = m;
	yintercept = b;
}

Line::Line(const Line& l)
{
	slope = l.slope;
	yintercept = l.yintercept;
}

double Line::get_slope()
{
	return slope;
}

double Line::get_yintercept()
{
	return yintercept;
}

void Line::set_slope(double m)
{
	slope = m;
}

void Line::set_yintercept(double b)
{
	yintercept = b;
}

bool Line::is_parallel(Line l)
{
	return slope == l.slope;
}

bool Line::inersection_point(Line l, double& x, double& y)
{
	if (is_parallel(l))
		return false;

	//y1 = m1 * x + b1
	//y2 = m2 * x + b2
	//y1 = y2
	//m1 * x + b1 = m2 * x + b2
	//x(m1 - m2) = b2 - b1
	//x = (b2 - b1) / (m1 - m2)

	x = (l.yintercept - yintercept) / (slope - l.slope);
	y = evaluate(x);
	return true;
}

double Line::evaluate(double x)
{
	return slope * x + yintercept;
}