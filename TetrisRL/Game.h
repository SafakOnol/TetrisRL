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

private:
	std::vector <Block> blocks;
	Block currentBlock;
	Block nextBlock;
};

