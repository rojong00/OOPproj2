#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include "inf_int.h"

using namespace std;

int main()
{

	inf_int a("0");
	inf_int b("0");
	inf_int c(1234678972);

	
	//bool test1 = a > b;
	//bool test2 = c > b;
	inf_int test3 = a - b;

	//cout << test1 << endl;
	//cout << test2 << endl;
	test3.show();

	return 0;
}
