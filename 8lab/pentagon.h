#ifndef OOP_EXERCISE_08_PENTAGON_H
#define OOP_EXERCISE_08_PENTAGON_H

#include "figure.h"

struct pentagon : figure{
private:
    point a1,a2,a3,a4,a5;
public:
    point center() const override ;
    void print(std::ostream&) const  override ;
    void printFile(std::ofstream&) const  override ;
    double square() const override ;
    pentagon() = default;
    pentagon(std::istream& is);
    pentagon(std::ifstream& is);
};

#endif //OOP_EXERCISE_08_PENTAGON_H