#pragma once
const int row = 9;
const int column = 9;
int initial[100];
int scoreGrid[row][column];
int simple_candies[5] = { 11,17,19,7,13 };
int horizontal_striped[5] = { 22,34,38,14,26 };
int vertical_striped[5] = { 33,51,57,21,39 };
int wrapped_candy[5] = { 44,68,76,28,52 };
int points = 0;
int turns = 20;
int x1 = -1, Y1 = -1, x2 = -1, y2 = -1;
int save = 0;
int red = 11, Yellow = 17, green = 19, blue = 7, Orange = 13;