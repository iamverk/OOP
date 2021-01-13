#include "pentagon.h"


//Pentagon::Pentagon(const Point& _p1, const Point& _p2, const Point& _p3, const Point& _p4, const Point& _p5)
//        : p1(_p1), p2(_p2), p3(_p3), p4(_p4), p5(_p5) {}

double Pentagon::square() const {
    return
            triangle_height(p1, p2, p3) * Vector(p2, p3).length() / 2
            + triangle_height(p1, p3, p4) * Vector(p3, p4).length() / 2
            + triangle_height(p1, p4, p5) * Vector(p4, p5).length() / 2;
}

Point Pentagon::center() const {
    return (p1 + p2 + p3 + p4 + p5) / 5;
}

void Pentagon::print(std::ostream& os) const{
	os << "Pentagon\n";
	os << p1 << p2 << p3 << p4 << p5;
}

Pentagon::Pentagon(std::istream& is) {
    
    is >> p1 >> p2 >> p3 >> p4 >> p5;

    if (p1 == p2 || p2 == p3 || p3 == p4 || p4 == p5 || p1 == p3 || p1 == p4 || p1 == p5 || p2 == p4 || p2 == p5){

    	throw std::logic_error("No points are able to be equal");
    }
}