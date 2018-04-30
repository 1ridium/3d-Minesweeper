using namespace std;
#include <cstdlib>

class Space {
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
	void setBomb(bool)
	{
		double sL; //spaces left
		double bL;
		double probBomb;
		double rng; //rolls to see if it will be a bomb
		sL = Field.spacesLeft();
		bL = Field.bombsLeft();
		probBomb = bL/sL;
		rng = ((double) rand() / (RAND_MAX));
		if(rng<probBomb)
		{
			isBomb = true;
			Field.bombsLeftPre --;	//decrease num bombs
		}
	}
	
	void setNum(Space *a[3][3][3]);
	void getCleared();
	void getFlagged();
};	

