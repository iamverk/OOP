#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include "point.h"
#include <fstream>

struct figure {
    virtual point center() const = 0;
    virtual void print(std::ostream&) const = 0 ;
    virtual void print_file(std::ofstream&) const = 0 ;
    virtual double square() const = 0;
    virtual ~figure() = default;
};


#endif //FIGURE_H