#ifndef __Long_h__
#define __Long_h__


#include <iostream>
#include <string>

class Long
{
public:
	Long();
	Long(const char *);
	Long(std::string);

	void read(std::istream &is);

	Long operator+(const Long &l2) const;
	Long operator-(const Long &l2) const;
	Long operator*(const Long &l2) const;
	Long operator/(const Long &l2) const;
	Long operator%(const Long &l2) const;


	void operator++();
	void operator--();

	bool operator==(Long &l2) const;
    bool operator>(Long &l2) const;
    bool operator<(Long &l2) const;
	
	void print(std::ostream &os) const;
    
    unsigned int firstHalf;
	unsigned int secondHalf;
};

Long operator""_long(const char* str);

std::istream& operator>>(std::istream& is, Long& l2);

std::ostream& operator<<(std::ostream& os, const Long& l2);


unsigned long long grade(unsigned long long m, int n);



#endif