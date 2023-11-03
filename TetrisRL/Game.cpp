#include "Game.h"
#include <random>
#include <iostream>

Game::Game()
{
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
	score = 0;

	// Audio
	InitAudioDevice();
	music = LoadMusicStream("Audio/Life is full of Joy.wav");
	PlayMusicStream(music);
	rotateSound = LoadSound("Audio/rotate.ogg");
	clearSound = LoadSound("Audio/clearRaw.ogg");
	moveDownSound = LoadSound("Audio/moveDown.ogg");
}

Game::~Game()
{
	UnloadMusicStream(music);
	UnloadSound(rotateSound);
	UnloadSound(clearSound);
	UnloadSound(moveDownSound);
	CloseAudioDevice();
}



Block Game::GetRandomBlock()
{
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

std::vector<Block> Game::GetAllBlocks()
{

	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::Render()
{
	grid.Render();
	currentBlock.Render(11, 111);
	

	switch (nextBlock.id)
	{
	case 3:
		nextBlock.Render(255, 420);
		break;
	case 4:
		nextBlock.Render(255, 420);
		break;
	default:
		nextBlock.Render(270, 420);
		break;
	}
}

void Game::HandleEvents()
{
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0)
	{
		gameOver = false;
		RestartGame();
	}
	switch (keyPressed)
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		UpdateScore(0, 1);
		PlaySound(moveDownSound);
		break;
	case KEY_UP:
		RotateBlock();
		break;
	}
}

void Game::MoveBlockLeft()
{
	if (gameOver)
	{
		return;
	}

	currentBlock.Move(0, -1);
	if (IsBlockOutOfBounds() || BlockFits() == false)
	{
		currentBlock.Move(0, 1);
	}
}

void Game::MoveBlockRight()
{
	if (gameOver)
	{
		return;
	}

	currentBlock.Move(0, 1);
	if (IsBlockOutOfBounds() || BlockFits() == false)
	{
		currentBlock.Move(0, -1);
	}
}

void Game::MoveBlockDown()
{
	if (gameOver)
	{
		return;
	}

	currentBlock.Move(1, 0);
	if (IsBlockOutOfBounds() || BlockFits() == false)
	{
		currentBlock.Move(-1, 0);
		LockBlock();
	}

}

bool Game::IsBlockOutOfBounds()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (grid.IsCellOutOfBounds(item.row, item.column))
		{
			return true;
		}

	}
	return false;
}

void Game::RotateBlock()
{
	if (gameOver)
	{
		return;
	}

	currentBlock.Rotate();
	if (IsBlockOutOfBounds() || BlockFits() == false)
	{
		currentBlock.UndoRotation();
	}
	else
	{
		PlaySound(rotateSound);
	}
}

void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (BlockFits() == false)
	{
		gameOver = true;
		std::cout << "GAME OVER!" << std::endl;
	}
	nextBlock = GetRandomBlock();
	int rowsCleared = grid.ClearComlpeteRows();
	if (rowsCleared > 0)
	{
		UpdateScore(rowsCleared, 0);
		PlaySound(clearSound);
	}
	
}

bool Game::BlockFits()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (grid.IsCellEmpty(item.row, item.column) == false)
		{
			return false;
		}
	}
	return true;
}

void Game::RestartGame()
{
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
	switch (linesCleared)
	{
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default:
		break;
	}

	score += moveDownPoints;
}

