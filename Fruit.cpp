#include "Fruit.h"
#include <time.h>
#include <random>
Fruit::Fruit(int w, int h)
{
	srand(time(NULL));
	x = rand() % w; //places fruit at a random place ON THE MAP
	y = rand() % h;

}

void Fruit::reposition(int w, int h)
{
	x = rand() % w; //places fruit at a random place ON THE MAP
	y = rand() % h;
}
