#include "Grid.h"
#include <iostream>
#include "Colors.h"

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
			DrawRectangle(column * cellSize + 11, row * cellSize + 111, cellSize - 1, cellSize - 1, colors[cellValue]);
			//colors[cellValue].a = 100;			
			//DrawRectangle(column * cellSize + 12, row * cellSize + 112, cellSize - 2, cellSize - 2, colors[cellValue]);
			//colors[cellValue].a = 255;
		}
		std::cout << std::endl;
	}
}

bool Grid::IsCellOutOfBounds(int row, int column)
{
	if (row >= 0 && row < numRows && column >= 0 && column < numColumns)
	{
		return false;
	}
	return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
	if (grid[row][column] == 0)
	{
		return true;
	}
	return false;
}

int Grid::ClearComlpeteRows()
{
	int completed = 0;
	for (int row = numRows - 1; row >= 0; row--)
	{
		if (IsRowComplete(row))
		{
			ClearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			MoveRowDown(row, completed);
		}
	}
	return completed;
}

bool Grid::IsRowComplete(int row)
{
	for (int column = 0; column < numColumns; column++)
	{
		if (grid[row][column] == 0)
		{
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row)
{
	for (int column = 0; column < numColumns; column++)
	{
		grid[row][column] = 0;
	}
}

void Grid::MoveRowDown(int row, int numRows)
{
	for (int column = 0; column < numColumns; column++)
	{
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}
