#include "field.h"
//#include "space.h"
#include <iostream>
//using namespace std;

int main(int argc, const char * argv[])
{
	int result = 0;
	int x,y,z = 0;
	Field a;
	Space spa();
	std::cout << "Total x values: " << a.returnTotX() << std::endl;
	std::cout << "Total y values: " << a.returnTotY() << std::endl;
	std::cout << "Total z values: " << a.returnTotZ() << std::endl;
	std::cout << "Error check int: " << a.getErrorChecks() << std::endl;
	a.initBombs(3,3,3);
	std::cout << "Total number of bombs set: " << a.getBombsSet() << std::endl;
	//result = a.bombsLeft();
	//cout << "bombs left are " << result << endl;
	//x = spa.getX();
	//y = spa.getY();
	//z = spa.getZ();
	//std::cout << "x value of the space is: " << x << std::endl;
	//std::cout << "y value of the space is: " << y << std::endl;
	//std::cout << "z value of the space is: " << z << std::endl;	
	return 0;
}
