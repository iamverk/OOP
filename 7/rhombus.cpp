#include "rhombus.h"
#include <iostream>
#include <cmath>



rhombus::rhombus(std::istream& is) {
    is >> a1 >> a2 >> a3 >> a4;
    double a, b, c, d;
    a = sqrt((a2.x - a1.x) * (a2.x - a1.x) + (a2.y - a1.y) * (a2.y - a1.y));
    b = sqrt((a3.x - a2.x) * (a3.x - a2.x) + (a3.y - a2.y) * (a3.y - a2.y));
    c = sqrt((a3.x - a4.x) * (a3.x - a4.x) + (a3.y - a4.y) * (a3.y - a4.y));
    d = sqrt((a4.x - a1.x) * (a4.x - a1.x) + (a4.y - a1.y) * (a4.y - a1.y));
    if(a != b || a != c || a != d)
        throw std::logic_error("Wrong coordinates. It's not a rhombus.");
}

rhombus::rhombus(std::ifstream& is) {
    is >> a1 >> a2 >> a3 >> a4;
    double a, b, c, d;
    a = sqrt((a2.x - a1.x) * (a2.x - a1.x) + (a2.y - a1.y) * (a2.y - a1.y));
    b = sqrt((a3.x - a2.x) * (a3.x - a2.x) + (a3.y - a2.y) * (a3.y - a2.y));
    c = sqrt((a3.x - a4.x) * (a3.x - a4.x) + (a3.y - a4.y) * (a3.y - a4.y));
    d = sqrt((a4.x - a1.x) * (a4.x - a1.x) + (a4.y - a1.y) * (a4.y - a1.y));
    if(a != b || a != c || a != d)
        throw std::logic_error("Wrong coordinates. It's not a rhombus.");
}



double rhombus::square() const {
    double  d1 =  sqrt((a1.x - a3.x) * (a1.x - a3.x) + (a1.y - a3.y) * (a1.y - a3.y));
    double  d2 =  sqrt((a2.x - a4.x) * (a2.x - a4.x) + (a2.y - a4.y) * (a2.y - a4.y));
    return d1 * d2 / 2;
}


point rhombus::center() const {
    point res;
    res.x = (a1.x + a2.x + a3.x + a4.x) / 4;
    res.y = (a1.y + a2.y + a3.y + a4.y) / 4;
    return res;
}


void rhombus::print(std::ostream& os) const {
    os << "rhombus\n"<< a1 << '\n' << a2 << '\n' << a3 << '\n' << a4 << '\n';
}

void rhombus::print_file(std::ofstream& of) const {
    of << "rhombus\n"<< a1 << '\n' << a2 << '\n' << a3 << '\n' << a4  << '\n';
}