//test.cpp
#include "pch.h"
#include "functions.cpp"

GridManipulator gridManipulator;

//Ibrahim
TEST(GridManipulatorTest, ShiftFunctionTest) {


    //-3 drops down the above value and the top most value is replaced with -1

    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
  {7, 17, 7, 7, 13, 17, 19, 22, 33},
  {19, -3, 17, 17, 13, 7, 19, 17, 19},
 {13, 17, 17, 13, 17, 19, 17, 11, 7},
 {19, 7, 13, 7, 19, 34, 7, 11, 11},
 {17, 17, 19, 7, 39, 19, 7, 17, 7},
 {17, 7, 7, 11, 7, 17, 33, 7, 7},
 {19, 7, 13, 7, 19, 39, 11, 13, 19},
 {21, 19, 17, 19, 7, 11, 7, 11, 11} };
    // Call the shift function
    gridManipulator.shift(grid);


    EXPECT_EQ(grid[2][1], 17);

}
TEST(GridManipulatorTest, ShiftFunctionTest2) {


    //Test case for shift function if grid values are not valid grid values


    int grid[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
 {10, 12, 15, 16, 18, 19, 20, 21, 22},
 {23, 24, 25, 26, 27, 28, 29, 30, 31},
 {32, 33, 34, 35, 36, 37, 38, 39, 40},
 {41, 42, 43, 44, 45, 46, 47, 48, 49},
 {50, 51, 52, 53, 54, 55, 56, 57, 58},
 {59, 60, 61, 62, 63, 64, 65, 66, 67},
 {68, 69, 70, 71, 72, 73, 74, 75, 76},
 {77, 78, 79, 80, 81, 82, 83, 84, 85} };

    int expected[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
  {10, 12, 15, 16, 18, 19, 20, 21, 22},
  {23, 24, 25, 26, 27, 28, 29, 30, 31},
  {32, 33, 34, 35, 36, 37, 38, 39, 40},
  {41, 42, 43, 44, 45, 46, 47, 48, 49},
  {50, 51, 52, 53, 54, 55, 56, 57, 58},
  {59, 60, 61, 62, 63, 64, 65, 66, 67},
  {68, 69, 70, 71, 72, 73, 74, 75, 76},
  {77, 78, 79, 80, 81, 82, 83, 84, 85} };
    // Call the shift function
    gridManipulator.shift(grid);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }


}
TEST(GridManipulatorTest, wrappedplusStripedTest1) {

    //valid test case
     //22 and 44 swapped(wrapped and striped) swapped
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
{7, 22, 44, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 19},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };


    int expected[row][column] = {
    {-3, -3, -3, -3, -3, -3, -3, -3, -3},
    {-3, -3, -3, -3, -3, -3, -3, -3, -3},
    {-3, -3, -3, -3, -3, -3, -3, -3, -3},
    {13, -3, -3, -3, 17, 19, 17, 11, 7},
    {19, -3, -3, -3, 19, 34, 7, 11, 11},
    {17, -3, -3, -3, 39, 19, 7, 17, 7},
    {17, -3, -3, -3, 7, 17, 33, 7, 7},
    {19, -3, -3, -3, 19, 39, 11, 13, 19},
    {21, -3, -3, -3, 7, 11, 7, 11, 11}
    };

    // Call the wrappedPlusStriped function
    gridManipulator.wrappedPlusStriped(grid, 1, 1, 1, 2);



    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, wrappedplusStripedTest2) {



    int grid[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
{10, 12, 15, 16, 18, 19, 20, 21, 22},
{23, 24, 25, 26, 27, 28, 29, 30, 31},
{32, 33, 34, 35, 36, 37, 38, 39, 40},
{41, 42, 43, 44, 45, 46, 47, 48, 49},
{50, 51, 52, 53, 54, 55, 56, 57, 58},
{59, 60, 61, 62, 63, 64, 65, 66, 67},
{68, 69, 70, 71, 72, 73, 74, 75, 76},
{77, 78, 79, 80, 81, 82, 83, 84, 85} };

    int expected[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
  {10, 12, 15, 16, 18, 19, 20, 21, 22},
  {23, 24, 25, 26, 27, 28, 29, 30, 31},
  {32, 33, 34, 35, 36, 37, 38, 39, 40},
  {41, 42, 43, 44, 45, 46, 47, 48, 49},
  {50, 51, 52, 53, 54, 55, 56, 57, 58},
  {59, 60, 61, 62, 63, 64, 65, 66, 67},
  {68, 69, 70, 71, 72, 73, 74, 75, 76},
  {77, 78, 79, 80, 81, 82, 83, 84, 85} };

    gridManipulator.wrappedPlusStriped(grid, 0, 0, 0, 1);


    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }

}
TEST(GridManipulatorTest, wrappedplusStripedTest3) {

    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
     {7, 22, 44, 7, 13, 17, 19, 22, 33},
     {19, 7, 17, 17, 13, 7, 19, 17, 19},
     {13, 17, 17, 13, 17, 19, 17, 11, 7},
     {19, 7, 13, 7, 19, 34, 7, 11, 11},
     {17, 17, 19, 7, 39, 19, 7, 17, 7},
     {17, 7, 7, 11, 7, 17, 33, 7, 7},
     {19, 7, 13, 7, 19, 39, 11, 13, 19},
     {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };



    //test case for a1 to be negative
    gridManipulator.wrappedPlusStriped(grid, -2, 3, 3, 3);


    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, wrappedplusStripedTest4) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    //Test case for a1 to be greater than 8
    gridManipulator.wrappedPlusStriped(grid, 10, 3, 2, 1);


    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, wrappedplusStripedTest5) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Test case for b1 to be negative
    gridManipulator.wrappedPlusStriped(grid, 1, -3, 2, 1);


    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, wrappedplusStripedTest6) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
   {7, 22, 44, 7, 13, 17, 19, 22, 33},
   {19, 7, 17, 17, 13, 7, 19, 17, 19},
   {13, 17, 17, 13, 17, 19, 17, 11, 7},
   {19, 7, 13, 7, 19, 34, 7, 11, 11},
   {17, 17, 19, 7, 39, 19, 7, 17, 7},
   {17, 7, 7, 11, 7, 17, 33, 7, 7},
   {19, 7, 13, 7, 19, 39, 11, 13, 19},
   {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };
    //Test case for b1 to be greater than 8
    gridManipulator.wrappedPlusStriped(grid, 1, 12, 2, 1);


    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, wrappedplusStripedTest7) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };
    //Test case for a2 to be negative
    gridManipulator.wrappedPlusStriped(grid, 2, 0, -2, 1);


    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, wrappedplusStripedTest8) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
      {7, 22, 44, 7, 13, 17, 19, 22, 33},
      {19, 7, 17, 17, 13, 7, 19, 17, 19},
      {13, 17, 17, 13, 17, 19, 17, 11, 7},
      {19, 7, 13, 7, 19, 34, 7, 11, 11},
      {17, 17, 19, 7, 39, 19, 7, 17, 7},
      {17, 7, 7, 11, 7, 17, 33, 7, 7},
      {19, 7, 13, 7, 19, 39, 11, 13, 19},
      {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    // Test case for a2 to be greater than 8
    gridManipulator.wrappedPlusStriped(grid, 1, 1, 12, 1);

    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, wrappedplusStripedTest9) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    //Test case for b2 to be negative 
    gridManipulator.wrappedPlusStriped(grid, 1, 1, 2, -4);

    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, wrappedplusStripedTest10) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
      {7, 22, 44, 7, 13, 17, 19, 22, 33},
      {19, 7, 17, 17, 13, 7, 19, 17, 19},
      {13, 17, 17, 13, 17, 19, 17, 11, 7},
      {19, 7, 13, 7, 19, 34, 7, 11, 11},
      {17, 17, 19, 7, 39, 19, 7, 17, 7},
      {17, 7, 7, 11, 7, 17, 33, 7, 7},
      {19, 7, 13, 7, 19, 39, 11, 13, 19},
      {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, 13, 17, 19, 17, 11, 7},
    {19, 7, 13, 7, 19, 34, 7, 11, 11},
    {17, 17, 19, 7, 39, 19, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    //Test case for b2 is greater than 8 
    gridManipulator.wrappedPlusStriped(grid, 1, 1, 1, 14);

    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatethreebythreeTest1) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = {
    {34, 13, 17, 11, 13, 7, 19, 7, 11},
    {7, 22, 44, 7, 13, 17, 19, 22, 33},
    {19, 7, 17, 17, 13, 7, 19, 17, 19},
    {13, 17, 17, -3, -3, -3, 17, 11, 7},
    {19, 7, 13, -3, -3, -3, 7, 11, 11},
    {17, 17, 19, -3, -3, -3, 7, 17, 7},
    {17, 7, 7, 11, 7, 17, 33, 7, 7},
    {19, 7, 13, 7, 19, 39, 11, 13, 19},
    {21, 19, 17, 19, 7, 11, 7, 11, 11}
    };


    //valid EC for three by three
    gridManipulator.eliminatethreeBythree(grid, 4, 4);

    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatethreebythreeTest2) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Invalid EC for three by three if k < 0
    gridManipulator.eliminatethreeBythree(grid, -4, 4);

    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatethreebythreeTest3) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Invalid EC for three by three if k > 8
    gridManipulator.eliminatethreeBythree(grid, 10, 4);

    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatethreebythreeTest4) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Invalid EC for three by three if l < 0
    gridManipulator.eliminatethreeBythree(grid, 4, -4);

    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatethreebythreeTest5) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Invalid EC for three by three if l > 8
    gridManipulator.eliminatethreeBythree(grid, 4, 10);

    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, swapTest1) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {13, 34, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Valid EC for swap
    gridManipulator.swap(grid, 0, 0, 0, 1);

    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, swapTest2) {
    int grid[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
      {10, 12, 15, 16, 18, 19, 20, 21, 22},
      {23, 24, 25, 26, 27, 28, 29, 30, 31},
      {32, 33, 34, 35, 36, 37, 38, 39, 40},
      {41, 42, 43, 44, 45, 46, 47, 48, 49},
      {50, 51, 52, 53, 54, 55, 56, 57, 58},
      {59, 60, 61, 62, 63, 64, 65, 66, 67},
      {68, 69, 70, 71, 72, 73, 74, 75, 76},
      {77, 78, 79, 80, 81, 82, 83, 84, 85} };

    int expected[row][column] = { {2, 1, 3, 4, 5, 6, 8, 9, 0},
       {10, 12, 15, 16, 18, 19, 20, 21, 22},
       {23, 24, 25, 26, 27, 28, 29, 30, 31},
       {32, 33, 34, 35, 36, 37, 38, 39, 40},
       {41, 42, 43, 44, 45, 46, 47, 48, 49},
       {50, 51, 52, 53, 54, 55, 56, 57, 58},
       {59, 60, 61, 62, 63, 64, 65, 66, 67},
       {68, 69, 70, 71, 72, 73, 74, 75, 76},
       {77, 78, 79, 80, 81, 82, 83, 84, 85} };


    //swap in case the values are not values of the grid
    gridManipulator.swap(grid, 0, 0, 0, 1);

    // Check that each value is the same as before the shift
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, swapTest3) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //swap function in case a1 is negative
    gridManipulator.swap(grid, -2, 0, 0, 1);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, swapTest4) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //swap function in case a1 > 8
    gridManipulator.swap(grid, 10, 0, 0, 1);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, swapTest5) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Invalid EC swap function in case b1 < 0
    gridManipulator.swap(grid, 0, -2, 0, 1);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, swapTest6) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Invalid EC swap function in case a2 < 0
    gridManipulator.swap(grid, 0, 0, -2, 1);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, swapTest7) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Invalid EC swap function in case a2 > 8
    gridManipulator.swap(grid, 0, 0, 10, 1);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, swapTest8) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Invalid EC swap function in case b1 < 0
    gridManipulator.swap(grid, 0, 0, 0, -2);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, swapTest9) {
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expected[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
       {7, 22, 44, 7, 13, 17, 19, 22, 33},
       {19, 7, 17, 17, 13, 7, 19, 17, 19},
       {13, 17, 17, 13, 17, 19, 17, 11, 7},
       {19, 7, 13, 7, 19, 34, 7, 11, 11},
       {17, 17, 19, 7, 39, 19, 7, 17, 7},
       {17, 7, 7, 11, 7, 17, 33, 7, 7},
       {19, 7, 13, 7, 19, 39, 11, 13, 19},
       {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    //Invalid EC swap function in case b1 > 8
    gridManipulator.swap(grid, 0, 0, 0, 10);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expected[i][j]);
        }
    }
}
TEST(GridManipulatorTest, zeroTest1) {
    float x, y;
    x = 0, y = 0;
    //Valid EC for zero
    int expected_x = 105, expected_y = 110;


    gridManipulator.zero(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, zeroTest2) {
    float x, y;
    x = -2, y = 0;
    //Invalid EC incase x is negative
    int expected_x = -95, expected_y = 110;


    gridManipulator.zero(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, zeroTest3) {
    float x, y;
    x = 10, y = 0;
    //Invalid EC incase x is greater than 8
    int expected_x = 1105, expected_y = 110;


    gridManipulator.zero(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, zeroTest4) {
    float x, y;
    x = 0, y = -2;
    //Invalid EC incase y is negative
    int expected_x = 105, expected_y = -90;

    gridManipulator.zero(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, zeroTest5) {
    float x, y;
    x = 0, y = 10;
    //Invalid EC incase y is greater than 8
    int expected_x = 105, expected_y = 1110;

    gridManipulator.zero(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, inputTest1) {
    int mousex, mousey, save;

    mousex = 100, mousey = 100, save = 0;
    //valid ec test case if mousex and y are between valid range
    int expected_mx = 0, expected_my = 0, expected_save = 0;

    gridManipulator.input(mousex, mousey, save);

    EXPECT_EQ(mousex, expected_mx);
    EXPECT_EQ(mousey, expected_my);
    EXPECT_EQ(save, expected_save);
}
TEST(GridManipulatorTest, inputTest2) {
    int mousex, mousey, save;
    //invalid ec test case if mousex and y values are such that they make save 1
    mousex = 991, mousey = 1400, save = 0;

    int expected_mx = -1, expected_my = -1, expected_save = 1;
    //In case save = 1 condition is set to true becuase of mousex and mousey values 
    gridManipulator.input(mousex, mousey, save);

    EXPECT_EQ(mousex, expected_mx);
    EXPECT_EQ(mousey, expected_my);
    EXPECT_EQ(save, expected_save);
}
TEST(GridManipulatorTest, inputTest3) {
    int mousex, mousey, save;

    mousex = 50, mousey = 100, save = 0;

    int expected_mx = -1, expected_my = -1, expected_save = 0;
    //Test case if mousex < 100
    gridManipulator.input(mousex, mousey, save);

    EXPECT_EQ(mousex, expected_mx);
    EXPECT_EQ(mousey, expected_my);
    EXPECT_EQ(save, expected_save);
}
TEST(GridManipulatorTest, inputTest4) {
    int mousex, mousey, save;

    mousex = 1000, mousey = 100, save = 0;

    int expected_mx = -1, expected_my = -1, expected_save = 0;
    //Test case if mousex > 900
    gridManipulator.input(mousex, mousey, save);

    EXPECT_EQ(mousex, expected_mx);
    EXPECT_EQ(mousey, expected_my);
    EXPECT_EQ(save, expected_save);
}
TEST(GridManipulatorTest, inputTest5) {
    int mousex, mousey, save;

    mousex = 100, mousey = 0, save = 0;

    int expected_mx = -1, expected_my = -1, expected_save = 0;
    //Test case if mousey < 100
    gridManipulator.input(mousex, mousey, save);

    EXPECT_EQ(mousex, expected_mx);
    EXPECT_EQ(mousey, expected_my);
    EXPECT_EQ(save, expected_save);
}
TEST(GridManipulatorTest, inputTest6) {
    int mousex, mousey, save;

    mousex = 100, mousey = 1000, save = 0;

    int expected_mx = -1, expected_my = -1, expected_save = 0;
    //Test case if mousey > 900
    gridManipulator.input(mousex, mousey, save);

    EXPECT_EQ(mousex, expected_mx);
    EXPECT_EQ(mousey, expected_my);
    EXPECT_EQ(save, expected_save);
}
TEST(GridManipulatorTest, yellowTest1) {
    float x, y;
    x = 0, y = 0;
    //Valid EC for zero
    int expected_x = 115, expected_y = 110;


    gridManipulator.yellow_horizontal(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, yellowTest2) {
    float x, y;
    x = -2, y = 0;
    //Invalid EC incase x is negative
    int expected_x = -85, expected_y = 110;


    gridManipulator.yellow_horizontal(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, yellowTest3) {
    float x, y;
    x = 10, y = 0;
    //Invalid EC incase x is greater than 8
    int expected_x = 1115, expected_y = 110;


    gridManipulator.yellow_horizontal(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, yellowTest4) {
    float x, y;
    x = 0, y = -2;
    //Invalid EC incase y is negative
    int expected_x = 115, expected_y = -90;

    gridManipulator.yellow_horizontal(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, yellowTest5) {
    float x, y;
    x = 0, y = 10;
    //Invalid EC incase y is greater than 8
    int expected_x = 115, expected_y = 1110;

    gridManipulator.yellow_horizontal(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}

//Manal
TEST(GridManipulatorTest, eliminatewrappedcandy1) {

    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
                        { 7, 17, 7, 7, 13, 17, 19, 22, 33 },
                        { 19, 7, 17, 17, 13, 7, 19, 17, 19 },
                        { 13, 17, 17, 13, 17, 19, 17, 11, 7 },
                        { 19, 7, 13, 11, 19, 34, 7, 11, 11 },
                        { 17, 17, 19, 44, 39, 19, 7, 17, 7 },
                        { 17, 7, 7, 11, 7, 17, 33, 7, 7 },
                        { 19, 7, 13, 7, 19, 39, 11, 13, 19 },
                        { 21, 19, 17, 19, 7, 11, 7, 11, 11 } };

    int expectedGrid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
                                        { 7, 17, 7, 7, 13, 17, 19, 22, 33 },
                                        { 19, 7, 17, 17, 13, 7, 19, 17, 19 },
                                        { 13, 17, 17, 13, 17, 19, 17, 11, 7 },
                                        { 19, 7, -3, -3, -3, 34, 7, 11, 11 },
                                        { 17, 17, -3, -3, -3, 19, 7, 17, 7 },
                                        { 17, 7, -3, -3, -3, 17, 33, 7, 7 },
                                        { 19, 7, 13, 7, 19, 39, 11, 13, 19 },
                                        { 21, 19, 17, 19, 7, 11, 7, 11, 11 } };

    gridManipulator.eliminatewrappedcandy(grid);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }

}
TEST(GridManipulatorTest, eliminatewrappedcandy2) {

    int grid[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
                                 {10, 12, 15, 16, 18, 19, 20, 21, 22},
                                 {23, 24, 25, 26, 27, 28, 29, 30, 31},
                                 {32, 33, 34, 35, 36, 37, 38, 39, 40},
                                 {41, 42, 43, 44, 45, 46, 47, 48, 49},
                                 {50, 51, 52, 53, 54, 55, 56, 57, 58},
                                 {59, 60, 61, 62, 63, 64, 65, 66, 67},
                                 {68, 69, 70, 71, 72, 73, 74, 75, 76},
                                 {77, 78, 79, 80, 81, 82, 83, 84, 85} };

    int expectedGrid[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
                                 {10, 12, 15, 16, 18, 19, 20, 21, 22},
                                 {23, 24, 25, 26, 27, 28, 29, 30, 31},
                                 {32, 33, 34, 35, 36, 37, 38, 39, 40},
                                 {41, 42, 43, 44, 45, 46, 47, 48, 49},
                                 {50, 51, 52, 53, 54, 55, 56, 57, 58},
                                 {59, 60, 61, 62, 63, 64, 65, 66, 67},
                                 {68, 69, 70, 71, 72, 73, 74, 75, 76},
                                 {77, 78, 79, 80, 81, 82, 83, 84, 85} };

    gridManipulator.eliminatewrappedcandy(grid);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }

}
TEST(GridManipulatorTest, wrappedcandy1) {

    int grid[row][column] = { { 34, 13, 17, 11, 13, 7, 7, 7, 11 },
                        { 7, 17, 7, 7, 13, 17, 19, 22, 33 },
                        { 19, 7, 17, 17, 13, 7, 19, 17, 19 },
                        { 13, 17, 17, 13, 17, 19, 17, 11, 7 },
                        { 19, 7, 13, 7, 19, 34, 7, 11, 11 },
                        { 17, 17, 19, 7, 39, 19, 7, 17, 7 },
                        { 17, 7, 7, 7, 11, 17, 33, 7, 7 },
                        { 19, 7, 13, 7, 19, 39, 11, 13, 19 },
                        { 21, 19, 17, 19, 7, 11, 7, 11, 11 } };

    int expectedGrid[row][column] = { {34,13, 17, 11, 13, 7, 7, 7, 11},
                                       {7, 17 , 7 , 7 , 13, 17, 19, 22, 33},
                                       {19, 7, 17, 17, 13, 7, 19, 17, 19},
                                       {13, 17, 17, 13, 17, 19, 17, 11, 7},
                                       {19, 7, 13, -3, 19, 34, 7, 11, 11},
                                       {17, 17, 19, -3, 39, 19, 7, 17, 7},
                                       {17, -3, -3, 28, 11, 17, 33, 7, 7},
                                       {19, 7, 13, 7, 19, 39, 11, 13, 19},
                                       {21,19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.wrappedcandy(grid);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }

}
TEST(GridManipulatorTest, wrappedcandy2) {

    int grid[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
                             {10, 12, 15, 16, 18, 19, 20, 21, 22},
                             {23, 24, 25, 26, 27, 28, 29, 30, 31},
                             {32, 33, 34, 35, 36, 37, 38, 39, 40},
                             {41, 42, 43, 44, 45, 46, 47, 48, 49},
                             {50, 51, 52, 53, 54, 55, 56, 57, 58},
                             {59, 60, 61, 62, 63, 64, 65, 66, 67},
                             {68, 69, 70, 71, 72, 73, 74, 75, 76},
                             {77, 78, 79, 80, 81, 82, 83, 84, 85}
    };

    int expectedGrid[row][column] = {
        {-3, -3, -3, -3, -3, -3, -3, -3, -3},
        {-3, -3, -3, 16, -3, 19, 20, -3, 22},
        {-3, -3, -3, 26, -3, 28, 29, -3, 31},
        {-3, -3, -3, 35, 36, 37, 38, 39, 40},
        {-3, -3, -3, 44, 45, 46, 47, 48, 49},
        {-3, -3, -3, 53, 54, 55, 56, 57, 58},
        {-3, -3, -3, 62, 63, 64, 65, 66, 67},
        {-3, -3, -3, 71, 72, 73, 74, 75, 76},
        {1, -3, -3, 80, 81, 82, 83, 84, 85}
    };

    gridManipulator.wrappedcandy(grid);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }

}
TEST(GridManipulatorTest, candybomb1) {

    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 19, 7, 11},
                        {7, 17, 7, 7, 13, 17, 19, 22, 33},
                        {19, 7, 17, 17, 17, 17, 17, 7, 19},
                        {13, 17, 17, 13, 17, 19, 17, 11, 7},
                        {19, 7, 13, 7, 19, 34, 7, 11, 11},
                        {17, 17, 19, 7, 39, 19, 7, 17, 7},
                        {17, 7, 7, 11, 7, 17, 33, 7, 7},
                        {19, 7, 13, 7, 19, 39, 11, 13, 19},
                        {21, 19, 17, 19, 7, 11, 7, 11, 11} };



    int expectedGrid[row][column] = {
                        {34, 13, 17, 11, 13, 7, 19, 7, 11},
                        {7, 17, 7, 7, 13, 17, 19, 22, 33},
                        {19, 7, -3, -3, 999, -3, -3, 7, 19},
                        {13, 17, 17, 13, 17, 19, 17, 11, 7},
                        {19, 7, 13, 7, 19, 34, 7, 11, 11},
                        {17, 17, 19, 7, 39, 19, 7, 17, 7},
                        {17, 7, 7, 11, 7, 17, 33, 7, 7},
                        {19, 7, 13, 7, 19, 39, 11, 13, 19},
                        {21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    gridManipulator.candybomb(grid);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }

}
TEST(GridManipulatorTest, candybomb2) {

    int grid[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
                             {10, 12, 15, 16, 18, 19, 20, 21, 22},
                             {23, 24, 25, 26, 27, 28, 29, 30, 31},
                             {32, 33, 34, 35, 36, 37, 38, 39, 40},
                             {41, 42, 43, 44, 45, 46, 47, 48, 49},
                             {50, 51, 52, 53, 54, 55, 56, 57, 58},
                             {59, 60, 61, 62, 63, 64, 65, 66, 67},
                             {68, 69, 70, 71, 72, 73, 74, 75, 76},
                             {77, 78, 79, 80, 81, 82, 83, 84, 85} };



    int expectedGrid[row][column] = { {-3, -3, 999, -3, -3, -3, -3, -3, -3},
                                        {10, 12, -3, 16, 18, 19, 20, 21, 22},
                                        {23, 24, -3, 26, 27, 28, 29, 30, 31},
                                        {32, 33, -3, 35, 36, 37, 38, 39, 40},
                                        {41, 42, -3, 44, 45, 46, 47, 48, 49},
                                        {50, 51, -3, 53, 54, 55, 56, 57, 58},
                                        {59, 60, -3, 62, 63, 64, 65, 66, 67},
                                        {68, 69, -3, 71, 72, 73, 74, 75, 76},
                                        {77, 78, -3, 80, 81, 82, 83, 84, 85}

    };

    gridManipulator.candybomb(grid);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }

}
TEST(GridManipulatorTest, simplythree1) {

    int grid[row][column] = { {34, 11, 11, 11, 13, 7, 19, 7, 11},
                                {7, 17, 7, 7, 13, 17, 19, 22, 33},
                                {19, 7, 17, 7, 11, 17, 17, 7, 19},
                                {13, 17, 17, 13, 17, 19, 17, 11, 7},
                                {19, 7, 13, 7, 19, 34, 7, 11, 11},
                                {17, 17, 19, 7, 39, 19, 7, 17, 7},
                                {17, 7, 7, 11, 7, 17, 33, 7, 7},
                                {19, 7, 13, 7, 19, 39, 11, 13, 19},
                                {21, 19, 17, 19, 7, 11, 7, 11, 11} };



    int expectedGrid[row][column] = { {34, -3, -3, -3, 13, 7, 19, 7, 11},
                                    {7, 17, 7, 7, 13, 17, 19, 22, 33},
                                    {19, 7, 17, 7, 11, 17, 17, 7, 19},
                                    {13, 17, 17, 13, 17, 19, 17, 11, 7},
                                    {19, 7, 13, 7, 19, 34, 7, 11, 11},
                                    {17, 17, 19, 7, 39, 19, 7, 17, 7},
                                    {17, 7, 7, 11, 7, 17, 33, 7, 7},
                                    {19, 7, 13, 7, 19, 39, 11, 13, 19},
                                    {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.simplythree(grid);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }

}
TEST(GridManipulatorTest, simplythree2) {

    int grid[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
                                 {10, 12, 15, 16, 18, 19, 20, 21, 22},
                                 {23, 24, 25, 26, 27, 28, 29, 30, 31},
                                 {32, 33, 34, 35, 36, 37, 38, 39, 40},
                                 {41, 42, 43, 44, 45, 46, 47, 48, 49},
                                 {50, 51, 52, 53, 54, 55, 56, 57, 58},
                                 {59, 60, 61, 62, 63, 64, 65, 66, 67},
                                 {68, 69, 70, 71, 72, 73, 74, 75, 76},
                                 {77, 78, 79, 80, 81, 82, 83, 84, 85} };



    int expectedGrid[row][column] = { {-3, -3, -3, -3, -3, -3, -3, -3, -3},
                                        {10, 12, -3, 16, 18, 19, 20, 21, 22},
                                        {23, 24, -3, 26, 27, 28, 29, 30, 31},
                                        {32, 33, -3, 35, 36, 37, 38, 39, 40},
                                        {41, 42, -3, 44, 45, 46, 47, 48, 49},
                                        {50, 51, -3, 53, 54, 55, 56, 57, 58},
                                        {59, 60, -3, 62, 63, 64, 65, 66, 67},
                                        {68, 69, -3, 71, 72, 73, 74, 75, 76},
                                        {77, 78, -3, 80, 81, 82, 83, 84, 85} };

    gridManipulator.simplythree(grid);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }

}
TEST(GridManipulatorTest, highlight1) {

    int x = 0;
    int y = 1;
    int expected_x = 110;
    int expected_y = 210;

    gridManipulator.highlight(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);

}
TEST(GridManipulatorTest, highlight2) {

    int x = -1;
    int y = 1;
    int expected_x = -1;
    int expected_y = 1;

    gridManipulator.highlight(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, highlight3) {

    int x = 1;
    int y = -1;
    int expected_x = 1;
    int expected_y = -1;

    gridManipulator.highlight(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, highlight4) {

    int x = 9;
    int y = 3;
	int expected_x = 1010;
	int expected_y = 410;

	gridManipulator.highlight(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, highlight5) {

    int x = 2;
    int y = 10;
	int expected_x = 310;
	int expected_y = 1110;

	gridManipulator.highlight(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, candy_bomb1) {

	float x = 1;
	float y = 1;
	float expected_x = 210;
	float expected_y = 210;

	gridManipulator.candy_bomb(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, candy_bomb2) {

	float x = -1;
	float y = 1;
	float expected_x = 10;
	float expected_y = 210;

	gridManipulator.candy_bomb(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, candy_bomb3) {

	float x = 1;
	float y = -1;
	float expected_x = 210;
	float expected_y = 10;

	gridManipulator.candy_bomb(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, candy_bomb4) {

	float x = 11;
	float y = 2;
	float expected_x = 1210;
	float expected_y = 310;

	gridManipulator.candy_bomb(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, candy_bomb5) {

	float x = 3;
	float y = 12;
	float expected_x = 410;
	float expected_y = 1310;

	gridManipulator.candy_bomb(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, yellow_vertical1) {

	float x = 2;
	float y = 2;
	float expected_x = 315;
	float expected_y = 310;

	gridManipulator.yellow_vertical(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, yellow_vertical2) {

	float x = -1;
	float y = 1;
	float expected_x = 15;
	float expected_y = 210;

	gridManipulator.yellow_vertical(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, yellow_vertical3) {

	float x = 1;
	float y = -1;
	float expected_x = 215;
	float expected_y = 10;

	gridManipulator.yellow_vertical(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, yellow_vertical4) {

	float x = 2;
	float y = -3;
	float expected_x = 315;
	float expected_y = -190;

	gridManipulator.yellow_vertical(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, yellow_vertical5) {

	float x = 13;
	float y = 1;
	float expected_x = 1415;
	float expected_y = 210;

	gridManipulator.yellow_vertical(x, y);
	EXPECT_EQ(x, expected_x);
	EXPECT_EQ(y, expected_y);
}

//Wardah
TEST(GridManipulatorTest, StripedCandies1) {
    // Create an instance of GridManipulator


    // Initialize the grid with test data
    int grid[row][column] = { {34, 13, 17, 11, 7, 7, 7, 7, 11},
                              {7, 17, 7, 7, 13, 17, 19, 22, 33},
                             {19, 7, 17, 17, 13, 7, 19, 17, 19},
                             {13, 17, 17, 13, 17, 19, 17, 11, 7},
                             {19, 7, 13, 7, 19, 34, 7, 11, 11},
                             {17, 17, 19, 7, 39, 19, 7, 17, 7},
                             {17, 7, 7, 11, 7, 17, 33, 7, 7},
                             {19, 7, 13, 7, 19, 39, 11, 13, 19},
                             {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expectedGrid[row][column] = { {34, 13, 17, 11, -3, -3, -3, 14, 11},
                                     {7, 17, 7, 7, 13, 17, 19, 22, 33},
                                    {19, 7, 17, 17, 13, 7, 19, 17, 19},
                                    {13, 17, 17, 13, 17, 19, 17, 11, 7},
                                    {19, 7, 13, 7, 19, 34, 7, 11, 11},
                                    {17, 17, 19, 7, 39, 19, 7, 17, 7},
                                    {17, 7, 7, 11, 7, 17, 33, 7, 7},
                                    {19, 7, 13, 7, 19, 39, 11, 13, 19},
                                    {21, 19, 17, 19, 7, 11, 7, 11, 11} };


    // Call the shift function
    gridManipulator.stripedcandies(grid);

    // Add assertions here to check the expected state of the grid after shifting

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }

}
TEST(GridManipulatorTest, StripedCandies2) {

    // Create an instance of GridManipulator


    // Initialize the grid with test data
    int grid[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9, 0},
                            {10, 12, 15, 16, 18, 19, 20, 21, 22},
                            {23, 24, 25, 26, 27, 28, 29, 30, 31},
                            {32, 33, 34, 35, 36, 37, 38, 39, 40},
                            {41, 42, 43, 44, 45, 46, 47, 48, 49},
                            {50, 51, 52, 53, 54, 55, 56, 57, 58},
                            {59, 60, 61, 62, 63, 64, 65, 66, 67},
                            {68, 69, 70, 71, 72, 73, 74, 75, 76},
                            {77, 78, 79, 80, 81, 82, 83, 84, 85} };

    int expectedGrid[row][column] = { {-3, -3, -3, -3, -3, -3, -3, -3,-3},
                                     {10, 12, -3, 16, 18, 19, -3, 21, 22},
                                     {23, 24, -3, 26, 27, 28, -3, 30, 31},
                                     {32, 33, -3, 35, 36, 37, -3, 39, 40},
                                     {41, 42, -3, 44, 45, 46, -3, 48, 49},
                                     {50, 51, -3, 53, 54, 55, -3, 57, 58},
                                     {59, 60, -3, 62, 63, 64, 1, 66, 67},
                                     {68, 69, -3, 71, 72, 73, 74, 75, 76},
                                     {77, 78, -3, 80, 81, 82, 83, 84, 85}};

    // Call the shift function
    gridManipulator.stripedcandies(grid);

    // Add assertions here to check the expected state of the grid after shifting

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }

}
TEST(GridManipulatorTest, initialMatchCheck1) {

    // Create an instance of GridManipulator


    // Initialize the grid with test data
    int grid[row][column] = { {34, 13, 17, 11, 13, 7, 7, 7, 11},
                              {7, 17, 7, 7, 13, 17, 19, 22, 33},
                              {19, 7, 17, 17, 13, 7, 19, 17, 19},
                              {13, 17, 17, 13, 17, 19, 17, 11, 7},
                              {19, 7, 13, 7, 19, 34, 7, 11, 11},
                              {17, 17, 19, 7, 39, 19, 7, 17, 7},
                              {17, 7, 7, 11, 7, 17, 33, 7, 7},
                              {19, 7, 13, 7, 19, 39, 11, 13, 19},
                              {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    int expectedGrid[row][column] = { {34, 13, 17, 11, 13, -1, -1, -1, 11},
                                    {7, 17, 7, 7, 13, 17, 19, 22, 33},
                                    {19, 7, 17, 17, 13, 7, 19, 17, 19},
                                    {13, 17, 17, 13, 17, 19, 17, 11, 7},
                                    {19, 7, 13, 7, 19, 34, 7, 11, 11},
                                    {17, 17, 19, 7, 39, 19, 7, 17, 7},
                                    {17, 7, 7, 11, 7, 17, 33, 7, 7},
                                    {19, 7, 13, 7, 19, 39, 11, 13, 19},
                                    {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    // Call the shift function
    int rValue = gridManipulator.initialMatchCheck(grid);

    // Add assertions here to check the expected state of the grid after shifting

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
    EXPECT_EQ(rValue, 0);
}
TEST(GridManipulatorTest, initialMatchCheck2) {

    // Create an instance of GridManipulator


    // Initialize the grid with test data
   int grid[row][column] = { {1, 2, 3, 4, 5, 6, 8, 9,0},
 {10, 12, 15, 16, 18, 19, 20, 21, 22},
 {23, 24, 25, 26, 27, 28, 29, 30, 31},
 {32, 33, 34, 35, 36, 37, 38, 39, 40},
 {41, 42, 43, 44, 45, 46, 47, 48, 49},
 {50, 51, 52, 53, 54, 55, 56, 57, 58},
 {59, 60, 61, 62, 63, 64, 65, 66, 67},
 {68, 69, 70, 71, 72, 73, 74, 75, 76},
 {77, 78, 79, 80, 81, 82, 83, 84, 85}
    };

    int expectedGrid[row][column] = { {-1, -1, -1, 4, 5, 6, 8, 9, 0},
 {10, 12, 15, 16, 18, 19, 20, 21, 22},
 {23, 24, 25, 26, 27, 28, 29, 30, 31},
 {32, 33, 34, 35, 36, 37, 38, 39, 40},
 {41, 42, 43, 44, 45, 46, 47, 48, 49},
 {50, 51, 52, 53, 54, 55, 56, 57, 58},
 {59, 60, 61, 62, 63, 64, 65, 66, 67},
 {68, 69, 70, 71, 72, 73, 74, 75, 76},
 {77, 78, 79, 80, 81, 82, 83, 84, 85} };

    // Call the shift function
    int rValue = gridManipulator.initialMatchCheck(grid);

    // Add assertions here to check the expected state of the grid after shifting

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
    EXPECT_EQ(rValue, 0);
}
TEST(GridManipulatorTest, eliminatecolorbomb1) {

    // Create an instance of GridManipulator


    // Initialize the grid with test data
    int grid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

   int expectedGrid[row][column] = { {-3, 13, 17, -3, -3, -3, -3, 13, 11},
        {-3, 17, -3, -3, 13, 17, 19, 22, 33},
        {-3, -3, -3, -3, -3, -3, -3, -3, -3},
        {-3, 17, 17, 13, 17, 19, 17, 11, -3},
        {-3, -3, 13, -3, 19, 34, -3, 11, 11},
        {-3, 17, 19, -3, 39, 19, -3, 17, -3},
        {-3, -3, -3, 11, -3, 17, 33, -3, -3},
        {-3, -3, 13, -3, 19, 39, 11, 13, 19},
        {-3, 19, 17, 19, -3, 11, -3, 11, 11} };

    gridManipulator.eliminatecolorbomb(grid,0,3,0,4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatecolorbomb2) {


    int grid[row][column] = { {1, 2, 3, 999, 5, 6, 8, 9, 101},
 {10, 12, 15, 16, 18, 19, 20, 21, 22},
 {23, 24, 25, 26, 27, 28, 29, 30, 31},
 {32, 33, 34, 35, 36, 37, 38, 39, 40},
 {50, 51, 52, 53, 54, 55, 56, 57, 58},
 {59, 60, 61, 62, 63, 64, 65, 66, 67},
 {68, 69, 70, 71, 72, 73, 74, 75, 76},
 {77, 78, 79, 80, 81, 82, 83, 84, 85},
    };

    int expectedGrid[row][column] = { {1, 2, 3, -3, -3, 6, 8, 9, 101},
        {-3, -3, -3, -3, -3, -3, -3, -3, -3},
        {23, 24, -3, 26, 27, 28, 29, -3, 31},
        {32, 33, 34, -3, 36, 37, 38, 39, -3},
        {-3, 51, 52, 53, 54, -3, 56, 57, 58},
        {59, -3, 61, 62, 63, 64, -3, 66, 67},
        {68, 69, -3, 71, 72, 73, 74, -3, 76},
        {77, 78, 79, -3, 81, 82, 83, 84, -3},
        {-3, -3, -3, -3, -3, -3, -3, -3, -3} };

    gridManipulator.eliminatecolorbomb(grid, 0, 3, 0, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
           EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatecolorbomb3) {


    int grid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminatecolorbomb(grid, -1, 3, 0, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatecolorbomb4) {
    int grid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminatecolorbomb(grid, 9, 3, 0, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatecolorbomb5) {
    int grid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminatecolorbomb(grid, 0, -2, 0, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatecolorbomb6) {


    int grid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminatecolorbomb(grid, 0, 20, 0, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatecolorbomb7) {


    int grid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminatecolorbomb(grid, 0, 3, -12, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatecolorbomb8) {


    int grid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminatecolorbomb(grid, 0, 3, 15, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatecolorbomb9) {
    int grid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminatecolorbomb(grid, 0, 0, 0, -5);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminatecolorbomb10) {


    int grid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 13, 17, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 999, 7, 7, 7, 13, 11},
        {7, 17, 7, 7, 13, 17, 19, 22, 33},
        {19, 7, 17, 17, 13, 7, 19, 17, 14},
        {13, 17, 17, 13, 17, 19, 17, 11, 7},
        {19, 7, 13, 7, 19, 34, 7, 11, 11},
        {17, 17, 19, 7, 39, 19, 7, 17, 7},
        {17, 7, 7, 11, 7, 17, 33, 7, 7},
        {19, 7, 13, 7, 19, 39, 11, 13, 19},
        {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminatecolorbomb(grid, 0, 3, 15, 9);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminateWrappedPlusWrapped1) {


    int grid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
        {7, -3, -3, -3, -3, -3, 19, 22, 33},
        {19, -3, -3, -3, -3, -3, 19, 17, 14},
        {13, -3, -3, -3, -3, -3, 17, 11, 7},
        {19, -3, -3, -3, -3, -3, 7, 11, 11},
        {17, -3, -3, -3, -3, -3, 7, 17, 7},
        {17, 7, 7, 11, 7, 17, 33, 7, 7},
        {19, 7, 13, 7, 19, 39, 11, 13, 19},
        {21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminateWrappedPlusWrapped(grid, 3, 3, 3, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminateWrappedPlusWrapped2) {


    int grid[row][column] = {{1, 2, 3, 4, 5, 6, 8, 9, 0},
 {10, 12, 15, 16, 18, 19, 20, 21, 22},
 {23, 24, 25, 26, 27, 28, 29, 30, 31},
 {32, 33, 34, 35, 36, 37, 38, 39, 40},
 {41, 42, 43, 44, 45, 46, 47, 48, 49},
 {50, 51, 52, 53, 54, 55, 56, 57, 58},
 {59, 60, 61, 62, 63, 64, 65, 66, 67},
 {68, 69, 70, 71, 72, 73, 74, 75, 76},
 {77, 78, 79, 80, 81, 82, 83, 84, 85}
    };

    int expectedGrid[row][column] = {{1, 2, 3, 4, 5, 6, 8, 9, 0},
 {10, 12, 15, 16, 18, 19, 20, 21, 22},
 {23, 24, 25, 26, 27, 28, 29, 30, 31},
 {32, 33, 34, 35, 36, 37, 38, 39, 40},
 {41, 42, 43, 44, 45, 46, 47, 48, 49},
 {50, 51, 52, 53, 54, 55, 56, 57, 58},
 {59, 60, 61, 62, 63, 64, 65, 66, 67},
 {68, 69, 70, 71, 72, 73, 74, 75, 76},
 {77, 78, 79, 80, 81, 82, 83, 84, 85}};

    gridManipulator.eliminateWrappedPlusWrapped(grid, 3, 3, 3, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminateWrappedPlusWrapped3) {


    int grid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminateWrappedPlusWrapped(grid, -1, 3, 3, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminateWrappedPlusWrapped4) {


    int grid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminateWrappedPlusWrapped(grid, 9, 3, 3, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminateWrappedPlusWrapped5) {


    int grid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminateWrappedPlusWrapped(grid, 3, -2, 3, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminateWrappedPlusWrapped6) {


    int grid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminateWrappedPlusWrapped(grid, 3, 20, 3, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminateWrappedPlusWrapped7) {


    int grid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminateWrappedPlusWrapped(grid, 3, 3, -12, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminateWrappedPlusWrapped8) {


    int grid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminateWrappedPlusWrapped(grid, 3, 3, 15, 4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminateWrappedPlusWrapped9) {


    int grid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminateWrappedPlusWrapped(grid, 3, 3, 3, -4);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, eliminateWrappedPlusWrapped10) {


    int grid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11}
    };

    int expectedGrid[row][column] = { {34, 13, 17, 34, 19, 7, 7, 13, 11},
 {7, 17, 7, 7, 13, 17, 19, 22, 33},
{19, 7, 17, 17, 13, 7, 19, 17, 14},
{13, 17, 17, 44, 68, 19, 17, 11, 7},
{19, 7, 13, 7, 19, 34, 7, 11, 11},
{17, 17, 19, 7, 39, 19, 7, 17, 7},
{17, 7, 7, 11, 7, 17, 33, 7, 7},
{19, 7, 13, 7, 19, 39, 11, 13, 19},
{21, 19, 17, 19, 7, 11, 7, 11, 11} };

    gridManipulator.eliminateWrappedPlusWrapped(grid, 3, 3, 3, 9);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            EXPECT_EQ(grid[i][j], expectedGrid[i][j]);
        }
    }
}
TEST(GridManipulatorTest, square_candy_vertical1) {
    float x, y;
    x = 4, y = 4;
    int expected_x = 520, expected_y = 520;
    gridManipulator.square_candy_vertical(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, square_candy_vertical2) {
    float x, y;
    x = -4, y = 4;
    int expected_x = -280, expected_y = 520;
    gridManipulator.square_candy_vertical(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, square_candy_vertical3) {
    float x, y;
    x = 10, y = 4;
    int expected_x = 1120, expected_y = 520;
    gridManipulator.square_candy_vertical(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, square_candy_vertical4) {
    float x, y;
    x = 4, y = -4;
    int expected_x = 520, expected_y = -280;
    gridManipulator.square_candy_vertical(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}
TEST(GridManipulatorTest, square_candy_vertical5) {
    float x, y;
    x = 4, y = 20;
    int expected_x = 520, expected_y = 2120;
    gridManipulator.square_candy_vertical(x, y);
    EXPECT_EQ(x, expected_x);
    EXPECT_EQ(y, expected_y);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}