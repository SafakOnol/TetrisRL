#pragma once
#include <vector>
#include <raylib.h>

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
};

