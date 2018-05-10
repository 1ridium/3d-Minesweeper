// maintrash.cpp this is a working space for tests
// very dirty 

#include "field.h"
//#include "space.h"
#include <iostream>
using namespace std; 

int main(int argc, const char * argv[])
{
	int result = 0;
	int x,y,z,sel = 0;
	Field a;
	Space spa();
	cout << "Total x values: " << a.returnTotX() << endl;
	cout << "Total y values: " << a.returnTotY() << endl;
	cout << "Total z values: " << a.returnTotZ() << endl;
	cout << "Error check int: " << a.getErrorChecks() << endl;
	a.initBombs(2,4,3);
	cout << "Total number of bombs set: " << a.getBombsSet() << endl;
	cout << "Here is the field!"  << endl << endl;
	a.setNumAround();
	a.printBombs();
    a.printBombsHidden();
    cout << "Select x, y, and z values to interact with: ";
   	cin >> x;
    cout << " ";
    cin >> y;
    cout << " ";
    cin >> z;
    cout << endl;
    cout << "Select 0 to flag, 1 to clear";
    cin >> sel;
    if (sel == 0){a.getFlagged(x,y,z);}
    else {a.getCleared(x,y,z);}
    //result = a.bombsLeft();
	//cout << "bombs left are " << result << endl;
	//x = spa.getX();
	//y = spa.getY();
	//z = spa.getZ();
	//cout << "x value of the space is: " << x << endl;
	//cout << "y value of the space is: " << y << endl;
	//cout << "z value of the space is: " << z << endl;
	return 0;
    // This will be the actual loop that the code should run assuming field has
    // been made, first point has been selected and also that all 0's have been
    // opened

    
}
