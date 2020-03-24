// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <ctime>
#include "Game.h"
#include "Snake.h"
#include "Fruit.h"

using namespace std;


bool gameOver;

void Draw(Game g, Snake s, Fruit f, int score) 
{
    system("cls"); //this command clears the screen, and should be our first step.
    //print top border
    for (int i = 0; i < g.getWidth() + 1; i++) {
        cout << "#";
    }
    cout << endl;

    //draw map
    for (int i = 0; i < g.getHeight(); i++) {

        for (int j = 0; j < g.getWidth(); j++) {
            if (j == 0)
                cout << "#";
            if (i == s.getY() && j == s.getX())
                cout << "H"; //head
            else if (i == f.getY() && j == f.getX())
                cout << "F";
            else
            {
                bool isTail = false;
                for (int k = 0; k < s.nTail; k++) {
                    if (s.tailX[k] == j && s.tailY[k] == i) {
                        isTail = true;
                        cout << "t";
                    }


                }
                if (!isTail)
                    cout << " ";

            }


            if (j == g.getWidth() - 1)
                cout << "#";
        }
        cout << endl;

    }

    //print bottom border
    for (int i = 0; i < g.getWidth() + 1; i++) {
        cout << "#";
    }

    cout << endl << "Score: " << score;
}

void Input(Snake &s)
{
    if (_kbhit()) //if any keyboard key is pressed, return true
    {
        switch (_getch()) //get the character of the pressed key
        {
        case 'a':
            s.setDir(s.LEFT);
            break;
        case 'd':
            s.setDir(s.RIGHT);
            break;
        case 'w':
            s.setDir(s.UP);
            break;
        case 's':
            s.setDir(s.DOWN);
            break;
        case 'x':
            gameOver = true;
            break;
        }

    }
}

void Logic(Game &g, Snake &s, Fruit &f, int &score)
{
    s.move();

    if (s.getX() > g.getWidth() || s.getX() < 0 || s.getY() > g.getHeight() || s.getY() < 0)
        gameOver = true;

    for (int i = 0; i < s.nTail; i++) {
        if (s.tailX[i] == s.getX() && s.tailY[i] == s.getY())
            gameOver = true;
    }

    if (s.getX() == f.getX() && s.getY() == f.getY()) {
        score += 10;
        f.reposition(g.getWidth(), g.getHeight());
        s.nTail++;
    }
}

int main()
{
    cout << "Hello World!\n";
    int score = 0;
    Game map(20, 20);
    Snake s(map.getWidth() / 2, map.getHeight() / 2);
    Fruit f(map.getWidth(), map.getHeight());

    while (!gameOver) {
        Draw(map, s, f, score);
        Draw(map,s,f,score);
        Input(s);
        Logic(map,s,f,score);
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
