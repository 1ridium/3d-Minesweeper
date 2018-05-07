//learning how a header file works
#include <iostream>
#include "space.h"
//using namespace std;

class Field
{
private:
	int totalSpaces;
	int spacesLeftPre;
	int spacesLeftPost;
	int bombsLeftPre;
	int bombsLeftPost;
	int maxBombs;
	int selX;
	int selY;
	int selZ;
	int posX;
	int posY;
	int posZ;
	Space spaces[8][8][8];
public:
	Field();
	void initBombs(int x, int y, int z);
	void printBombs();
	void getCleared(int x, int y, int z);
	void setNumAround();
	int spacesLeft();
	int bombsLeft();
	int returnTotX();
	int returnTotY();
	int returnTotZ();
	int getErrorChecks();
	int getBombsSet();
};
