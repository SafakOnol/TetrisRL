#pragma once
#include <vector>

class Color;

class Grid
{
public:
	Grid();
	void Initialize();
	void Print();
	void Render();
	int grid[20][10];

private:
	int numRows;
	int numColumns;
	int cellSize;

	std::vector<Color> colors;
	std::vector<Color> GetCellColors();
};

