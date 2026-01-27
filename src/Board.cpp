#include "Board.hpp"

Board::Board()
{
	for(auto& row : board_)
	{
		row.fill(0);
	}
}
int Board::generateRand()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0,1);
	
	return (dist(gen) == 0) ? 2 : 4;
}

void insertHelper(Array2d& board, int randPos, int pos, int i, j)
{

	if(pos == randPos)
	{
		board[i][j] == generateRand();
	}
}

void Board::insertTwoOrFour(Array2d& board)
{
	int zeroCount {};
	for(int i {}; i < ROW; i++)
	{
		for(int j {}; j < COL; j++)
		{
			if(board[i][j] == 0)
				zeroCount++;
		}
	}

	if(zeroCount == 0) return;

	int randPos {rand() % zeroCount + 1};
	int pos {};
	for(int i {}; i < ROW; i++)
	{
		for(int j {}; j < COL; j++)
		{
			if(board[i][j] == 0)
			{
				pos++;
				insertHelper(board, rand, pos, i, j);
				return;
			}
		}
	}
};
