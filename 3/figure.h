#ifndef D_FIGURE_H_
#define D_FIGURE_H_

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


class Vector
{
public:
	double x, y;
	double length() const;
	explicit Vector(Point a, Point b);
	friend double operator*(Vector a, Vector b);
	bool operator== (Vector b);
};

bool isPerpendicular(const Vector a, const Vector b);
bool isParallel(const Vector a, const Vector b);




class Figure {
public:

	virtual Point center() const = 0;
	virtual void print(std::ostream&) const = 0;
	virtual double square() const = 0;
	virtual ~Figure() = default;
};



#endif //D_FIGURE_H_