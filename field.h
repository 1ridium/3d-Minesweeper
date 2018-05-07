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
	bool gameLost;
    Space spaces[8][8][8];
public:
	Field();
	void initBombs(int x, int y, int z);
	void printBombs();
	void printBombsHidden();
	void getCleared(int x, int y, int z);
	void getFlagged(int x, int y, int z);
    void setNumAround();
    void openZeros(int x, int y, int z);
    //void openAllZero();
    //int openOneZero();
    int spacesLeft();
	int bombsLeft();
	int returnTotX();
	int returnTotY();
	int returnTotZ();
	int getErrorChecks();
	int getBombsSet();
    bool isInBounds(int x, int y, int z);
};
