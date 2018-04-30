//header for space class

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
        
	void setBomb();
};
