#pragma once
#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"

class Block
{
public:
	Block();
	void Render();
	int id;
	std::map<int, std::vector<Position>> cells;
	
private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
};

