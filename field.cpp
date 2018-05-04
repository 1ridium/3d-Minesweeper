//Field.cpp file 

#include "field.h"


Field::Field() //constructor
{
	totalSpaces = 8*8*8;
	spacesLeftPre = totalSpaces;
	spacesLeftPost = totalSpaces;
	maxBombs = 50;
	bombsLeftPre = maxBombs;
	bombsLeftPost = maxBombs;
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			for (int c = 0; c < 8; c++) {
				spaces[a][b][c].setLoc(a,b,c);				
			}
		}
	}
	//posX = 0;
	//posY = 0;
	//posZ = 0;
	std::cout<<"field created\n";
}

int Field::returnTotX(){
	int total = 0;
	for (int a = 0; a < 8; a++){
		for (int b = 0; b < 8; b++){
			for (int c = 0; c < 8; c++){
				total += spaces[a][b][c].getX();
			}
		}
	}
	return total;
}

int Field::returnTotY(){
	int total = 0;
	for (int a = 0; a < 8; a++){
		for (int b = 0; b < 8; b++){
			for (int c = 0; c < 8; c++){
				total += spaces[a][b][c].getY();
			}
		}
	}
	return total;
}

int Field::returnTotZ(){
	int total = 0;
	for (int a = 0; a < 8; a++){
		for (int b = 0; b < 8; b++){
			for (int c = 0; c < 8; c++){
				total += spaces[a][b][c].getZ();
			}
		}
	}
	return total;
}

int Field::getErrorChecks(){
	int result = 0;
	for (int a = 0; a < 8; a ++){
		for (int b = 0; b < 8; b++){
			for (int c = 0; c < 8; c++){
				if (spaces[a][b][c].getIsBomb() == true){
				result = 1;
				}
				
				if (spaces[a][b][c].getIsFlagged() == true){
				result = 2;
				}
				
				if (spaces[a][b][c].getIsOnCursor() == true){
				result = 3;
				}
				if (spaces[a][b][c].getIsCleared() == true){
				result = 4;
				}
			}
		}
	}
	return result;
}
int Field::bombsLeft()
{
	return bombsLeftPre;
}

int Field::spacesLeft()
{
	return spacesLeftPre;
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
