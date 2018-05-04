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
	int posX;
	int posY;
	int posZ;
	Space spaces[8][8][8];
public:
	Field();
	int spacesLeft();
	int bombsLeft();
	int returnTotX();
	int returnTotY();
	int returnTotZ();
	int getErrorChecks();
};
