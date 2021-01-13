#ifndef D_HEXAGON_H
#define D_HEXAGON_H

#include "figure.h"

class Hexagon : public Figure {

public: 
	Hexagon(std::istream& is);
	Hexagon() = default;
    
    Point center() const override;
    void print(std::ostream&) const  override;
    double square() const override;

    //explicit Hexagon(const Point& _p1, const Point& _p2, const Point& _p3, const Point& _p4, const Point& _p5, const Point& _p6);
   
private:
    Point p1, p2, p3, p4, p5, p6;
};


#endif