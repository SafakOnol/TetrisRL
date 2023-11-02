#include "Grid.h"
#include <iostream>
#include "raylib.h"

Grid::Grid()
{
	numRows		= 20;
	numColumns	= 10;
	cellSize	= 30;
	Initialize();
	colors = GetCellColors();
}

void Grid::Initialize()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			grid[row][column] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			std::cout << grid[row][column] << " ";
		}
		std::cout << std::endl;
	}
}

void Grid::Render()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			int cellValue = grid[row][column];
			DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
		}
		std::cout << std::endl;
	}
}

std::vector<Color> Grid::GetCellColors()
{
	Color darkGrey	= { 26, 31, 41, 255 };		// 0
	Color green		= { 47, 230, 23, 255 };		// 1
	Color red		= { 232, 18, 18, 255 };		// 2
	Color orange	= { 226, 116, 17, 255 };	// 3
	Color yellow	= { 237, 234, 4, 255 };		// 4
	Color purple	= { 166, 0, 247, 255 };		// 5
	Color cyan		= { 21, 204, 209, 255 };	// 6
	Color blue		= { 13, 64, 216, 255 };		// 7
	
	return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}
