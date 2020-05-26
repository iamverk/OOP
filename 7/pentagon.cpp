#include "pentagon.h"

#include <cmath>
#include "point.h"

point pentagon::center() const {
    point p;
    p.x = (a1.x + a2.x + a3.x + a4.x + a5.x) / 5;
    p.y = (a1.y + a2.y + a3.y + a4.y + a5.y) / 5;
    return p;
}

void pentagon::print(std::ostream& os) const {
    os << "pentagon\n"<< a1 << '\n' << a2 << '\n' << a3 << '\n' << a4 << '\n' << a5 << '\n';
}

void pentagon::print_file(std::ofstream& of) const {
    of << "pentagon\n"<< a1 << '\n' << a2 << '\n' << a3 << '\n' << a4 << '\n' << a5 << '\n';
}

double pentagon::square() const {
    return (-0.5) * ((a1.x*a2.y + a2.x*a3.y + a3.x*a4.y + a4.x*a5.y + a5.x*a1.y) - ( a1.y*a2.x + a2.y*a3.x + a3.y*a4.x + a4.y*a5.x + a5.y*a1.x ));
}

pentagon::pentagon(std::istream& is) {
    is >> a1 >> a2 >> a3 >> a4 >> a5;
}

pentagon::pentagon(std::ifstream& is) {
    is >> a1 >> a2 >> a3 >> a4 >> a5;
}