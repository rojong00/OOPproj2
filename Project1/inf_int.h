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
  vector<unsigned int> digits;
  unsigned int length;
  bool thesign;

public :
    inf_int();               // assign 0 as a default value
    inf_int(int );
    inf_int(const char* );
//    inf_int(const inf_int& );  // copy constructor;

    void show();
    //~inf_int(); // destructor

    inf_int& operator=(const inf_int&); // assignment operator

    friend bool operator==(const inf_int& , const inf_int&);
    friend bool operator!=(const inf_int& , const inf_int&);
    friend bool operator>(const inf_int& , const inf_int&);
    friend bool operator<(const inf_int& , const inf_int&);

    friend inf_int operator+(const inf_int& , const inf_int&);
    friend inf_int operator-(const inf_int& , const inf_int&);
    friend inf_int operator*(const inf_int& , const inf_int&);

    friend ostream& operator<<(ostream& , const inf_int&);

	void Adder(const inf_int&, const inf_int&);
	void Subtractor(const inf_int&, const inf_int&);

};

#endif
