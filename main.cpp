#include <iostream>
#include <Windows.h>

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
	// Draw the game and set the position of the 
	// Fruit randomly and the Snake in the middle
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < width+1; i++)
		std::cout << "#";
	std::cout << std::endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0) {
				std::cout << "#";
			}
			else if (i == y && j == x) {
				std::cout << "S";
			}
			else if (i == fruitY && j == fruitX) {
				std::cout << "F";
			}
			else {
				std::cout << " ";
			}

			if (j == width - 1)
				std::cout << "#" << std::endl;
			
		}
	}
	for (int i = 0; i < width+1; i++)
		std::cout << "#";
	std::cout << std::endl;
}
void Input()
{
	// Check what key is being pressed and assign a 
	// direction to the Snake for use in logic to move 
	// the snake in the desired direction

	int keypress = 0;
	std::cout << keypress;
	int W = GetAsyncKeyState(0x57);
	int A = GetAsyncKeyState(0x41);
	int S = GetAsyncKeyState(0x53);
	int D = GetAsyncKeyState(0x44);

	if (W != 0) {
		//std::cout << "you pressed w! " << w;
		dir = UP;
	}
	else if (A != 0) {
		//std::cout << "You pressed A! " << A;
		dir = LEFT;
	}
	else if (S != 0) {
		//std::cout << "You pressed S! " << S;
		dir = DOWN;
	}
	else if (D != 0) {
		//std::cout << "You pressed D! " << D;
		dir = RIGHT;
	}
		
}
void Logic() 
{
	switch (dir) {
	case UP:
	}
}
int main() 
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(1000);
		
	}
	return 0;
}