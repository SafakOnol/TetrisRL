#include <raylib.h>
#include "Game.h"

int main()
{
	Color darkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "TetrisRL");
	SetTargetFPS(50);

	Game game = Game();

	// GAME LOOP
	// ########################################## //
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(darkBlue);
		// ##### //

		game.HandleEvents();
		game.Render();

		// ##### //
		EndDrawing();
	}

	CloseWindow();
}