#pragma once
#include <vector>
#include <map>
#include "Position.h"

class Block
{
public:
	Block();
	int id;
	std::map<int, std::vector<Position>> cells;

private:
	int cellSize;
	int rotationState;
};

