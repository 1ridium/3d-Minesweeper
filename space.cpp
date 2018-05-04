using namespace std;
#include <cstdlib>
#include "space.h"
#include <iostream>
#include "field.h"

/*class Space {
	friend class Field;
	bool isBomb;
	bool isFlagged;
	bool isOnCursor;
	bool isCleared;
	int numAround;
	int xPos;
	int yPos;
	int zPos;
public:
*/
void Space::setBomb(Field& temp)
	{
		double sL; //spaces left
		double bL;
		double probBomb;
		double rng; //rolls to see if it will be a bomb
		sL = temp.spacesLeft();
		bL = temp.bombsLeft();
		probBomb = bL/sL;
		rng = ((double) rand() / (RAND_MAX));
		if(rng<probBomb)
		{
			isBomb = true;
			//b.bombsLeftPre --;	//decrease num bombs
		}
	}
	
	//void setNum(Space *a[3][3][3]);
	void Space::getCleared()
	{

	}
	void Space::getFlagged()
	{

	}

