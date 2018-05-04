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
	void setBomb(/*Field& temp*/);
	void getCleared();
	void getFlagged();
	void setLoc(int x, int y, int z);
	int getX();
	int getY();
	int getZ();
	bool getIsBomb();
	bool getIsFlagged();
	bool getIsOnCursor();
	bool getIsCleared();
};
