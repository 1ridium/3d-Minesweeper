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

void Field::initBombs(int x, int y, int z){
	//spacesLeftPre=8*8*8;
	int around = 0;
	selX = x; //set field selection variables
	selY = y; //to initial values of xyz
	selZ = z; //like first click in game
	around = spaces[selX][selY][selZ].checkNumAround();
	spacesLeftPre -= around;
	std::cout << spacesLeftPre << std::endl;
	for (int a = 0; a < 8; a++){
		for (int b = 0; b < 8; b++){
			for (int c = 0; c < 8; c++){
			//test if touching first bomb
				if (a>=(selX-1) && a<= (selX+1) && b>=(selY-1) && b<=(selY+1) && c>=(selZ-1) && c<=(selZ+1)){
					spaces[a][b][c].setNoBombManual();
					spacesLeftPre--;
				}
				else{
					spaces[a][b][c].setBomb(bombsLeftPre, spacesLeftPre);
					spacesLeftPre--;
					if(spaces[a][b][c].getIsBomb() == true){
					bombsLeftPre--;
					}
				}
			}
		}
	}
	
}

int Field::getBombsSet(){
	int total = 0;

	for (int a = 0; a < 8; a++){
		for (int b = 0; b < 8; b++){
			for (int c = 0; c < 8; c++){
				if (spaces[a][b][c].getIsBomb() == true){
					total++;
				}
			}
		}
	}
	return total;
}

void Field::printBombs(){
	for (int a = 0; a < 8; a++){
		for (int b = 0; b < 8; b++){
			for (int c = 0; c < 8; c++){
				if (spaces[a][b][c].getIsBomb() == true){
					std::cout << "@";
				}
				else {
					std::cout << ".";
				}
			}
		std::cout << std::endl;
		}
	std::cout << std::endl << std::endl;
	}
}
int Field::bombsLeft()
{
	return bombsLeftPre;
}

int Field::spacesLeft()
{
	return spacesLeftPre;
}
	// sup brian


