#ifndef _RHOMBUS_H_
#define _RHOMBUS_H_

#include "figure.h"

struct rhombus : figure{
private:
    point a1,a2,a3,a4,a5;
public:
    point center() const override ;
    void print(std::ostream&) const  override ;
    void printFile(std::ofstream&) const  override ;
    double square() const override ;
    rhombus() = default;
    rhombus(std::istream& is);
    rhombus(std::ifstream& is);
};


#endif




