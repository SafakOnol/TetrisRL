#include <raylib.h>
#include "Game.h"
#include "Colors.h"
#include <iostream>

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

	InitWindow(500, 720, "TetrisRL");
	SetTargetFPS(50);

	// Load the Font - RayLib
	Font font = LoadFontEx("Font/tetris-2-bombliss.ttf", 64, 0, 0);

	Game game = Game();

	// GAME LOOP
	// ########################################## //
	while (WindowShouldClose() == false)
	{
		UpdateMusicStream(game.music);
		
		BeginDrawing();
		ClearBackground(darkBlue);

		// Draw Text - RayLib

		// TITLE
		DrawTextEx(font, "TETRIS", { 25, 20 }, 62, 2, PINK);
		DrawTextEx(font, "TETRIS", { 27, 22 }, 62, 2, YELLOW);

		// SCORE
		DrawTextEx(font, "SCORE", { 336, 125 }, 23, 2, BLUE);
		DrawTextEx(font, "SCORE", { 338, 128 }, 23, 2, WHITE);
		DrawRectangleRounded({ 320, 160, 170, 60 }, 0.3, 6, lightBlue);

		char scoreText[10];
		sprintf_s(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 23, 2);		
		DrawTextEx(font, scoreText, { 320  + (170 - textSize.x)/2, 178}, 23, 2, WHITE);
		DrawTextEx(font, scoreText, { 322 + (170 - textSize.x) / 2, 180 }, 23, 2, PURPLE);

		// NEXT
		DrawTextEx(font, "NEXT", { 350, 325 }, 23, 2, BLUE);
		DrawTextEx(font, "NEXT", { 352, 327 }, 23, 2, WHITE);
		DrawRectangleRounded({ 320, 360, 170, 180 }, 0.3, 6, lightBlue);

		
		
		// ##### //

		if (EventTriggered(0.3))
		{
			game.MoveBlockDown();
		}

		game.HandleEvents();
		
		game.Render();

		// GAME OVER
		if (game.gameOver)
		{
			DrawTextEx(font, "GAME OVER!", { 30, 340 }, 23, 2, WHITE);
			DrawTextEx(font, "GAME OVER!", { 32, 342 }, 23, 2, PINK);
		}
		

		// ##### //
		EndDrawing();
	}

	CloseWindow();
}