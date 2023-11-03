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
	bool IsCellOutOfBounds(int row, int column);
	bool IsCellEmpty(int row, int column);
	int ClearComlpeteRows();
	int grid[20][10];

private:
	bool IsRowComplete(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int numRows);
	int numRows;
	int numColumns;
	int cellSize;

	std::vector<Color> colors;
};

