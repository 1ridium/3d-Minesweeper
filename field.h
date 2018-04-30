//learning how a header file works

class Field
{
public:
	const int totalSpaces = 0;
	int spacesLeftPre = 0;
	int spacesLeftPost = 0;
	int bombsLeftPre = 50;
	int bombsLeftPost = 0;
	int maxBombs = 0;
	int posX = 0;
	int posY = 0;
	int posZ = 0;


	int spacesLeft();
	int bombsLeft();
};
