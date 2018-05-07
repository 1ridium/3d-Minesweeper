//Field.cpp file 

#include "field.h"
using namespace std;

Field::Field() //constructor
{
	totalSpaces = 8*8*8;
	spacesLeftPre = totalSpaces;
	spacesLeftPost = totalSpaces;
	maxBombs = 180;
	bombsLeftPre = maxBombs;
	bombsLeftPost = maxBombs;
	gameLost = false;
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
	cout<<"field created\n";
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
	cout << spacesLeftPre << endl;
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
	for (int c = 0; c < 8; c++){
	cout << c << endl;
		for (int b = 0; b < 8; b++){
			for (int a = 0; a < 8; a++){
				if (spaces[a][b][c].getIsBomb() == true){
					cout << "@";
				}
				else {
					cout << spaces[a][b][c].getBombAround();
				}
			}
		cout << endl;
		}
	cout << endl << endl;
	}
}
	


void Field::getCleared(int x, int y, int z){
    spaces[x][y][z].setCleared();
}

void Field::getFlagged(int x, int y, int z){
    spaces[x][y][z].setFlagged();
    bombsLeftPost--;
}

void Field::setNumAround(){
	int num = 0;
	for (int c = 0; c < 8; c++){
		for (int b = 0; b < 8; b++){
			for (int a = 0; a < 8; a++){
				num = 0;
				for (int l = c-1; l < c+2; l++){
					for (int k = b-1; k < b+2; k++){
						for (int j= a-1; j < a+2; j++){
							//big if statement incoming
							if (j < 0 || k < 0 || l < 0 || j > 7 || k > 7 || l > 7){}
							else{ 
								if(spaces[j][k][l].getIsBomb()==true){
									num++;
								}
							}
						}
					}
				}
				spaces[a][b][c].setNumAround(num);
			}
		}
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


