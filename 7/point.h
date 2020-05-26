#ifndef D_POINT_H_
#define D_POINT_H_

#include <iostream>
#include <numeric>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct point {

    double x, y;

};

std::istream& operator>>(std::istream& is, point &p);
std::ostream& operator<<(std::ostream& os, const point &p);
bool operator==(point a, point b);
point operator+(point a, point b);
point operator / (point p, double a);
double triangle_height(point p1, point p2, point p3);


#endif