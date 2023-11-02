#include <raylib.h>
#include <iostream>
#include "Grid.h"

int main()
{
	Color darkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "TetrisRL");
	SetTargetFPS(50);

	// VARIABLES
	// ########################################## //
	

	Grid grid = Grid();
	grid.grid[0][0] = 1;
	grid.grid[4][5] = 2;
	grid.grid[8][12] = 3;
	grid.Print();
	// ########################################## //




	// GAME LOOP
	// ########################################## //
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(darkBlue);

		grid.Render();

		EndDrawing();
	}

	CloseWindow();
}