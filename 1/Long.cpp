#include "Long.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <climits>


unsigned long long grade(unsigned long long m, int n){
	int i;
    unsigned long long rez = 1;
 
    for(int i = 1 ; i <= n; i++) {
        rez *= m;
    }
    return rez;
}



Long::Long() {
	firstHalf = 0;
	secondHalf = 0;
}

void Long::Enter() {
    std::string str;

    std::cout << '\n' << "Enter number" << '\n';
    std::cin >> str;

    std::string sec(str.size(), '0');
    std::vector<int> v;

    while (str != sec) {
        int a = 0;
        for (int i = 0; i < str.size(); i++) {
            a *= 10;
            a += str[i] - '0';
            str[i] = char('0' + a / 2);
            a %= 2;
        }
        v.push_back(a);
    }
    unsigned int sh = 1;

    for (int i = 0; i < 32 && i < v.size(); i++) {
        secondHalf += v[i] * sh;
        sh *= 2;
    }

    unsigned int fh = 1;

    for (int i = 32; i  < v.size(); i++) {
        firstHalf += v[i] * fh;
        fh *= 2;
    }
}


Long Long::sum(const Long &l2) {
	Long l;
	unsigned long long union1 = 0;
	unsigned long long union2 = 0;
	unsigned long long union0;
	Long zero;

	union1 = secondHalf + (firstHalf * grade(2, 32));
	union2 = l2.secondHalf + (l2.firstHalf * grade(2, 32));
	
	union0 = union1 + union2;
	
	l.secondHalf = union0 % (grade(2, 32));
	l.firstHalf = union0 / (grade(2, 32));
	

	
	return l;
}




Long Long::diff(const Long &l2) {
	
	Long l;
	unsigned long long union1 = 0;
	unsigned long long union2 = 0;
	unsigned long long union0 = 0;

	union1 = secondHalf + (firstHalf * grade(2, 32));
	union2 = l2.secondHalf + (l2.firstHalf * grade(2, 32));
	if (union1 > union2) {
		union0 = union1 - union2;
	}
	else if(union1 < union2){
		union0 = union2 - union1;
	}
	l.secondHalf = union0 % (grade(2, 32));
	l.firstHalf = union0 / (grade(2, 32));
	return l;
}

Long Long::division(const Long &l2) {
	Long l;
	unsigned long long union1 = 0;
	unsigned long long union2 = 0;
	unsigned long long union0;
	Long zero;

	union1 = secondHalf + (firstHalf * grade(2, 32));
	union2 = l2.secondHalf + (l2.firstHalf * grade(2, 32));

	if(union2 != 0){
		union0 = union1 / union2;
	}
	else if(union2 == 0){
		std::cout << "Error. Cannot be divided by zero\n";
		return zero;
	}

	if (union0 != -1){
		l.secondHalf = union0 % (grade(2, 32));
		l.firstHalf = union0 / (grade(2, 32));
	}

	return l;
}



int Long::compare(const Long & l2) {
	if (firstHalf > l2.firstHalf) {
		return 1;                             // 1 - left bigger // 2 - equal // 3 - right bigger
	} else if (firstHalf < l2.firstHalf) {
		return 3;
	} else {
		if (secondHalf > l2.secondHalf) {
			return 1;
		} else if (secondHalf < l2.secondHalf) {
			return 3;
		} else {
			return 2;
		}
	}
}



Long Long::multi(const Long &l2) {
	Long l;
	unsigned long long union1 = 0;
	unsigned long long union2 = 0;
	unsigned long long union0;
	Long zero;

	union1 = secondHalf + (firstHalf * grade(2, 32));
	union2 = l2.secondHalf + (l2.firstHalf * grade(2, 32));
	if ((zero.compare(l2) == 2) || (firstHalf == 0 && secondHalf ==0))
	{
		return zero;
	}

	union0 = union1 * union2;
	

		l.secondHalf = union0 % (grade(2, 32));
		l.firstHalf = union0 / (grade(2, 32));
	

	
	return l;
}


void Long::plusplus() {
	Long l, l1;

	Long zero;

	Long one;
	one.secondHalf++;
	l1.firstHalf = firstHalf;
	l1.secondHalf = secondHalf;
	
	 
	l1 = l1.sum(one);	
	
	firstHalf = l1.firstHalf;
	secondHalf = l1.secondHalf;
}

void Long::minusminus() {

	Long l, l1;

	Long zero;

	Long one;
	one.secondHalf++;
	l1.firstHalf = firstHalf;
	l1.secondHalf = secondHalf;
	
	 if(one.compare(l1) == 1){
		std::cout << "Error.  -- Cannot be calculated \n";
		return;
	}
	if (one.compare(l1) > 1){
		l1 = l1.diff(one);	
	}
	firstHalf = l1.firstHalf;
	secondHalf = l1.secondHalf;
}



Long Long::remainder(const Long &l2) {

	Long l;
	unsigned long long union1 = 0;
	unsigned long long union2 = 0;
	long long union0 = -1;
	Long zero;
	union1 = secondHalf + (firstHalf * grade(2, 32));
	union2 = l2.secondHalf + (l2.firstHalf * grade(2, 32));

	if(union2 != 0){
		union0 = union1 % union2;
	}
	else if(union2 == 0){
		std::cout << "Error. Cannot be divided by zero\n";
		return zero;
	}

	if (union0 != -1){
		l.secondHalf = union0 % (grade(2, 32));
		l.firstHalf = union0 / (grade(2, 32));
	}

	return l;
}




void Long::print() {

    Long l1;
    l1.firstHalf = firstHalf;
    l1.secondHalf = secondHalf;

    std::vector<int> v;

    while (l1.firstHalf != 0) {
        v.push_back(l1.firstHalf % 2);
        l1.firstHalf /= 2;
    }

    for (int i = 0; i < 32 - v.size(); i++) {
        std::cout << 0;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        std::cout << v[i];
    }
    v.clear();

    std::cout << " ";

    while (l1.secondHalf != 0) {
        v.push_back(l1.secondHalf % 2);
        l1.secondHalf /= 2;
    }
    for (int i = 0; i < 32 - v.size(); i++) {
        std::cout << 0;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        std::cout << v[i];
    }
    std::cout << '\n';

}
