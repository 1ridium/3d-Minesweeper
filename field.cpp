//Field.cpp file

#include "field.h"
using namespace std;

Field::Field(){ //constructor
	totalSpaces = 8*8*8;
	spacesLeftPre = totalSpaces;
	spacesLeftPost = totalSpaces;
	maxBombs = 18;
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

//this function runs on the first click and initializes bombs
void Field::initBombs(int x, int y, int z){
	//spacesLeftPre=8*8*8;
	int around = 0;
	selX = x; //set field selection variables
	selY = y; //to initial values of xyz
	selZ = z; //like first click in game
	spaces[selX][selY][selZ].setCleared(); //clears first space
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
    setNumAround();
	openZeros(selX,selY,selZ);
  cout << "starting point selected: " << selX << " " << selY << " " << selZ << endl;
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

void Field::printBombsHidden(){
	for (int c = 0; c < 8; c++){
	cout << c << endl;
		for (int b = 0; b < 8; b++){
			for (int a = 0; a < 8; a++){
				if (spaces[a][b][c].getIsBomb() == true){
					cout << ".";
				}
				else {
                    if (spaces[a][b][c].getIsCleared() == true){
					    				cout << spaces[a][b][c].getBombAround();
                    }
                    else {
                    	cout << ".";
                    }
				}
			}
		cout << endl;
		}
	cout << endl << endl;
	}
}

void Field::getCleared(int x, int y, int z){
    spaces[x][y][z].setCleared();
    if(spaces[x][y][z].getIsBomb()){
        gameLost=true;    
    }
    else if(spaces[x][y][z].checkNumAround()==0){
        openZeros(x,y,z);
        updateSpacesLeft();
    }
    else{spacesLeftPost--;}
}

void Field::getFlagged(int x, int y, int z){
    spaces[x][y][z].setFlagged();
    bombsLeftPost--;
}

void Field::updateSpacesLeft(){
    int count = 0;
    for (int z = 0; z < 8; z++){
        for (int y = 0; y < 8; y++){
            for (int x = 0; x < 8; x++){
                if(!spaces[x][y][z].getIsCleared()&&!spaces[x][y][z].getIsBomb()){count++;}
            }
        }
    }
    spacesLeftPost=count;
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

void Field::openZeros(int x, int y, int z){
	//error check
	if (spaces[x][y][z].getBombAround() != 0){
		cout << "Wtf is going on" << endl;
	}
	else {
		for (int c = z-1; c < z+2; c++){
			for (int b = y-1; b < y+2; b++){
				for (int a = x-1; a < x+2; a++){
					if (isInBounds(a,b,c)){ //if this is a real index for a space
                        if (spaces[a][b][c].getBombAround() == 0 && !spaces[a][b][c].getIsCleared()){
							spaces[a][b][c].setCleared();
                            openZeros(a,b,c);
						}
                        else{spaces[a][b][c].setCleared();}
                    }
				}
			}
		}
	}
	cout << "All zeroes should be open" << endl;
}

void Field::lostGame(){
    cout << "you lose";
    gameLost = true;
    //return true;
}

void Field::wonGame(){
    cout << ":)";
    //return false;
}

/* not cool, can be done recursive
void Field::openAllZero(){
    while (openOneZero() == 1) {} //do nothing keep looping
    cout << "finished opening all spaces" << endl;
}

int Field::openOneZero(){ //loop through all and clear all contiguous 0s
    bool newZero = false;
    for (int z = 0; z < 8; z++){
        for (int y = 0; y < 8; y++){
            for (int x = 0; x < 8; x++){
                if (spaces[x][y][z].getIsCleared()){
                    if (spaces[x][y][z].getBombAround() == 0) {
                        for (int c = z-1; c < z+2; c++){
                            for (int b = y-1; b < y+2; b++){
                                for (int a = x-1; a < x+2; a++){
                                    if (isInBounds(a,b,c) && newZero == false){
                                        if(!spaces[a][b][c].getIsCleared()){
                                            newZero = true; //if a space is
                                            //uncleared around the 0 it has not
                                            //been cleared properly
                                        }
                                    }
                                }
                            }
                        }
                        if (newZero == true){
                            for (int c = z-1; c < z+2; c++){
                                for (int b = y-1; b < y+2; b++){
                                    for (int a = x-1; a < x+2; a++){
                                        if (isInBounds(a,b,c)){
                                            spaces[a][b][c].setCleared();
                                        }
                                    }
                                }
                            }
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
*/

int Field::bombsLeft(){
	return bombsLeftPost;
}

int Field::spacesLeft(){
	return spacesLeftPost;
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

bool Field::isInBounds(int x, int y, int z){
    if (x < 0 || y < 0 || z < 0 || x > 7 || y > 7 || z > 7){
        return false;
    }
    return true;
}

bool Field::getGameLost(){
    return gameLost;
}
    
// sup brian
