#ifndef _HEXAGON_H
#define _HEXAGON_H

#include "figure.h"

struct hexagon : figure{
private:
    point a1,a2,a3,a4,a5,a6;
public:
    point center() const override ;
    void print(std::ostream&) const  override ;
    void printFile(std::ofstream&) const  override ;
    double square() const override ;
    hexagon() = default;
    hexagon(std::istream& is);
    hexagon(std::ifstream& is);
};



#endif