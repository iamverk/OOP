#include "figure.h"

class Pentagon : public Figure {
public:
    
    Pentagon(std::istream& is);
    Pentagon() = default;
    
    //explicit Pentagon(const Point& _p1, const Point& _p2, const Point& _p3, const Point& _p4, const Point& _p5);
    
    Point center() const override;
    double square() const override;
    void print(std::ostream& os) const override;
    

private:
    Point p1, p2, p3, p4, p5;
};