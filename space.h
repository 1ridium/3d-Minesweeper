//header for space class
//#include "field.h"
#include <iostream>
//using namespace std;

class Space
{
	friend class Field;
private:

	bool isBomb;
	bool isFlagged;
	bool isOnCursor;
	bool isCleared;
	int numAround;
	int xPos;
	int yPos;
	int zPos;
public:
	Space();
	void setLoc(int x, int y, int z);
	void setBomb(int nB, int nS);
	void setNoBombManual();
	void setCleared();
	void setNumAround(int n);
	void setFlagged();
    int getX();
	int getY();
	int getZ();
	int checkNumAround();
	int getBombAround();
	bool getIsBomb();
	bool getIsFlagged();
	bool getIsOnCursor();
	bool getIsCleared();

};
