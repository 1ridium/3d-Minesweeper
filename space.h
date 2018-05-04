//header for space class
#include "field.h"

class Space
{
	friend class Field
public:
	bool isBomb=false;
	bool isFlagged = false;
	bool isOnCursor = false;
	bool isCleared = false;
	int numAround = 3;
	int xPos = 0;
	int yPos = 0;
	int zPos = 0;
        Field b;
	void setBomb(Field&);
	void getCleared();
	void getFlagged();
};
