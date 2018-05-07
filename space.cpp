#include "space.h"
using namespace std;

Space::Space(){
	//cout << "lets make a space" << endl;
	isBomb = false;
	isFlagged = false;
	isOnCursor = false;
	isCleared = false;
	numAround = 0;
	xPos = 0;
	yPos = 0;
	zPos = 0;
}

void Space::setLoc(int x, int y, int z){
	//cout << "making a new cell" << endl;
	xPos = x;
	yPos = y;
	zPos = z;
}

void Space::setBomb(int nB, int nS ){
	double sL; //spaces left
	double bL;
	double probBomb;
	double rng; //rolls to see if it will be a bomb
	sL = ((double) nS);
	bL = ((double) nB);
	probBomb = bL/sL;
	rng = ((double) rand() / (RAND_MAX));
	if(rng<probBomb)
	{
		isBomb = true;
	}
}

void Space::setNoBombManual(){
	isBomb = false;
}

void Space::setCleared(){
  isCleared = true;
  if (isBomb){
    cout << "You lose" << endl;
  }
  else{
    cout << "Number of bombs around this space: " <<  numAround << endl;
  }
}

void Space::setNumAround(int n){
	numAround = n;
}

void Space::setFlagged(){
    isFlagged = true;
}

int  Space::getX(){
	return xPos;
}

int Space::getY(){
	return yPos;
}

int Space::getZ(){
	return zPos;
}

int Space::checkNumAround(){
	if (xPos == 0 || xPos == 7){
		if (yPos == 0 || yPos == 7){
			if (zPos == 0 || zPos == 7){
				return 8;
			}
		return 12;
		}
		if (zPos == 0 || zPos == 7){
			return 12;
		}
	return 18;
	}
	if (yPos == 0 || yPos == 7){
		if (zPos == 0 || zPos == 7){
			return 12;
		}
	return 18;
	}
	if (zPos == 0 || zPos == 7){
		return 18;
	}
	return 27;
}

int Space::getBombAround(){
	return numAround;
}

bool Space::getIsBomb(){
	return isBomb;
}

bool Space::getIsFlagged(){
	return isFlagged;
}

bool Space::getIsOnCursor(){
	return isOnCursor;
}

bool Space::getIsCleared(){
	return isCleared;
}
