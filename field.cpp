//Field.cpp file 

#include "field.h"
#include <iostream>
using namespace std;


Field::Field() //constructor
{
	cout<<"field created\n";
}

int Field::bombsLeft()
{
	return bombsLeftPre;
}

int Field::spacesLeft()
{
	return spacesLeft;
}
/* this is probably all garbage	
	int const totalSpaces;
	int spacesLeftPre;
	int spacesLeftPost;
	int bombsLeftPre;
	int bombsLeftPost;
	int maxBombs;
	int posX;
	int posY;
	int posZ;

public:
	int spacesLeft()
	{
		spacesLeftPre --;
		return spacesLeftPre+1;
	}
	int bombsLeft()
	{
		return bombsLeftPre;
	}
	this isnt */
	// sup brian
