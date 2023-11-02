#include "raylib.h"
#include <iostream>

int main()
{
	Color darkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "TetrisRL");
	SetTargetFPS(50);

	// Game Loop
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(darkBlue);

		EndDrawing();
	}

	CloseWindow();
}