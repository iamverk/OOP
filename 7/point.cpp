#include "point.h"

std::istream& operator >> (std::istream& is, point &p) {
    return is >> p.x >> p.y;
}

std::ostream& operator << (std::ostream& os, const point &p) {
    return os << p.x << " " << p.y << '\n';
}

bool operator == (point a, point b) {
    return (a.x == b.x && a.y == b.y);
}

point operator + (point a, point b) {
    point res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}

point operator / (point p, double a) {

    point res;
    res.x = p.x / a;
    res.y = p.y / a;
    return res;
}

