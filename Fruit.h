#pragma once
#ifndef _FRUIT_H
#define _FRUIT_H



class Fruit
{
public:
	Fruit(int w, int h); //seed random number generator, get first x and y positions.
	void reposition(int w, int h);

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}

private:
	int x;
	int y;

};

#endif

