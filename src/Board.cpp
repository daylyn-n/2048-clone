#include "Board.hpp"
#include <random>

int Board::spawnRandomTile()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0,1);
	
	return (dist(gen) == 0) ? 2 : 4;
}

void Board::insertHelper(int randPos, int pos, int i, int j)
{

	if(pos == randPos)
	{
		set(i, j, spawnRandomTile());
	}
}

void Board::insertTwoOrFour()
{
	int zeroCount {};
	for(int i {}; i < N; i++)
	{
		for(int j {}; j < N; j++)
		{
			if(grid_[i][j] == 0)
				zeroCount++;
		}
	}

	if(zeroCount == 0) return;

	int randPos {rand() % zeroCount + 1};
	int pos {};
	for(int i {}; i < N; i++)
	{
		for(int j {}; j < N; j++)
		{
			if(grid_[i][j] == 0)
			{
				pos++;
				insertHelper(randPos, pos, i, j);
				return;
			}
		}
	}
};
