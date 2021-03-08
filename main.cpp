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
bool bodyCreated = false;

void Setup()
{
	// Draw the game and set the position of the 
	// Fruit randomly and the Snake in the middle
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	bodyLength = 0;
	bodyX[0] = x+1;
	bodyY[0] = y;
	fruitX = rand() % (width - 1) + 1;
	fruitY = rand() % (height - 1) + 1;
	score = 0;
}

void cls() {
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

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
			bodyCreated = false;
			for (int k = 0; k < maxBody; k++) {
				if (bodyX[k] == NULL) {
					break;
				}
				else if (bodyX[k] == j && bodyY[k] == i) {
					std::cout << "S";
					bodyCreated = true;
				}
			}
			if (j == 0) {
				std::cout << "#";
			}
			else if (i == y && j == x) {
				std::cout << "S";
			}
			else if (i == fruitY && j == fruitX) {
				std::cout << "F";
			}
			else if (bodyCreated != true) {
					std::cout << " ";			
			}
			if (j == width - 1)
				std::cout << "#" << std::endl;
		}
	}
	for (int i = 0; i < width + 1; i++)
		std::cout << "#";
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
		if (dir == DOWN) {
			dir = DOWN;
		}
		else {
			dir = UP;
		}
	}
	else if (A != 0) {
		if (dir == RIGHT) {
			dir = RIGHT;
		}
		else {
			dir = LEFT;
		}
	}
	else if (S != 0) {
		if (dir == UP) {
			dir = UP;
		}
		else {
			dir = DOWN;
		}
	}
	else if (D != 0) {
		if (dir == LEFT) {
			dir = LEFT;
		}
		else {
			dir = RIGHT;
		}
	}

}
void UpdateBody()
{
	// Update the position of each body to its predecessors 
	// position creating a tail. Stopping the update process
	// if we reach the end of the tail.

	int tempX;
	int tempXX;
	int tempY;
	int tempYY;

	for (int i = 0; i < maxBody; i++) {
		if (bodyX[i] == NULL) {
			break;
		}
		else if (i == 0) {
			tempX = bodyX[i];
			tempY = bodyY[i];
			bodyX[i] = x;
			bodyY[i] = y;
		}
		else {
			tempXX = bodyX[i];
			bodyX[i] = tempX;
			tempYY = bodyY[i];
			bodyY[i] = tempY;
			tempX = tempXX;
			tempY = tempYY;
		}
	}
}
void Logic()
{
	if (x == fruitX && y == fruitY)
	{
		fruitX = rand() % (width - 1) + 1;
		fruitY = rand() % (height - 1) + 1;
		bodyLength += 1;
		bodyX[bodyLength] = bodyX[bodyLength - 1];
		bodyY[bodyLength] = bodyY[bodyLength - 1];
		score += 1;
	}
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
	for (int i = 0; i < maxBody; i++) {
		if (bodyX[i] == NULL) {
			break;
		}
		else if (x == bodyX[i] && y == bodyY[i]) {
			gameOver = true;
		}
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
