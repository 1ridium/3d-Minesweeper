// main.cpp this will be the final working version of main

#include "field.h"
//#include "space.h"
#include <iostream>
using namespace std; 

int main(int argc, const char * argv[])
{
	int result = 0;
	int x,y,z,sel = 0;
	Field a;
    cout << "Select x, y, and z values to open the first space:  ";
   	cin >> x;
    cout << " ";
    cin >> y;
    cout << " ";
    cin >> z;
    cout << endl;
    a.initBombs(x,y,z);
	a.setNumAround();
    cout << "Total number of bombs set: " << a.getBombsSet() << endl;
	cout << "Here is the field!"  << endl << endl;
	a.printBombs();
    a.printBombsHidden();
    while(!a.getGameLost()&&a.spacesLeft()!=0){
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
        a.printBombsHidden();
    }
    if (a.spacesLeft()==0){
        a.wonGame();
    }
    else if (a.getGameLost()){
        a.lostGame();
    }
    else{cout << "how did i get here";}
  	return 0;
    // This will be the actual loop that the code should run assuming field has
    // been made, first point has been selected and also that all 0's have been
    // opened

    
}
