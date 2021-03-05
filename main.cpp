#include <iostream>
#include <Windows.h>

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score, bodyLength;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
const int maxBody = (width - 1) * (height - 1);
int bodyX[maxBody];
int bodyY[maxBody];

void Setup()
{
	// Draw the game and set the position of the 
	// Fruit randomly and the Snake in the middle
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	bodyLength = 0;
	for (int i = 0; i<maxBody;i++) {
		if (i!=0) {
			bodyX[i] = NULL;
			bodyY[i] = NULL;
		}
		else {
			bodyX[i] = x;
			bodyY[i] = y;
		}
	}
	fruitX = rand() % (width-1)+1;
	fruitY = rand() % (height-1)+1;
	score = 0;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < width + 1; i++)
		std::cout << "#";
	std::cout << std::endl;

	for (int i = 1; i < height; i++)
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
				for (int k = 0; k < maxBody; k++) {
					if (bodyX[k] == NULL) {
						break;
					}
					else if (bodyX[k] == j && bodyY[k] == i) {
						std::cout << "S";
					}
				}
				std::cout << " ";
			}
			if (j == width - 1)
				std::cout << "#" << std::endl;
		}
	}
	for (int i = 0; i < width + 1; i++)
		std::cout << "#";
	std::cout << std::endl;
	std::cout << fruitX;
	std::cout << std::endl;
	std::cout << fruitY;
}
void Input()
{
	// Check what key is being pressed and assign a 
	// direction to the Snake for use in logic to move 
	// the snake in the desired direction

	int W = GetAsyncKeyState(0x57);
	int A = GetAsyncKeyState(0x41);
	int S = GetAsyncKeyState(0x53);
	int D = GetAsyncKeyState(0x44);

	if (W != 0) {
		dir = UP;
	} else if (A != 0) {
		dir = LEFT;
	} else if (S != 0) {
		dir = DOWN;
	} else if (D != 0) {
		dir = RIGHT;
	}

}
void UpdateBody() 
{
	// Update the position of each body to its predecessors 
	// position creating a tail. Stopping the update process
	// if we reach the end of the tail.
	for (int i = 0; i < maxBody; i++) {
		if (bodyX[i] == NULL) {
			break;
		}
		else if (i == 0) {
			bodyX[i] = x;
			bodyY[i] = y;
		}
		else {
			bodyX[i] = bodyX[i - 1];
			bodyY[i] = bodyY[i - 1];
		}
	}
}
void Logic()
{
	switch (dir) 
	{
		case 3:
			UpdateBody();			
			y -= 1;
			break;
		case 1:
			UpdateBody();
			x -= 1;
			break;
		case 4:
			UpdateBody();
			y += 1;
			break;
		case 2: 
			UpdateBody();
			x += 1;
	}
	if (x == 0 || x == width) {
		gameOver = true;
	}
	else if (y == 0 || y == height) {
		gameOver = true;
	}
	if (x == fruitX && y == fruitY)
	{
		fruitX = rand() % (width - 1) + 1;
		fruitY = rand() % (height - 1) + 1;
		bodyLength += 1;
		bodyX[bodyLength] = bodyX[bodyLength-1];
		bodyY[bodyLength] = bodyY[bodyLength-1];
		score += 1;
	}

}
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Sleep(100);
		Input();
		Logic();
		

	}
	return 0;
}
