#pragma once
#include "Grid.h"
#include "Blocks.cpp"


class Game
{
public:
	Game();
	~Game();

	void Render();
	void HandleEvents();
	void MoveBlockDown();
	bool gameOver;
	int score;
	Music music;

private:
	Grid grid;
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();

	void MoveBlockLeft();
	void MoveBlockRight();

	bool IsBlockOutOfBounds();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void RestartGame();
	void UpdateScore(int linesCleared, int moveDownPoints);
	std::vector <Block> blocks;
	Block currentBlock;
	Block nextBlock;
	Sound rotateSound;
	Sound clearSound;
	Sound moveDownSound;
};

