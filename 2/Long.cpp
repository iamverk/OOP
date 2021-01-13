#include "Long.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <exception>
#include <stdexcept>


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


Long::Long(const char * in) : Long() {
    std::string str = std::string(in);
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



    unsigned long long sh = 1;

    for (int i = 0; i < 32 && i < v.size(); i++) {
        secondHalf += v[i] * sh;
        sh *= 2;
    }

    unsigned long long fh = 1;

    for (int i = 32; i < v.size(); i++) {
        firstHalf += v[i] * fh;
        fh *= 2;
    }
}

Long::Long(std::string str) : Long() {
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



    unsigned long long sh = 1;

    for (int i = 0; i < 32 && i < v.size(); i++) {
        secondHalf += v[i] * sh;
        sh *= 2;
    }

    unsigned long long fh = 1;

    for (int i = 32; i < v.size(); i++) {
        firstHalf += v[i] * fh;
        fh *= 2;
    }
}

Long Long::operator+(const Long &l2) const{
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

Long Long::operator-(const Long &l2) const{
	Long l;
	unsigned long long union1 = 0;
	unsigned long long union2 = 0;
	long long union0 = 0;

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

Long Long::operator*(const Long &l2) const{
	Long l;
	unsigned long long union1 = 0;
	unsigned long long union2 = 0;
	long long union0 = -1;
	Long zero;

	union1 = secondHalf + (firstHalf * grade(2, 32));
	union2 = l2.secondHalf + (l2.firstHalf * grade(2, 32));
	if ((l2 == zero) || (firstHalf == 0 && secondHalf ==0)){
		return zero;
	}
	
		union0 = union1 * union2;
	
		l.secondHalf = union0 % (grade(2, 32));
		l.firstHalf = union0 / (grade(2, 32));
	return l;
}

Long Long::operator/(const Long &l2) const{
	Long l;
	unsigned long long union1 = 0;
	unsigned long long union2 = 0;
	long long union0 = -1;
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

Long Long::operator%(const Long &l2) const{
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

void Long::operator++(){
	Long l, l1;

	Long zero;

	Long one;
	one.secondHalf++;
	l1.firstHalf = firstHalf;
	l1.secondHalf = secondHalf;
	
	 
	l1 = l1 + one;	
	
	firstHalf = l1.firstHalf;
	secondHalf = l1.secondHalf;
}

void Long::operator--(){
	Long l, l1;

	Long zero;

	Long one;
	one.secondHalf++;
	l1.firstHalf = firstHalf;
	l1.secondHalf = secondHalf;
	
	 if(one > l1){
		std::cout << "Error.  -- Cannot be calculated \n";
		return;
	}
	if ((one < l1) || (one == l1)){
		l1 = l1 - one;	
	}
	firstHalf = l1.firstHalf;
	secondHalf = l1.secondHalf;
}

bool Long::operator==(Long &l2) const{
	return ((firstHalf==l2.secondHalf) && (secondHalf==l2.secondHalf));	
}

bool Long::operator>(Long &l2) const{
	return ((firstHalf > l2.firstHalf) || (firstHalf == l2.firstHalf && secondHalf > l2.secondHalf));	
}

bool Long::operator<(Long &l2) const{
	return ((firstHalf < l2.firstHalf) || (firstHalf == l2.firstHalf && secondHalf < l2.secondHalf));
}

Long operator""_long(const char* str){
    return Long(str);
}


void Long::print(std::ostream &os) const{
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



std::istream& operator>> (std::istream& is, Long& l2) {
    std::string a;
    is >> a;
    l2 = Long(a);
}

std::ostream& operator<< (std::ostream& os, const Long& l2) {
    l2.print(os);
}
