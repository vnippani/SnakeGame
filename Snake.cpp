#include "Snake.h"

Snake::Snake(int _x, int _y)
{
	x = _x;
	y = _y;
	dir = STOP;
	nTail = 0;


}

void Snake::move()
{
    int prevX = tailX[0]; int prevY = tailY[0]; //saves previous x and y of the first tail element.
    tailX[0] = x; tailY[0] = y;
    int prev2X, prev2Y;

    for (int i = 1; i < nTail; i++) { //array will constantly move forward (values move TOWARD index 0)
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    //now move the snake head
    switch (dir)
    {
    case LEFT:
        x = x - 1;
        break;
    case RIGHT:
        x = x + 1;
        break;
    case UP:
        y = y - 1;
        break;
    case DOWN:
        y = y + 1;
        break;
    }

}
