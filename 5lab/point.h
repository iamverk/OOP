#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <cmath>
#include <limits>

template<class T>
struct Point {
  T x;
  T y;
};

template<class T>
Point<T> operator+(const Point<T>& A, const Point<T>& B) {
    Point<T> res;
    res.x = A.x + B.x;
    res.y = A.y + B.y;
    return res;
}

template<class T>
Point<T> operator/=(Point<T>& A, const double B) { //деление на число
    A.x /= B;
    A.y /= B;
    return A;
}

template<class T>
std::istream& operator>> (std::istream& is, Point<T>& p) {
  is >> p.x >> p.y;
  return is;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const Point<T>& p) {
  os << '(' << p.x << ';' << p.y << ')' ;
  return os;
}



#endif