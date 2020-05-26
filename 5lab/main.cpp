#include <iostream>
#include <algorithm>

#include "list.h"
#include "point.h"
#include "rhombus.h"

#include<clocale>


void Menu1() {
	std::cout << "1. Добавить фигуру в список\n";
	std::cout << "2. Удалить фигуру\n";
	std::cout << "3. Вывести фигуру\n";
	std::cout << "4. Вывести все фигуры\n";
	std::cout << "5. Вывести кол-во фигур чья площадь больше чем ...\n";
}

void PushMenu() {
	std::cout << "1. Добавить фигуру в начало списка\n";
	std::cout << "2. Добавить фигуру в конец списка\n";
	std::cout << "3. Добавить фигуру по индексу\n";
}

void DeleteMenu() {
	std::cout << "1. Удалить фигуру в начале списка\n";
	std::cout << "2. Удалить фигуру в конце списка\n";
	std::cout << "3. Удалить фигуру по индексу\n";
}

void PrintMenu() {
	std::cout << "1. Вывести первую фигуру в списке\n";
	std::cout << "2. Вывести последнюю фигуру в списке\n";
	std::cout << "3. Вывести фигуру по индексу\n";
}

int main() {
	setlocale(LC_ALL, "rus");
	containers::list<rhombus<int>> MyList;

	rhombus<int> Temprhombus;

	while (true) {
		Menu1();
		int n, m, kek;
		double s;
		std::cin >> n;
		switch (n) {
		case 1:
			Temprhombus.read(std::cin);
			PushMenu();
			std::cin >> m;
			switch (m) {
			case 1:
				MyList.push_front(Temprhombus);
				break;
			case 2:
				MyList.push_back(Temprhombus);
				break;
			case 3:
				std::cin >> kek;
				MyList.insert_by_number(kek, Temprhombus);
			default:
				break;
			}
			break;
		case 2:
			DeleteMenu();
			std::cin >> m;
			switch (m) {
			case 1:
				MyList.pop_front();
				break;
			case 2:
				MyList.pop_back();
				break;
			case 3:
				std::cin >> kek;
				MyList.delete_by_number(kek);
				break;
			default:
				break;
			}
			break;
		case 3:
			PrintMenu();
			std::cin >> m;
			switch (m) {
			case 1:
				MyList.front().print(std::cout);
				std::cout << std::endl;
				break;
			case 2:
				MyList.back().print(std::cout);
				std::cout << std::endl;
				break;
			case 3:
				std::cin >> kek;
				MyList[kek].print(std::cout);
				std::cout << std::endl;
				break;
			default:
				break;
			}
			break;
		case 4:
			std::cout << MyList.length() << std::endl;
			std::for_each(MyList.begin(), MyList.end(), [](rhombus<int>& X) { X.print(std::cout); std::cout << std::endl; });
			
			break;
		case 5:
			std::cin >> s;
			std::cout << std::count_if(MyList.begin(), MyList.end(), [=](rhombus<int>& X) {return X.area() > s; }) << std::endl;
			break;
		default:
			return 0;
		}
	}
	
	system("pause");
	return 0;
}