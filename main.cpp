#include "field.h"
//#include "space.h"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
	int result = 0;
	int x,y,z = 0;
	Field a;
	Space spa();
	cout << "Total x values: " << a.returnTotX() << endl;
	cout << "Total y values: " << a.returnTotY() << endl;
	cout << "Total z values: " << a.returnTotZ() << endl;
	cout << "Error check int: " << a.getErrorChecks() << endl;
	a.initBombs(3,3,3);
	cout << "Total number of bombs set: " << a.getBombsSet() << endl;
	cout << "Here is the field!"  << endl << endl;
	a.setNumAround();
	a.printBombs();
	//result = a.bombsLeft();
	//cout << "bombs left are " << result << endl;
	//x = spa.getX();
	//y = spa.getY();
	//z = spa.getZ();
	//cout << "x value of the space is: " << x << endl;
	//cout << "y value of the space is: " << y << endl;
	//cout << "z value of the space is: " << z << endl;	
	return 0;
}
