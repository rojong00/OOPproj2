// initializer 가 완성되었다고 생각하고 +, -, * 만을 구현.
// 지금은 public 으로 변수에 직접적으로 접근하지만, 추후 initizlier 구현후 private로 바꿈

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <algorithm>
#include "inf_int.h"

using namespace std;

int main()
{
	inf_int a;
	inf_int b;
	inf_int c;

	for (int i = 0; i < 8; i++)
	{
		a.digits.push_back(7);
	}

	for (int i = 0; i < 8; i++)
	{
		b.digits.push_back(i);
	}

	c = a - b;
	unsigned int num = 6;

	for (unsigned int i = 0; i < c.digits.size(); i++)
	{
		cout << c.digits[num-i] << ' ';
	}

	//inf_int a, b, c, d;
	//inf_int a, e;
	//inf_int b(100);
	//inf_int c("321111111111122222222222233333333333444444444445555555555");
	//inf_int d("123451987651234572749499923455022211");
	//inf_int f = d;
	//inf_int g(f);

	// cin >> g ;   // not required

	//a = b * c;
	// e=g/f;       // not required

	//b = c - d;


	//if (f == d) {
	//	cout << "a : " << a << endl;
	//	cout << "b : " << b << endl;
	//	cout << "c : " << c << endl;
	//	cout << "d : " << d << endl;
	//	// cout << "e : " << e << endl;
	//	cout << "f : " << f << endl;
	//	// cout << "g : " << g << endl;
	//}

	return 0;
}
