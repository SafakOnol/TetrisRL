#include <raylib.h>
#include "Game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime(); // RayLib function
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

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

		if (EventTriggered(0.3))
		{
			game.MoveBlockDown();
		}

		game.HandleEvents();
		
		game.Render();

		// ##### //
		EndDrawing();
	}

	CloseWindow();
}