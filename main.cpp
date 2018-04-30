#include "field.h"
#include <iostream>
using namespace std;

int result = 0;

int main(int argc, const char * argv[])
{
	Field a;
	result = a.bombsLeft();
	cout << result;
	return 0;
}
