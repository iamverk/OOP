#include "Long.h"

int main(int argc, char** argv){

	Long l1, l2;
	std::cout << "Enter the number\n";
	std::cin >> l1;

	std::cout << "Enter the second number\n";
	std::cin >> l2;

	std::cout << l1;
	std::cout <<l2;

	std::cout << "Sum is :\n";
	Long lFinal = l1 + l2;
	std::cout << lFinal;

	std::cout << "Differ is:\n";
	lFinal = l1 - l2;
	std::cout << lFinal;
	
	std::cout << "Multiplication is:\n";
    lFinal = l1 * l2;
    std::cout << lFinal;

    std::cout << "Division is:\n";
    lFinal = l1 / l2;
    std::cout << lFinal;

    std::cout << "Remainder from division is:\n";
    lFinal = l1 % l2;
    std::cout << lFinal;

    lFinal = l1;
    std::cout << "++ of the first is:\n";
    ++lFinal;
    std::cout << lFinal;

    lFinal = l2;
    std::cout << "--  of the second is:\n";
    --lFinal;
    std::cout << lFinal;

    if (l1 > l2) {
        std::cout << "First number is larger\n";
    } else if (l1 < l2) {
        std::cout << "Second number is larger\n";
    } else {
        std::cout << "First and second numbers are equal\n";
    }

    std::cout << "Literal examples 89_long and 0_long: \n";
    std::cout << 89_long;
    std::cout << 0_long;

    Long l;

    std::cout << "Enter the number for demonstration of input and output\n";
    std::cin >> l;
    std::cout << l;




	return 0;
}