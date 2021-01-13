#include "Long.h"


int main(int argc, char** argv) {


    Long l1;

    l1.Enter();

    Long l2;

    l2.Enter();

    l1.print();
    l2.print();

    std::cout << "sum is :\n";
    Long lFinal = l1.sum(l2);
    lFinal.print();

    lFinal = l1.diff(l2);
    std::cout << "differ is:\n";
    lFinal.print();

    std::cout << "multiplication is:\n";
    lFinal = l1.multi(l2);
    lFinal.print();

    std::cout << "division is:\n";
    lFinal = l1.division(l2);
    lFinal.print();

    std::cout << "remainder from division is:\n";
    lFinal = l1.remainder(l2);
    lFinal.print();

    lFinal = l1;
    std::cout << "++ of the first is:\n";
    lFinal.plusplus();
    
    lFinal.print();

    lFinal = l2;
    std::cout << "--  of the second is:\n";
    lFinal.minusminus();
    lFinal.print();





int k = l1.compare(l2);
    if (k == 1){
        std::cout << "First number is bigger\n";
    }
    else if (k == 2){
        std::cout << "Numbers are equal\n";
    }
    else if (k == 3){
        std::cout << "Second number is bigger\n";
    }

    return 0;
}
