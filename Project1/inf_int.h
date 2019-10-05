#ifndef _INF_INT_H_
#define _INF_INT_H_

#include <iostream>
#include <vector>

using namespace std;

class inf_int
{
public: // initializer 구현후, private로 바꾸면서 main.cpp의 선언을 바꾸어주면 된다.
	//char* digits;
	vector<int> digits;      //Vector 로 우선 해놓음
	unsigned int length;
	bool thesign;   // true if positive , false if negative.
	// ex) 15311111111111111 -> digits="11111111111111351", length=17, thesign=true;
	// ex) -12345555555555 -> digits="55555555554321", length=14, thesign=false
	// you may insert additional private members here.

public:
	inf_int();               // assign 0 as a default value
	friend inf_int operator+(const inf_int&, const inf_int&);
	friend inf_int operator-(const inf_int&, const inf_int&);
	friend inf_int operator*(const inf_int&, const inf_int&);

	void Adder(const inf_int&, const inf_int&);
	void Subtractor(const inf_int&, const inf_int&);
};

#endif