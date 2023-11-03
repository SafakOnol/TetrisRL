#pragma once
#include "Grid.h"
#include "Blocks.cpp"


class Game
{
public:
	Game();
	Grid grid;
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();

	void Render();
	void HandleEvents();

	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();

private:
	bool IsBlockOutOfBounds();
	std::vector <Block> blocks;
	Block currentBlock;
	Block nextBlock;
};

