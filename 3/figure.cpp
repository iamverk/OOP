#include "figure.h"

std::ostream& operator<<(std::ostream& os, const Figure& f){
	f.print(os);
}




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
    return {a.x + b.x, a.y + b.y};
}

Point operator / (Point p, double a) {
    return { p.x / a, p.y / a};
}

double triangle_height(Point p1, Point p2, Point p3) {
    double A = p2.y - p3.y;
    double B = p3.x - p2.x;
    double C = p2.x*p3.y - p3.x*p2.y;
    return (std::abs(A*p1.x + B*p1.y + C) / std::sqrt(A*A + B*B));
}



Vector::Vector(Point a, Point b) {
	x = b.x - a.x;
	y = b.y - a.y;
}

double Vector::length() const{
	return sqrt(x * x + y * y);
}

bool isParallel(const Vector a, const Vector b) {
	return (a.x * b.y - a.y * b.y) == 0;
}

bool isPerpendicular(const Vector a, const Vector b) {
	return (a.x * b.x + a.y * b.y) == 0;
}

double operator* (Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

bool Vector::operator== (Vector b) {
	return std::abs(x - b.x) < std::numeric_limits<double>::epsilon() * 100 
	&& std::abs(y - b.y) < std::numeric_limits<double>::epsilon() * 100;
}