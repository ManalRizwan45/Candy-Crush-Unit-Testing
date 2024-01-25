#include<Windows.h>
#include <iostream>
#include<sstream>
#include "variables.h"

using namespace std;
//const int row = 9, column = 9;
//int scoreGrid[row][column] = { 1 };
//int x1 = -1, Y1 = -1, x2 = -1, y2 = -1;
//int turns = 1;
////int save = 0;
//int points = 0;

class GridManipulator {
public:
	//Ibrahim
	void shift(int grid[row][column]);
	void wrappedPlusStriped(int grid[row][column], int a1, int b1, int a2, int b2);
	void eliminatethreeBythree(int grid[row][column], int k, int l);
	void swap(int grid[][column], int a1, int b1, int a2, int b2);
	void zero(float& x, float& y);
	void input(int& mousex, int& mousey, int& save);
	void yellow_horizontal(float &x, float &y);

	//Manal
	void eliminatewrappedcandy(int grid[row][column]);
	void wrappedcandy(int grid[][column]);
	void candybomb(int grid[][column]);
	void simplythree(int grid[][column]);
	void highlight(int& x, int& y);
	void candy_bomb(float& x, float& y);
	void yellow_vertical(float& x, float& y);

	//Wardah
	void stripedcandies(int grid[][column]);
	int initialMatchCheck(int grid[row][column]);
	void initialize(int grid[row][column]);
	void eliminatecolorbomb(int grid[row][column], int x1, int Y1, int x2, int y2);
	void eliminateWrappedPlusWrapped(int grid[row][column], int a1, int b1, int a2, int b2);
	void square_candy_vertical(float &x, float &y);

	//Extra funcitons being called within functions
	void copyOfGrid(int scoreGrid[][column], int grid[row][column]);
	void score(int scoreGrid[][column], int grid[][column]);
	void display(int grid[row][column]);
};
//Ibrahim
void GridManipulator::shift(int grid[row][column])
{
	int x = 0;
	while (x < 82)
	{
		for (int j = column - 1; j >= 0; j--)
		{
			for (int i = row - 1; i >= 0; i--)
			{
				if (grid[i][j] == -3)
				{
					if (i == 0)
						grid[i][j] = -1;
					else
					{
						if (grid[i - 1][j] != -3 || grid[i - 1][j] == -1)
						{
							grid[i][j] = grid[i - 1][j];
							grid[i - 1][j] = -3;
						}
					}
				}
			}
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (grid[i][j] != 0)
				{
					x++;
				}
				else if (grid[i][j] == -3)
				{
					x = 0;
				}
			}
		}
	}
	cout << "Grid After Shift Function" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
};
void GridManipulator::wrappedPlusStriped(int grid[row][column], int a1, int b1, int a2, int b2)
{

	int x = grid[a1][b1];

	if (x % 11 == 0)
		x = 11; //Red
	else if (x % 17 == 0)
		x = 17;  //Yellow
	else if (x % 19 == 0)
		x = 19;  //Green
	else if (x % 7 == 0)
		x = 7;  //Blue
	else if (x % 13 == 0)
		x = 13;  //Orange

	int y = grid[a2][b2];
	if (y % 11 == 0)
		y = 11; //Red
	else if (y % 17 == 0)
		y = 17;  //Yellow
	else if (y % 19 == 0)
		y = 19;  //Green
	else if (y % 7 == 0)
		y = 7;  //Blue
	else if (y % 13 == 0)
		y = 13;  //Orange

	if (grid[a1][b1] / x == 2 || grid[a1][b1] / x == 3)
	{
		if (grid[a2][b2] / y == 4)
		{
			for (int k = 0; k < column; k++)
			{
				grid[k][b2] = -3;
				if (b2 + 1 < column)
					grid[k][b2 + 1] = -3;
				if (b2 - 1 >= 0)
					grid[k][b2 - 1] = -3;
			}
			for (int k = 0; k < row; k++)
			{
				grid[a2][k] = -3;
				if (a1 + 1 < row)
					grid[a2 + 1][k] = -3;
				if (a1 - 1 >= 0)
					grid[a2 - 1][k] = -3;
			}
		}
	}
	else if (grid[a2][b2] / y == 3 || grid[a2][b2] / y == 2)
	{
		if (grid[a1][b1] / x == 4)
		{
			for (int k = 0; k < column; k++)
			{
				grid[k][b1] = -3;
				if (b1 + 1 < column)
					grid[k][b1 + 1] = -3;
				if (b1 - 1 >= 0)
					grid[k][b1 - 1] = -3;
			}
			for (int k = 0; k < row; k++)
			{
				grid[a1][k] = -3;
				if (a1 + 1 < row)
					grid[a1 + 1][k] = -3;
				if (a1 - 1 >= 0)
					grid[a1 - 1][k] = -3;
			}
		}
	}
	cout << "Grid After wrapped plus striped" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

}
void GridManipulator::eliminatethreeBythree(int grid[row][column], int k, int l)
{
	if (k == 0 && l == 0) //top left corner
	{
		grid[k][l] = -3;
		grid[k][l + 1] = -3;
		grid[k + 1][l] = -3;
		grid[k + 1][l + 1] = -3;
	}
	else if (k == 8 && l == 0) //bottom left corner
	{
		grid[k][l] = -3;
		grid[k][l + 1] = -3;
		grid[k - 1][l] = -3;
		grid[k - 1][l + 1] = -3;
	}
	else if (k == 0 && l == 8) //top rkght corner
	{
		grid[k][l] = -3;
		grid[k][l - 1] = -3;
		grid[k + 1][l] = -3;
		grid[k + 1][l - 1] = -3;
	}
	else if (k == 8 && l == 8) //bottom rkght corner
	{
		grid[k][l] = -3;
		grid[k - 1][l] = -3;
		grid[k][l - 1] = -3;
		grid[k - 1][l - 1] = -3;
	}
	else if (k == 0 && (l > 0 && l < 8)) //top row
	{
		grid[k][l] = -3;
		grid[k][l + 1] = -3;
		grid[k][l - 1] = -3;
		grid[k + 1][l] = -3;
		grid[k + 1][l + 1] = -3;
		grid[k + 1][l - 1] = -3;
	}
	else if (k == 8 && (l > 0 && l < 8)) //bottom row
	{
		grid[k][l] = -3;
		grid[k - 1][l] = -3;
		grid[k - 1][l + 1] = -3;
		grid[k - 1][l - 1] = -3;
		grid[k][l - 1] = -3;
		grid[k][l + 1] = -3;
	}
	else if ((k > 0 && k < 8) && l == 0) // first column
	{
		grid[k][l] = -3;
		grid[k][l + 1] = -3;
		grid[k + 1][l + 1] = -3;
		grid[k - 1][l + 1] = -3;
		grid[k - 1][l] = -3;
		grid[k + 1][l] = -3;
	}
	else if ((k > 0 && k < 8) && l == 8) //last column
	{
		grid[k][l] = -3;
		grid[k - 1][l] = -3;
		grid[k + 1][l] = -3;
		grid[k][l - 1] = -3;
		grid[k - 1][l - 1] = -3;
		grid[k + 1][l - 1] = -3;
	}
	else if ((k > 0 && k < 8) && (l > 0 && l < 8)) //middle
	{
		grid[k][l] = -3;
		grid[k - 1][l] = -3;
		grid[k + 1][l] = -3;
		grid[k][l + 1] = -3;
		grid[k][l - 1] = -3;
		grid[k - 1][l + 1] = -3;
		grid[k - 1][l - 1] = -3;
		grid[k + 1][l + 1] = -3;
		grid[k + 1][l - 1] = -3;
	}
	cout << "Grid after eliminate three by three" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
void GridManipulator::swap(int grid[][column], int a1, int b1, int a2, int b2)
{
	if (a1 != -1 && b1 != -1 && a2 != -1 && b2 != -1)
	{
		if ((a2 == a1 + 1 && b2 == b1) || (a2 == a1 - 1 && b2 == b1) || (a2 == a1 && b2 == b1 + 1) || (a2 == a1 && b2 == b1 - 1))
		{
			int temp = grid[a1][b1];
			grid[a1][b1] = grid[a2][b2];
			grid[a2][b2] = temp;
			eliminatecolorbomb(grid, a1, b1, a2, b2);
			score(scoreGrid, grid);
			copyOfGrid(scoreGrid, grid);

			wrappedPlusStriped(grid, a1, b1, a2, b2);
			score(scoreGrid, grid);
			copyOfGrid(scoreGrid, grid);

			eliminateWrappedPlusWrapped(grid, a1, b1, a2, b2);
			score(scoreGrid, grid);
			copyOfGrid(scoreGrid, grid);

			x1 = -1;
			Y1 = -1;
			x2 = -1;
			y2 = -1;
			turns--;
		}
		else
		{
			x1 = -1;
			Y1 = -1;
			x2 = -1;
			y2 = -1;
		}
	}
	cout << endl;
	cout << "Grid after swap" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
void GridManipulator::zero(float& x, float& y) {

	//sf::RectangleShape line1(sf::Vector2f(90, 5));
	//sf::RectangleShape line2(sf::Vector2f(90, 5));


	//line1.rotate(45);
	//line2.rotate(135);
	if (y == 0)
		y = 110;
	else
		y = (y * 100) + 110;
	if (x == 0)
		x = 105;
	else
		x = (x * 100) + 105;
	cout << "Values of X and Y after Zero" << endl;
	cout << "x:" << x << endl;
	cout << "y:" << y << endl;
	/*line1.setPosition(y + 10, x + 12);
	line2.setPosition(y + 75, x + 17);
	cout << "Line 1 Position: (" << line1.getPosition().x << ", " << line1.getPosition().y << ")" << endl;
	cout << "Line 2 Position: (" << line2.getPosition().x << ", " << line2.getPosition().y << ")" << endl;
	window.draw(line1);
	window.draw(line2);*/
}
void GridManipulator::input(int& mousex, int& mousey, int& save) {
	/*sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");*/
	if ((TRUE))
	{
		/*mousey = sf::Mouse::getPosition(window).x;
		mousex = sf::Mouse::getPosition(window).y;*/
		if (mousex > 900 && mousex < 992 && mousey>1300 && mousey < 1700)
		{
			save = 1;
		}
		mousex = (mousex / 100) - 1;
		mousey = (mousey / 100) - 1;
		if (mousex > 8 || mousey > 8)
		{
			mousex = -1;
			mousey = -1;
		}
		if (mousex < 0 || mousey < 0)
		{
			mousex = -1;
			mousey = -1;
		}

		cout << "Values after Input" << endl;
		cout << "Save:" << save << endl;
		cout << "mousex:" << mousex << endl;
		cout << "mousey:" << mousey << endl;


		Sleep(500);

	}
}
void GridManipulator::yellow_horizontal(float &x, float &y) {
	//sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
	//sf::CircleShape yellow(40, 3);
	//yellow.setFillColor(sf::Color::Yellow);

	if (y == 0)
		y = 110;
	else
		y = (y * 100) + 110;
	if (x == 0)
		x = 115;
	else
		x = (x * 100) + 115;
	//yellow.setPosition(y, x);
	//window.draw(yellow);
	/*int j = 0;
	for (int i = 0; i < 50; i = i + 10)
	{

		sf::RectangleShape horizontal(sf::Vector2f(50 - i, 4));
		horizontal.setPosition(y + 15 + j, x + 50 - i);
		window.draw(horizontal);
		j = j + 5;
	}*/
}

//Manal
void GridManipulator::eliminatewrappedcandy(int grid[row][column])
{
	int pak40 = 11;
	for (int pak38 = 0; pak38 < 5; pak38++) {
		if (pak38 == 0) {
			pak40 = 11;
		}
		else if (pak38 == 1) {
			pak40 = 17;
		}
		else if (pak38 == 2) {
			pak40 = 19;
		}
		else if (pak38 == 3) {
			pak40 = 7;
		}
		else if (pak38 == 4) {
			pak40 = 13;
		}
		//vertical top left corner OK
		if (((grid[0][0] % pak40 == grid[1][0] % pak40) && (grid[1][0] % pak40 == grid[2][0] % pak40) && (grid[0][0] % pak40 == grid[2][0] % pak40))) {
			if (grid[0][0] / pak40 == 4) {
				grid[0][0] = -3;
				grid[1][0] = -3;
				grid[2][0] = -3;
				grid[0][1] = -3;
				grid[1][1] = -3;
			}
		}
		//horizontal top left corner OK
		if (((grid[0][0] % pak40 == grid[0][1] % pak40) && (grid[0][1] % pak40 == grid[0][2] % pak40) && (grid[0][0] % pak40 == grid[0][2] % pak40))) {
			if (grid[0][0] / pak40 == 4) {
				grid[0][0] = -3;
				grid[0][1] = -3;
				grid[1][0] = -3;
				grid[1][1] = -3;
				grid[0][2] = -3;

			}
		}
		//vertical top right corner OK
		if (((grid[0][8] % pak40 == grid[1][8] % pak40) && (grid[1][8] % pak40 == grid[2][8] % pak40) && (grid[0][8] % pak40 == grid[2][8] % pak40))) {
			if (grid[0][8] / pak40 == 4) {
				grid[0][8] = -3;
				grid[1][8] = -3;
				grid[2][8] = -3;
				grid[0][7] = -3;
				grid[1][7] = -3;
			}
		}
		//horizontal top right corner OK
		if (((grid[0][8] % pak40 == grid[0][7] % pak40) && (grid[0][7] % pak40 == grid[0][6] % pak40) && (grid[0][6] % pak40 == grid[0][8] % pak40))) {
			if (grid[0][8] / pak40 == 4) {
				grid[0][8] = -3;
				grid[0][7] = -3;
				grid[0][6] = -3;
				grid[1][8] = -3;
				grid[1][7] = -3;
			}
		}
		//vertical bottom left corner OK
		if (((grid[8][0] % pak40 == grid[7][0] % pak40) && (grid[7][0] % pak40 == grid[6][0] % pak40) && (grid[8][0] % pak40 == grid[6][0] % pak40))) {
			if (grid[8][0] / pak40 == 4) {
				grid[8][0] = -3;
				grid[7][0] = -3;
				grid[6][0] = -3;
				grid[8][1] = -3;
				grid[7][1] = -3;
			}
		}
		//horizontal bottom left corner OK
		if (((grid[8][0] % pak40 == grid[8][1] % pak40) && (grid[8][1] % pak40 == grid[8][2] % pak40) && (grid[8][2] % pak40 == grid[8][0] % pak40))) {
			if (grid[8][0] / pak40 == 4) {
				grid[8][0] = -3;
				grid[8][1] = -3;
				grid[8][2] = -3;
				grid[7][0] = -3;
				grid[7][1] = -3;
			}
		}
		//vertical bottom right corner OK
		if (((grid[8][8] % pak40 == grid[7][8] % pak40) && (grid[7][8] % pak40 == grid[6][8] % pak40) && (grid[8][8] % pak40 == grid[6][8] % pak40))) {
			if (grid[8][8] / pak40 == 4) {
				grid[7][8] = -3;
				grid[6][8] = -3;
				grid[8][8] = -3;
				grid[8][7] = -3;
				grid[7][7] = -3;
			}
		}
		//horizontal bottom right corner OK
		if (((grid[8][8] % pak40 == grid[8][7] % pak40) && (grid[8][7] % pak40 == grid[8][6] % pak40) && (grid[8][6] % pak40 == grid[8][8] % pak40))) {
			if (grid[8][8] / pak40 == 4) {
				grid[8][8] = -3;
				grid[8][7] = -3;
				grid[8][6] = -3;
				grid[7][8] = -3;
				grid[7][7] = -3;
			}
		}


		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column - 1; j++)
			{
				// for pak40
				if (((grid[i][j] % pak40 == grid[i + 1][j] % pak40) && (grid[i + 1][j] % pak40 == grid[i + 2][j] % pak40) && (grid[i][j] % pak40 == grid[i + 2][j] % pak40)))
				{//clearing 3x3 grid with wrapped candy as point of origin if it is not on boundary
					if (i < 9 && i>-1) {


						if (grid[i + 1][j] / pak40 == 4) {

							if ((i + 1 > -1) && (i + 1 < 9)) {
								grid[i + 1][j] = -3;
								if ((j + 1 > -1) && (j + 1 < 9)) {
									grid[i + 1][j + 1] = -3;
								}
								if ((j - 1 > -1) && (j - 1 < 9)) {
									grid[i + 1][j - 1] = -3;
								}
							}

							grid[i][j] = -3;
							if ((j + 1 > -1) && (j + 1 < 9)) {
								grid[i][j + 1] = -3;
							}
							if ((j - 1 > -1) && (j - 1 < 9)) {
								grid[i][j - 1] = -3;
							}

							if ((i + 2 > -1) && (i + 2 < 9)) {
								grid[i + 2][j] = -3;
								if ((j + 1 > -1) && (j + 1 < 9)) {
									grid[i + 2][j + 1] = -3;
								}
								if ((j - 1 > -1) && (j - 1 < 9)) {
									grid[i + 2][j - 1] = -3;
								}
							}


						}
						else if (grid[i][j] / pak40 == 4) {

							if ((i + 1 > -1) && (i + 1 < 9)) {
								grid[i + 1][j] = -3;
								if ((j + 1 > -1) && (j + 1 < 9)) {
									grid[i + 1][j + 1] = -3;
								}
								if ((j - 1 > -1) && (j - 1 < 9)) {
									grid[i + 1][j - 1] = -3;
								}
							}

							grid[i][j] = -3;
							if ((j + 1 > -1) && (j + 1 < 9)) {
								grid[i][j + 1] = -3;
							}
							if ((j - 1 > -1) && (j - 1 < 9)) {
								grid[i][j - 1] = -3;
							}

							if ((i - 1 > -1) && (i - 1 < 9)) {
								grid[i - 1][j] = -3;
								if ((j + 1 > -1) && (j + 1 < 9)) {
									grid[i - 1][j + 1] = -3;
								}
								if ((j - 1 > -1) && (j - 1 < 9)) {
									grid[i - 1][j - 1] = -3;
								}
							}
						}

						else if (grid[i + 2][j] / pak40 == 4) {
							if ((i + 1 > -1) && (i + 1 < 9)) {
								grid[i + 1][j] = -3;
								if ((j + 1 > -1) && (j + 1 < 9)) {
									grid[i + 1][j + 1] = -3;
								}
								if ((j - 1 > -1) && (j - 1 < 9)) {
									grid[i + 1][j - 1] = -3;
								}
							}
							if ((i + 2 > -1) && (i + 2 < 9)) {
								grid[i + 2][j] = -3;
								if ((j + 1 > -1) && (j + 1 < 9)) {
									grid[i + 2][j + 1] = -3;
								}
								if ((j - 1 > -1) && (j - 1 < 9)) {
									grid[i + 2][j - 1] = -3;
								}
							}
							if ((i + 3 > -1) && (i + 3 < 9)) {
								grid[i + 3][j] = -3;
								if ((j + 1 > -1) && (j + 1 < 9)) {
									grid[i + 3][j + 1] = -3;
								}
								if ((j - 1 > -1) && (j - 1 < 9)) {
									grid[i + 3][j - 1] = -3;
								}
							}
						}
					}
				}
			}

		}

		for (int j = 0; j < column - 2; j++) {

			for (int i = 0; i < row; i++) {
				if ((grid[i][j] % pak40 == grid[i][j + 1] % pak40) && (grid[i][j + 1] % pak40 == grid[i][j + 2] % pak40) && (grid[i][j] % pak40 == grid[i][j + 2] % pak40)) {
					if (j > -1 && j < 9) {


						if (grid[i][j] / pak40 == 4) {

							grid[i][j] = -3;
							if ((j + 1 > -1) && (j + 1 < 9)) {
								grid[i][j + 1] = -3;
							}
							if ((j - 1 > -1) && (j - 1 < 9)) {
								grid[i][j - 1] = -3;
							}
							if ((i + 1 > -1) && (i + 1 < 9)) {
								grid[i + 1][j] = -3;
								if ((j + 1 > -1) && (j + 1 < 9)) {
									grid[i + 1][j + 1] = -3;
								}
								if ((j - 1 > -1) && (j - 1 < 9)) {
									grid[i + 1][j - 1] = -3;
								}
							}
							if ((i - 1 > -1) && (i - 1 < 9)) {
								grid[i - 1][j] = -3;
								if ((j + 1 > -1) && (j + 1 < 9)) {
									grid[i - 1][j + 1] = -3;
								}
								if ((j - 1 > -1) && (j - 1 < 9)) {
									grid[i - 1][j - 1] = -3;
								}
							}

						}
						else if (grid[i][j + 1] / pak40 == 4) {
							if (j + 1 < 9) {

								grid[i][j] = -3;
								grid[i][j + 1] = -3;
								if (j + 2 < 9) {
									grid[i][j + 2] = -3;
								}
								if ((i + 1) < 9) {
									grid[i + 1][j] = -3;
									if (j + 1 < 9) {
										grid[i + 1][j + 1] = -3;
									}
									if (j + 2 < 9) {
										grid[i + 1][j + 2] = -3;
									}
								}
								if ((i - 1) > -1) {
									grid[i - 1][j] = -3;
									if (j + 1 < 9) {
										grid[i + 1][j + 1] = -3;
									}
									if (j + 2 < 9) {
										grid[i + 1][j + 2] = -3;
									}
								}
							}

						}
						else if (grid[i][j + 2] / pak40 == 4) {

							grid[i][j] = -3;
							if (j + 1 < 9) {
								grid[i][j + 1] = -3;
							}
							if (j + 2 < 9) {
								grid[i][j + 2] = -3;
							}
							if (j + 3 < 9) {
								grid[i][j + 3] = -3;
							}
							if (i + 1 < 9) {
								if (j + 1 < 9) {
									grid[i + 1][j + 1] = -3;
								}
								if (j + 2 < 9) {
									grid[i + 1][j + 2] = -3;
								}
								if (j + 3 < 9) {
									grid[i + 1][j + 3] = -3;
								}
							}
							if (i - 1 > -1) {
								if (j + 1 < 9) {
									grid[i - 1][j + 1] = -3;
								}
								if (j + 2 < 9) {
									grid[i - 1][j + 2] = -3;
								}
								if (j + 3 < 9) {
									grid[i - 1][j + 3] = -3;
								}
							}
						}
					}
				}
			}
		}

	}
	//display(grid);
}
void GridManipulator::wrappedcandy(int grid[][column]) //checks for formation of wrapped candy and forms it
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			int  w = grid[i][j]; //wrapped candy being formed
			if (w % 11 == 0)
				w = 44; //Red wrapped candy
			else if (w % 17 == 0)
				w = 68;  //Yellow wrapped candy
			else if (w % 19 == 0)
				w = 76;  //Green wrapped candy
			else if (w % 7 == 0)
				w = 28;  //Blue wrapped candy
			else if (w % 13 == 0)
				w = 52;  //Orange wrapped candy 

			int x = grid[i][j];
			if (x % 11 == 0)
				x = 11; //Red wrapped candy
			else if (x % 17 == 0)
				x = 17;  //Yellow wrapped candy
			else if (x % 19 == 0)
				x = 19;  //Green wrapped candy
			else if (x % 7 == 0)
				x = 7;  //Blue wrapped candy
			else if (x % 13 == 0)
				x = 13;  //Orange wrapped candy   

			if (grid[i][j] % x == grid[i][j + 1] % x && grid[i][j + 1] % x == grid[i][j + 2] % x && grid[i][j + 2] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x)
			{
				if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++) //vertical stripe elimination
					{
						grid[k][j] = -3;
					}
				}

				if (grid[i][j + 1] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j + 1] = -3;
					}
				}

				if (grid[i][j + 2] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j + 2] = -3;
					}
				}

				if (grid[i][j] / x == 2 || grid[i][j + 1] / x == 2 || grid[i][j + 2] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i][k] = -3;
					}
				}

				if (grid[i + 1][j] / x == 2) //horizontal stripe elimination
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)
					{
						grid[i + 1][k] = -3;
					}
				}

				if (grid[i + 2][j] / x == 2)//horizontal stripe elimination
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)
					{
						grid[i + 2][k] = -3;
					}
				}
				eliminatewrappedcandy(grid);
				grid[i][j] = -3;                //    _ _
				grid[i][j + 1] = -3;            //  |
				grid[i][j + 2] = -3;            //  |   
				grid[i + 1][j] = -3;            //  |      shape
				grid[i + 2][j] = w;
			}

			if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x && grid[i + 2][j] % x == grid[i + 2][j + 1] % x && grid[i + 2][j + 1] % x == grid[i + 2][j + 2] % x)
			{

				if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j] = -3;
					}
				}
				if (grid[i + 2][j + 1] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j + 1] = -3;
					}
				}
				if (grid[i + 2][j + 2] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j + 2] = -3;
					}
				}
				if (grid[i][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i][k] = -3;
					}
				}
				if (grid[i + 1][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 1][k] = -3;
					}
				}
				if (grid[i + 2][j] / x == 2 || grid[i + 2][j + 1] / x == 2 || grid[i + 2][j + 2] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 2][k] = -3;
					}
				}
				eliminatewrappedcandy(grid);
				grid[i][j] = -3;
				grid[i + 1][j] = -3;
				grid[i + 2][j] = w;                        //  |
				grid[i + 2][j + 1] = -3;                   //  |
				grid[i + 2][j + 2] = -3;                   //  | _ _  shape
			}

			if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x && grid[i + 2][j] % x == grid[i + 1][j + 1] % x && grid[i + 1][j + 1] % x == grid[i + 1][j + 2] % x)
			{

				if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j] = -3;
					}
				}
				if (grid[i + 2][j + 1] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j + 1] = -3;
					}
				}
				if (grid[i + 2][j + 2] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j + 2] = -3;
					}
				}
				if (grid[i][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i][k] = -3;
					}
				}
				if (grid[i + 1][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 1][k] = -3;
					}
				}
				if (grid[i + 2][j] / x == 2 || grid[i + 2][j + 1] / x == 2 || grid[i + 2][j + 2] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 2][k] = -3;
					}
				}
				eliminatewrappedcandy(grid);
				grid[i][j] = -3;
				grid[i + 1][j] = -3;
				grid[i + 2][j] = w;                        //  |  
				grid[i + 1][j + 1] = -3;                   //  | - -
				grid[i + 1][j + 2] = -3;                   //  |      shape
			}

		}
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = column - 1; j > 1; j--)
		{
			int  w = grid[i][j];
			if (w % 11 == 0)
				w = 44; //Red wrapped candy
			else if (w % 17 == 0)
				w = 68;  //Yellow wrapped candy
			else if (w % 19 == 0)
				w = 76;  //Green wrapped candy
			else if (w % 7 == 0)
				w = 28;  //Blue wrapped candy
			else if (w % 13 == 0)
				w = 52;  //Orange wrapped candy

			int x = grid[i][j];
			if (x % 11 == 0)
				x = 11; //Red wrapped candy
			else if (x % 17 == 0)
				x = 17;  //Yellow wrapped candy
			else if (x % 19 == 0)
				x = 19;  //Green wrapped candy
			else if (x % 7 == 0)
				x = 7;  //Blue wrapped candy
			else if (x % 13 == 0)
				x = 13;  //Orange wrapped candy   


			if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x && grid[i + 2][j] % x == grid[i][j - 1] % x && grid[i][j - 1] % x == grid[i][j - 2] % x)
			{

				if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j] = -3;
					}
				}
				if (grid[i][j - 1] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j - 1] = -3;
					}
				}
				if (grid[i][j - 2] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j - 2] = -3;
					}
				}
				if (grid[i][j] / x == 2 || grid[i][j - 1] / x == 2 || grid[i][j - 2] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i][k] = -3;
					}
				}
				if (grid[i + 1][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 1][k] = -3;
					}
				}
				if (grid[i + 2][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 2][k] = -3;
					}
				}
				eliminatewrappedcandy(grid);
				grid[i][j] = -3;
				grid[i + 1][j] = -3;                        //  _ _  
				grid[i + 2][j] = w;                         //      |
				grid[i][j - 1] = -3;                        //      |
				grid[i][j - 2] = -3;                        //      |  shape
			}

			if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x && grid[i + 2][j] % x == grid[i + 2][j - 1] % x && grid[i + 2][j - 1] % x == grid[i + 2][j - 2] % x)
			{

				if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j] = -3;
					}
				}
				if (grid[i + 2][j - 1] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j - 1] = -3;
					}
				}
				if (grid[i + 2][j - 2] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j - 2] = -3;
					}
				}
				if (grid[i][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i][k] = -3;
					}
				}
				if (grid[i + 1][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 1][k] = -3;
					}
				}
				if (grid[i + 2][j] / x == 2 || grid[i + 2][j - 1] / x == 2 || grid[i + 2][j - 2] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 2][k] = -3;
					}
				}
				eliminatewrappedcandy(grid);
				grid[i][j] = -3;
				grid[i + 1][j] = -3;             //     |
				grid[i + 2][j] = w;              //     |
				grid[i + 2][j - 1] = -3;         // _ _ |  shape
				grid[i + 2][j - 2] = -3;
			}

			if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x && grid[i + 2][j] % x == grid[i + 1][j - 1] % x && grid[i + 1][j - 1] % x == grid[i + 1][j - 2] % x)
			{

				if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j] = -3;
					}
				}

				if (grid[i + 1][j - 1] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j - 1] = -3;
					}
				}

				if (grid[i + 1][j - 3] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j - 2] = -3;
					}
				}
				if (grid[i][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i][k] = -3;
					}
				}

				if (grid[i + 1][j] / x == 2 || grid[i + 1][j - 1] / x == 2 || grid[i + 1][j - 2] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 1][k] = -3;
					}
				}

				if (grid[i + 2][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 2][k] = -3;
					}
				}
				eliminatewrappedcandy(grid);
				grid[i][j] = -3;
				grid[i + 1][j] = -3;
				grid[i + 2][j] = w;                         //      |  
				grid[i + 1][j - 1] = -3;                    //  - - | 
				grid[i + 1][j - 2] = -3;                    //      |   shape
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 1; j < column - 2; j++)
		{
			int  w = grid[i][j];
			if (w % 11 == 0)
				w = 44; //Red wrapped candy
			else if (w % 17 == 0)
				w = 68;  //Yellow wrapped candy
			else if (w % 19 == 0)
				w = 76;  //Green wrapped candy
			else if (w % 7 == 0)
				w = 28;  //Blue wrapped candy
			else if (w % 13 == 0)
				w = 52;  //Orange wrapped candy

			int x = grid[i][j];
			if (x % 11 == 0)
				x = 11; //Red wrapped candy
			else if (x % 17 == 0)
				x = 17;  //Yellow wrapped candy
			else if (x % 19 == 0)
				x = 19;  //Green wrapped candy
			else if (x % 7 == 0)
				x = 7;  //Blue wrapped candy
			else if (x % 13 == 0)
				x = 13;  //Orange wrapped candy   

			if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x && grid[i + 2][j] % x == grid[i + 2][j - 1] % x && grid[i + 2][j - 1] % x == grid[i + 2][j + 1] % x)
			{
				if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j] = -3;
					}
				}
				if (grid[i + 2][j - 1] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j - 1] = -3;
					}
				}
				if (grid[i + 2][j + 1] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j + 1] = -3;
					}
				}
				if (grid[i][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i][k] = -3;
					}
				}
				if (grid[i + 1][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 1][k] = -3;
					}
				}
				if (grid[i + 2][j] / x == 2 || grid[i + 2][j - 1] / x == 2 || grid[i + 2][j + 1] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 2][k] = -3;
					}
				}
				eliminatewrappedcandy(grid);
				grid[i][j] = -3;
				grid[i + 1][j] = -3;
				grid[i + 2][j] = w;                         //      |  
				grid[i + 2][j - 1] = -3;                    //      | 
				grid[i + 2][j + 1] = -3;                    //    _ | _  shape
			}

			if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x && grid[i + 2][j] % x == grid[i][j - 1] % x && grid[i][j - 1] % x == grid[i][j + 1] % x)
			{

				if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j] = -3;
					}
				}
				if (grid[i][j - 1] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j - 1] = -3;
					}
				}
				if (grid[i][j + 1] / x == 3)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < row; k++)  //vertical stripe elimination
					{
						grid[k][j + 1] = -3;
					}
				}
				if (grid[i][j] / x == 2 || grid[i][j - 1] / x == 2 || grid[i][j + 1] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i][k] = -3;
					}
				}
				if (grid[i + 1][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 1][k] = -3;
					}
				}
				if (grid[i + 2][j] / x == 2)
				{
					eliminatewrappedcandy(grid);
					for (int k = 0; k < column; k++)  //horizontal stripe elimination
					{
						grid[i + 2][k] = -3;
					}
				}
				eliminatewrappedcandy(grid);
				grid[i][j] = -3;
				grid[i + 1][j] = -3;                        //    _   _
				grid[i + 2][j] = w;                         //      |  
				grid[i][j - 1] = -3;                        //      | 
				grid[i][j + 1] = -3;                        //      |    shape
			}
		}
	}
	//display(grid);
}
void GridManipulator::candybomb(int grid[][column])
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int x = grid[i][j];
			if (x % 11 == 0)
				x = 11; //Red candy
			else if (x % 17 == 0)
				x = 17;  //Yellow candy
			else if (x % 19 == 0)
				x = 19;  //Green candy
			else if (x % 7 == 0)
				x = 7;  //Blue candy
			else if (x % 13 == 0)
				x = 13;  //Orange candy 

			if (grid[i][j] % x == grid[i][j + 1] % x && grid[i][j + 1] % x == grid[i][j + 2] % x && grid[i][j + 2] % x == grid[i][j + 3] % x && grid[i][j + 3] % x == grid[i][j + 4] % x)
			{
				if (grid[i][j] != -3)
				{
					if (grid[i][j] / x == 3)
					{
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j] = -3;
						}
					}
					if (grid[i][j + 1] / x == 3)
					{
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j + 1] = -3;
						}
					}
					if (grid[i][j + 2] / x == 3)
					{
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j + 2] = -3;
						}
					}
					if (grid[i][j + 3] / x == 3)
					{
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j + 3] = -3;
						}
					}
					if (grid[i][j + 4] / x == 3)
					{
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j + 4] = -3;
						}
					}
					if (grid[i][j] / x == 2 || grid[i][j + 1] / x == 2 || grid[i][j + 2] / x == 2 || grid[i][j + 3] / x == 2 || grid[i][j + 4] / x == 2)
					{
						for (int k = 0; k < column; k++)  //horizontal stripe elimination
						{
							grid[i][k] = -3;
						}
					}
					grid[i][j] = -3;
					grid[i][j + 1] = -3;
					grid[i][j + 2] = 999;
					grid[i][j + 3] = -3;
					grid[i][j + 4] = -3;
				}
			}
		}

		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				int x = grid[i][j];
				if (x % 11 == 0)
					x = 11; //Red 
				else if (x % 17 == 0)
					x = 17;  //Yellow 
				else if (x % 19 == 0)
					x = 19;  //Green
				else if (x % 7 == 0)
					x = 7;  //Blue
				else if (x % 13 == 0)
					x = 13;  //Orange
				if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x && grid[i + 2][j] % x == grid[i + 3][j] % x && grid[i + 3][j] % x == grid[i + 4][j] % x)
				{
					if (grid[i][j] != -3)
					{
						if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3 || grid[i + 3][j] / x == 3 || grid[i + 4][j] / x == 3)
						{
							for (int k = 0; k < row; k++)  //vertical stripe elimination
							{
								grid[k][j] = -3;
							}
						}
						if (grid[i][j] / x == 2)
						{
							for (int k = 0; k < column; k++)  //horizontal stripe elimination
							{
								grid[i][k] = -3;
							}
						}
						if (grid[i + 1][j] / x == 2)
						{
							for (int k = 0; k < column; k++)  //horizontal stripe elimination
							{
								grid[i + 1][k] = -3;
							}
						}
						if (grid[i + 2][j] / x == 2)
						{
							for (int k = 0; k < column; k++)  //horizontal stripe elimination
							{
								grid[i + 2][k] = -3;
							}
						}
						if (grid[i + 3][j] / x == 2)
						{
							for (int k = 0; k < column; k++)  //horizontal stripe elimination
							{
								grid[i + 3][k] = -3;
							}
						}
						if (grid[i + 4][j] / x == 2)
						{
							for (int k = 0; k < column; k++)  //horizontal stripe elimination
							{
								grid[i + 4][k] = -3;
							}
						}
						grid[i][j] = -3;
						grid[i + 1][j] = -3;
						grid[i + 2][j] = 999;
						grid[i + 3][j] = -3;
						grid[i + 4][j] = -3;

					}
				}
			}
		}
	}
	//display(grid);
}
void GridManipulator::simplythree(int grid[][column])
{
	//horizontal check for all same type of candies
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			int x = grid[i][j];
			if (x % 11 == 0)
				x = 11; //Red
			else if (x % 17 == 0)
				x = 17;  //Yellow
			else if (x % 19 == 0)
				x = 19;  //Green
			else if (x % 7 == 0)
				x = 7;  //Blue
			else if (x % 13 == 0)
				x = 13;  //Orange


			if (grid[i][j] % x == grid[i][j + 1] % x && grid[i][j + 1] % x == grid[i][j + 2] % x)
			{
				if (grid[i][j] != -3)
				{
					if (grid[i][j] / x == 3)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j] = -3;
						}
					}
					if (grid[i][j + 1] / x == 3)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j + 1] = -3;
						}
					}
					if (grid[i][j + 2] / x == 3)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j + 2] = -3;
						}
					}
					if (grid[i][j] / x == 2 || grid[i][j + 1] / x == 2 || grid[i][j + 2] / x == 2)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < column; k++)  //horizontal stripe elimination
						{
							grid[i][k] = -3;
						}
					}
					eliminatewrappedcandy(grid);
					grid[i][j] = -3;
					grid[i][j + 1] = -3;
					grid[i][j + 2] = -3;
				}
			}
		}
	}// horizontal end

	//vertical check of all same type of candies
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < column; j++)
		{
			int x = grid[i][j];
			if (x % 11 == 0)
				x = 11; //Red
			else if (x % 17 == 0)
				x = 17;  //Yellow
			else if (x % 19 == 0)
				x = 19;  //Green
			else if (x % 7 == 0)
				x = 7;  //Blue
			else if (x % 13 == 0)
				x = 13;  //Orange

			if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x)
			{
				if (grid[i][j] != -3)
				{
					if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j] = -3;
						}
					}
					if (grid[i][j] / x == 2)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < column; k++)  //horizontal stripe elimination
						{
							grid[i][k] = -3;
						}
					}
					if (grid[i + 1][j] / x == 2)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < column; k++)  //horizontal stripe elimination
						{
							grid[i + 1][k] = -3;
						}
					}
					if (grid[i + 2][j] / x == 2)
					{
						eliminatewrappedcandy(grid);

						for (int k = 0; k < column; k++)  //horizontal stripe elimination
						{
							grid[i + 2][k] = -3;
						}
					}
					eliminatewrappedcandy(grid);
					grid[i][j] = -3;
					grid[i + 1][j] = -3;
					grid[i + 2][j] = -3;
				}
			}
		}
	}
	//display(grid);
}
void GridManipulator::highlight(int& x, int& y)
{
	if (x != -1 && y != -1)
	{
		// sf::RectangleShape square(sf::Vector2f(80, 80));
		// square.setFillColor(sf::Color::Transparent);
		// square.setOutlineColor(sf::Color::White);
		// square.setOutlineThickness(3.0);
		x++;
		y++;
		x = x * 100 + 10;
		y = y * 100 + 10;
		// square.setPosition(y, x);
		// window.draw(square);
	}
}
void GridManipulator::candy_bomb(float& x, float& y)
{
	// sf::CircleShape shape(40.f);
	// shape.setFillColor(sf::Color::Red);
	// shape.setOutlineThickness(10);
	// shape.setOutlineColor(sf::Color::Blue);
	if (y == 0)
		y = 110;
	else
		y = (y * 100) + 110;
	if (x == 0)
		x = 110;
	else
		x = (x * 100) + 110;

	// shape.setPosition(y, x);
	// window.draw(shape);
	// sf::CircleShape shape2(5.0f);
	// shape2.setFillColor(sf::Color::Green);
	// shape2.setPosition(y + 50, x + 50);
	// window.draw(shape2);
	// sf::CircleShape shape3(5.0f);
	// shape3.setFillColor(sf::Color::Cyan);
	// shape3.setPosition(y + 35, x + 35);
	// window.draw(shape3);
	// sf::CircleShape shape4(5.0f);
	// shape4.setFillColor(sf::Color::White);
	// shape4.setPosition(y + 20, x + 20);
	// window.draw(shape4);
	// sf::CircleShape shape5(5.0f);
	// shape5.setFillColor(sf::Color::Yellow);
	// shape5.setPosition(y + 50, x + 20);
	// window.draw(shape5);
	// sf::CircleShape shape6(5.0f);
	// shape6.setFillColor(sf::Color::Yellow);
	// shape6.setPosition(y + 20, x + 50);
	// window.draw(shape6);

}
void GridManipulator::yellow_vertical(float& x, float& y)
{
	// sf::CircleShape yellow(40, 3);
	// yellow.setFillColor(sf::Color::Yellow);

	if (y == 0)
		y = 110;
	else
		y = (y * 100) + 110;
	if (x == 0)
		x = 115;
	else
		x = (x * 100) + 115;

	// yellow.setPosition(y, x);
	// window.draw(yellow);

	// int j = 0;
	// for (int i = 0; i < 20; i = i + 10)
	// {

		// sf::RectangleShape vertical(sf::Vector2f(40 + i, 4));
		// vertical.rotate(90);
		// vertical.setPosition(y + i + 30, x + 19 - j);
		// window.draw(vertical);

	// 	j = j + 9;
	// }
	// sf::RectangleShape vertical2(sf::Vector2f(40, 4));
	// vertical2.rotate(90);
	// vertical2.setPosition(y + 50, x + 19);
	// window.draw(vertical2);

}

//Wardah
void GridManipulator::stripedcandies(int grid[][column]) //checks for fomation of stripped candy and forms it
{
	//horizontal check for all same type of candies
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int  w = grid[i][j]; //h.striped candy being formed
			if (w % 11 == 0)
				w = 22; //Red h.striped candy
			else if (w % 17 == 0)
				w = 34;  //Yellow h.striped candy
			else if (w % 19 == 0)
				w = 38;  //Green h.striped candy
			else if (w % 7 == 0)
				w = 14;  //Blue h.striped candy
			else if (w % 13 == 0)
				w = 26;  //Orange h.striped candy 

			int x = grid[i][j];
			if (x % 11 == 0)
				x = 11; //Red
			else if (x % 17 == 0)
				x = 17;  //Yellow
			else if (x % 19 == 0)
				x = 19;  //Green
			else if (x % 7 == 0)
				x = 7;  //Blue
			else if (x % 13 == 0)
				x = 13;  //Orange  

			if (grid[i][j] % x == grid[i][j + 1] % x && grid[i][j + 1] % x == grid[i][j + 2] % x && grid[i][j + 2] % x == grid[i][j + 3] % x)
			{
				if (grid[i][j] != -3)
				{
					if (grid[i][j] / x == 3)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j] = -3;
						}
					}
					if (grid[i][j + 1] / x == 3)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j + 1] = -3;
						}
					}
					if (grid[i][j + 2] / x == 3)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j + 2] = -3;
						}
					}
					if (grid[i][j + 3] / x == 3)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j + 3] = -3;
						}
					}
					if (grid[i][j] / x == 2 || grid[i][j + 1] / x == 2 || grid[i][j + 2] / x == 2 || grid[i][j + 3] / x == 2)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < column; k++)  //horizontal stripe elimination
						{
							grid[i][k] = -3;
						}
					}
					eliminatewrappedcandy(grid);
					grid[i][j] = -3;
					grid[i][j + 1] = -3;
					grid[i][j + 2] = -3;
					grid[i][j + 3] = w;
				}
			}
		}
	}// horizontal end

	//vertical check of all same type of candies
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < column; j++)
		{
			int  w = grid[i][j];
			if (w % 11 == 0)
				w = 22; //Red v.striped candy
			else if (w % 17 == 0)
				w = 51;  //Yellow v.striped candy
			else if (w % 19 == 0)
				w = 57;  //Green v.striped candy
			else if (w % 7 == 0)
				w = 21;  //Blue v.striped candy
			else if (w % 13 == 0)
				w = 39;  //Orange v.striped candy

			int x = grid[i][j];
			if (x % 11 == 0)
				x = 11; //Red
			else if (x % 17 == 0)
				x = 17;  //Yellow
			else if (x % 19 == 0)
				x = 19;  //Green
			else if (x % 7 == 0)
				x = 7;  //Blue
			else if (x % 13 == 0)
				x = 13;  //Orange

			if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x && grid[i + 2][j] % x == grid[i + 3][j] % x)
			{
				if (grid[i][j] != -3)
				{
					if (grid[i][j] / x == 3 || grid[i + 1][j] / x == 3 || grid[i + 2][j] / x == 3 || grid[i + 3][j] / x == 3)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < row; k++)  //vertical stripe elimination
						{
							grid[k][j] = -3;
						}
					}
					if (grid[i][j] / x == 2)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < column; k++)  //horizontal stripe elimination
						{
							grid[i][k] = -3;
						}
					}
					if (grid[i + 1][j] / x == 2)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < column; k++)  //horizontal stripe elimination
						{
							grid[i + 1][k] = -3;
						}
					}
					if (grid[i + 2][j] / x == 2)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < column; k++)  //horizontal stripe elimination
						{
							grid[i + 2][k] = -3;
						}
					}
					if (grid[i + 3][j] / x == 2)
					{
						eliminatewrappedcandy(grid);
						for (int k = 0; k < column; k++)  //horizontal stripe elimination
						{
							grid[i + 3][k] = -3;
						}
					}
					eliminatewrappedcandy(grid);
					grid[i][j] = -3;
					grid[i + 1][j] = -3;
					grid[i + 2][j] = -3;
					grid[i + 3][j] = w;

				}
			}
		}
	}
	display(grid);
}
int GridManipulator::initialMatchCheck(int grid[row][column])
{
	//horizontal check 
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			int x = grid[i][j];
			if (x % 11 == 0)
				x = 11;
			else if (x % 17 == 0)
				x = 17;
			else if (x % 19 == 0)
				x = 19;
			else if (x % 7 == 0)
				x = 7;
			else if (x % 13 == 0)
				x = 13;

			if (grid[i][j] % x == grid[i][j + 1] % x && grid[i][j + 1] % x == grid[i][j + 2] % x)
			{
				grid[i][j] = -1;
				grid[i][j + 1] = -1;
				grid[i][j + 2] = -1;
				display(grid);
				return 0;
			}
		}
	}// horizontal end

	//vertical check
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < column; j++)
		{
			int x = grid[i][j];
			if (x % 11 == 0)
				x = 11;
			else if (x % 17 == 0)
				x = 17;
			else if (x % 19 == 0)
				x = 19;
			else if (x % 7 == 0)
				x = 7;
			else if (x % 13 == 0)
				x = 13;

			if (grid[i][j] % x == grid[i + 1][j] % x && grid[i + 1][j] % x == grid[i + 2][j] % x)
			{
				grid[i][j] = -1;
				grid[i + 1][j] = -1;
				grid[i + 2][j] = -1;
				display(grid);
				return 0;
			}
		}
	}
	//vertical end
	display(grid);
	return -1;
}
void GridManipulator::initialize(int grid[row][column])
{
	srand(time(0));

	int x;
	for (int f = 0; f < 90; f++)
	{
		x = rand() % 5;
		initial[f] = simple_candies[x];
	}
	for (int f = 90; f < 94; f++)
	{
		x = rand() % 5;
		initial[f] = horizontal_striped[x];
	}
	for (int f = 94; f < 98; f++)
	{
		x = rand() % 5;
		initial[f] = vertical_striped[x];
	}
	for (int f = 98; f < 99; f++)
	{
		x = rand() % 5;
		initial[f] = wrapped_candy[x];
	}

	initial[99] = 999;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			int k = rand() % 100;
			grid[i][j] = initial[k];
		}
	}
	display(grid);
}
void GridManipulator::eliminatecolorbomb(int grid[row][column], int a1, int b1, int a2, int b2)
{
	if (grid[a1][b1] == 999 && grid[a2][b2] == 999)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				grid[i][j] = -3;
			}
		}
	}

	int x;
	if (grid[a1][b1] == 999)
	{
		x = grid[a2][b2];
	}
	else
	{
		x = grid[a1][b1];
	}
	if (x % 11 == 0)
		x = 11; //Red candy
	else if (x % 17 == 0)
		x = 17;  //Yellow candy
	else if (x % 19 == 0)
		x = 19;  //Green candy
	else if (x % 7 == 0)
		x = 7;  //Blue candy
	else if (x % 13 == 0)
		x = 13;  //Orange wrapped candy 

	if (grid[a1][b1] == 999 || grid[a2][b2] == 999)
	{
		if (grid[a1][b1] / x == 1 || grid[a2][b2] / x == 1)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					if (grid[i][j] % x == 0)
					{
						if (grid[i][j] / x == 3)
						{
							for (int k = 0; k < row; k++)
							{
								grid[k][j] = -3;
							}
						}
						if (grid[i][j] / x == 2)
						{
							for (int k = 0; k < column; k++)
							{
								grid[i][k] = -3;
							}
						}
						grid[i][j] = -3;
						grid[a1][b1] = -3;
						grid[a2][b2] = -3;
					}
				}
			}
		}
	}
	if (grid[a1][b1] == 999 || grid[a2][b2] == 999) //colorbomb plus horizontal striped candy
	{
		if (grid[a1][b1] / x == 2 || grid[a2][b2] / x == 2)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					if (grid[i][j] % x == 0)
					{
						grid[i][j] = x * 2;
						for (int k = 0; k < row; k++)
						{
							for (int l = 0; l < column; l++)
							{
								if (grid[k][l] == x * 2)
								{
									for (int m = 0; m < column; m++)
									{
										grid[k][m] = -3;
										grid[a1][b1] = -3;
										grid[a2][b2] = -3;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (grid[a1][b1] == 999 || grid[a2][b2] == 999) //colorbomb plus vertical striped candy
	{
		if (grid[a1][b1] / x == 3 || grid[a2][b2] / x == 3)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					if (grid[i][j] % x == 0)
					{
						grid[i][j] = x * 3;
						for (int k = 0; k < row; k++)
						{
							for (int l = 0; l < column; l++)
							{
								if (grid[k][l] == x * 3)
								{
									for (int m = 0; m < row; m++)
									{
										grid[m][l] = -3;
										grid[a1][b1] = -3;
										grid[a2][b2] = -3;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (grid[a1][b1] == 999 || grid[a2][b2] == 999) //colorbomb plus wrapped candy
	{
		if (grid[a1][b1] / x == 4 || grid[a2][b2] / x == 4)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					if (grid[i][j] % x == 0)
					{
						grid[i][j] = x * 4;
						for (int k = 0; k < row; k++)
						{
							for (int l = 0; l < column; l++)
							{
								if (grid[k][l] == x * 4)
								{
									eliminatethreeBythree(grid, k, l);
								}
							}
						}
					}
				}
			}
		}
	}
	display(grid);
}
void GridManipulator::eliminateWrappedPlusWrapped(int grid[row][column], int a1, int b1, int a2, int b2)
{
	int x = grid[a1][b1];
	if (x % 11 == 0)
		x = 11; //Red
	else if (x % 17 == 0)
		x = 17;  //Yellow
	else if (x % 19 == 0)
		x = 19;  //Green
	else if (x % 7 == 0)
		x = 7;  //Blue
	else if (x % 13 == 0)
		x = 13;  //Orange

	int y = grid[a2][b2];
	if (y % 11 == 0)
		y = 11; //Red
	else if (y % 17 == 0)
		y = 17;  //Yellow
	else if (y % 19 == 0)
		y = 19;  //Green
	else if (y % 7 == 0)
		y = 7;  //Blue
	else if (y % 13 == 0)
		y = 13;  //Orange

	if (grid[a1][b1] / x == 4)
	{
		if (grid[a2][b2] / y == 4)
		{
			//entire horizontal at origin
			grid[a1][b1] = -3;
			if (a1 + 1 < 9) {
				grid[a1 + 1][b1] = -3;
			}
			if (a1 + 2 < 9) {
				grid[a1 + 2][b1] = -3;
			}
			if (a1 - 1 > -1) {
				grid[a1 - 1][b1] = -3;
			}
			if (a1 - 2 > -1) {
				grid[a1 - 2][b1] = -3;
			}
			for (int pz4 = 1; pz4 < 3; pz4++) {
				if ((b1 + pz4) < 9) {
					grid[a1][b1 + pz4] = -3;
				}
				if ((a1 + 1 < 9) && (b1 + pz4 < 9)) {
					grid[a1 + 1][b1 + pz4] = -3;
				}
				if ((a1 + 2 < 9) && (b1 + pz4 < 9)) {
					grid[a1 + 2][b1 + pz4] = -3;
				}
				if ((a1 - 1 > -1) && (b1 + pz4 < 9)) {
					grid[a1 - 1][b1 + pz4] = -3;
				}
				if ((a1 - 2 > -1) && (b1 + pz4 < 9)) {
					grid[a1 - 2][b1 + pz4] = -3;
				}

			}
			for (int pz5 = -2; pz5 < 0; pz5++) {
				if ((b1 + pz5) < 9) {
					grid[a1][b1 + pz5] = -3;
				}
				if ((a1 + 1 < 9) && (b1 + pz5 > -1)) {
					grid[a1 + 1][b1 + pz5] = -3;
				}
				if ((a1 + 2 < 9) && (b1 + pz5 > -1)) {
					grid[a1 + 2][b1 + pz5] = -3;
				}
				if ((a1 - 1 > -1) && (b1 + pz5 > -1)) {
					grid[a1 - 1][b1 + pz5] = -3;
				}
				if ((a1 - 2 > -1) && (b1 + pz5 > -1)) {
					grid[a1 - 2][b1 + pz5] = -3;
				}

			}

		}

	}
	display(grid);
}
void GridManipulator::square_candy_vertical(float &x, float &y)
{
   /* sf::RectangleShape square_candy(sf::Vector2f(60, 60));
    square_candy.setFillColor(sf::Color::Green);
    sf::RectangleShape vertical(sf::Vector2f(60, 4));
    vertical.rotate(90);*/
    if (y == 0)
        y = 120;
    else
        y = (y * 100) + 120;
    if (x == 0)
        x = 120;
    else
        x = (x * 100) + 120;


    //square_candy.setPosition(y, x);
    //window.draw(square_candy);
    //for (int i = 0; i < 60; i = i + 10)
    //{
    //    vertical.setPosition(y + i + 5, x);
    //    window.draw(vertical);
    //}
	cout << "THIS IS THE OUTPUT" << endl;
	cout << "Y: " << y << endl;
	cout << "X: " << x << endl;

}

//Functions that are being called within other functions
void GridManipulator::copyOfGrid(int scoreGrid[][column], int grid[row][column])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			scoreGrid[i][j] = grid[i][j];
		}
	}
}
void GridManipulator::score(int scoreGrid[][column], int grid[][column])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			int  w = scoreGrid[i][j];
			if (w % 11 == 0)
				w = 30; //Red
			else if (w % 17 == 0)
				w = 30;  //Yellow
			else if (w % 19 == 0)
				w = 40;  //Green
			else if (w % 7 == 0)
				w = 50;  //Blue
			else if (w % 13 == 0)
				w = 60;  //Orange

			if (grid[i][j] != scoreGrid[i][j])
			{
				if (grid[i][j] == -3)
				{
					points = points + w;
				}
			}
		}
	}
}
void GridManipulator::display(int grid[row][column])
{
	cout << "Grid after function execution" << endl;
	for (int k = 0; k < row; k++)
	{
		for (int x = 0; x < column; x++)
		{
			cout << grid[k][x] << " ";
		}
		cout << endl;
	}
}



