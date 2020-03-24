#pragma once

#ifndef _GAME_H
#define _GAME_H

class Game
{
public:
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}


private:
	int width;
	int height;
};


#endif
