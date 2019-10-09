#ifndef _INF_INT_H_
#define _INF_INT_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

class inf_int
{
private :
  vector<int> digits;
  unsigned int length;
  bool thesign;

public :
    inf_int();                                   // constructor
    inf_int(long long);                          // assign 0 as a default value
    inf_int(const char* );
    inf_int(const inf_int& );

    ~inf_int();                                  // destructor

    void Show();
    void Adder(const inf_int&, const inf_int&);
  	void Subtractor(const inf_int&, const inf_int&);

    inf_int& operator=(const inf_int&);          // assignment operator

    friend bool operator==(const inf_int& , const inf_int&);
    friend bool operator!=(const inf_int& , const inf_int&);
    friend bool operator>(const inf_int& , const inf_int&);
    friend bool operator<(const inf_int& , const inf_int&);

    friend inf_int operator+(const inf_int& , const inf_int&);
    friend inf_int operator-(const inf_int& , const inf_int&);
    friend inf_int operator*(const inf_int& , const inf_int&);
	bool Abstract_compair(const inf_int a, const inf_int b);

//    friend ostream& operator<<(ostream& , const inf_int&);
};

#endif
