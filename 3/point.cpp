#include "point.h"

std::istream& operator >> (std::istream& is, Point &p) {
	return is >> p.x >> p.y;
}

std::ostream& operator << (std::ostream& os, const Point &p) {
    return os << p.x << " " << p.y << '\n';
}

bool operator == (Point a, Point b) {
	return (a.x == b.x && a.y == b.y);
}

Point operator + (Point a, Point b) {
	Point res;
	res.x = a.x + b.x;
	res.y = a.y + b.y;
    return res;
}

Point operator / (Point p, double a) {

	Point res;
	res.x = p.x / a;
	res.y = p.y / a;
    return res;
}

double triangle_height(Point p1, Point p2, Point p3) {
    double A = p2.y - p3.y;
    double B = p3.x - p2.x;
    double C = p2.x*p3.y - p3.x*p2.y;
    return (std::abs(A*p1.x + B*p1.y + C) / std::sqrt(A*A + B*B));
}