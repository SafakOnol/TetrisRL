#include <raylib.h>
#include <iostream>
#include "Grid.h"
#include "Tetrimino.cpp"

int main()
{
	Color darkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "TetrisRL");
	SetTargetFPS(50);

	// VARIABLES
	// ########################################## //
	

	Grid grid = Grid();
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