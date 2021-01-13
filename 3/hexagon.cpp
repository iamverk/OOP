#include "hexagon.h"


//Hexagon::Hexagon(const Point& _p1, const Point& _p2, const Point& _p3, const Point& _p4, const Point& _p5,const Point& _p6)
//: p1(_p1), p2(_p2), p3(_p3), p4(_p4), p5(_p5), p6(_p6) {}


Point Hexagon::center() const {
    double x,y;
    x = (p1.x + p2.x + p3.x + p4.x + p5.x + p6.x) / 6;
    y = (p1.y + p2.y + p3.y + p4.y + p5.y + p6.y) / 6;
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
void Hexagon::print(std::ostream& os) const {
   
    os << "Hexagon\n";
    os << p1 << p2 << p3 << p4 << p5 << p6;
}

double Hexagon::square() const {
    return (-0.5) * ((p1.x*p2.y + p2.x*p3.y + p3.x*p4.y + p4.x*p5.y + p5.x*p6.y + p6.x*p1.y) - ( p1.y*p2.x + p2.y*p3.x + p3.y*p4.x + p4.y*p5.x + p5.y*p6.x + p6.y*p1.x ));
}

Hexagon::Hexagon(std::istream& is) {
    is >> p1 >> p2 >> p3 >> p4 >> p5 >> p6;
    if (p1 == p2 || p2 == p3 || p3 == p4 || p4 == p5 || p5 == p6 || p6 == p1 || p1 == p3 || p1 == p4 || p1 == p5 || p2 == p4 || p2 == p5 || p2 == p6 || p3 == p5 || p3 == p6 || p4 == p6) {

        throw std::logic_error("No points are able to be equal");
    }
}
