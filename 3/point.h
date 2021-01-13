#ifndef D_POINT_H_
#define D_POINT_H_

#include <iostream>
#include <numeric>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Point {

	double x, y;
	
};

std::istream& operator>>(std::istream& is, Point &p);
std::ostream& operator<<(std::ostream& os, const Point &p);
bool operator==(Point a, Point b);
Point operator+(Point a, Point b);
Point operator / (Point p, double a);
double triangle_height(Point p1, Point p2, Point p3);


#endif