#pragma once
#ifndef _SNAKE_H
#define _SNAKE_H

class Snake
{
public:
	Snake(int _x, int _y);

	void move();

	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

	int nTail;
	int tailX[100];
	int tailY[100];

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getDir() {
		return dir;
	}

	void setDir(eDirection d) {
		dir = d;
	}

private:
	int x;
	int y;
	eDirection dir;

};




#endif

