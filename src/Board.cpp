#include "../include/Board.hpp"
#include <random>

Board::Board()
{
	for(auto& it : grid_)
	{
		it.fill(0);
	}
}
void Board::reset()
{
	for(auto& it : grid_)
	{
		it.fill(0);
	}
}

int Board::spawnRandomTile()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0,1);
	
	return (dist(gen) == 0) ? 2 : 4;
}

void Board::insertHelper(int randPos, int pos, std::size_t r, std::size_t c)
{

	if(pos == randPos)
	{
		set(r, c, spawnRandomTile());
	}
}

void Board::insertTwoOrFour()
{
	int zeroCount {};
	for(std::size_t r {}; r < N; r++)
	{
		for(std::size_t c {}; c < N; c++)
		{
			if(grid_[r][c] == 0)
				zeroCount++;
		}
	}

	if(zeroCount == 0) return;
	
	// fixed an edge case, where if there was only one zero left,
	// it wouldnt fill in that tile with a two or four
	if(zeroCount == 1)
	{
		for(std::size_t r {}; r < N; r++)
		{
			for(std::size_t c {}; c < N; c++)
			{
				if(grid_[r][c] == 0) 
					grid_[r][c] = spawnRandomTile();
				
			}
		}
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0,10000);
	
	int randPos {dist(gen) % zeroCount + 1};
	int pos {};
	for(std::size_t r {}; r < N; r++)
	{
		for(std::size_t c {}; c < N; c++)
		{
			if(grid_[r][c] == 0)
			{
				
				insertHelper(randPos, pos, r, c);
				pos++;
				if(grid_[r][c] != 0) return;
			}
		}
	}
}
bool Board::isAdj(std::size_t r, std::size_t c) const
{
	int current = grid_[r][c];
           
    // Check right
    if(c + 1 < N && grid_[r][c + 1] == current)
        return true;
            
    // Check down
    if(r + 1 < N && grid_[r + 1][c] == current)
        return true;
    
    // Check left
    if(c > 0 && grid_[r][c - 1] == current)
        return true;
    
    // Check up
    if(r > 0 && grid_[r - 1][c] == current)
        return true;

	return false;
    
}
bool Board::canMove() const
{
	for(std::size_t r {}; r < N; r++)
	{
		for(std::size_t c {}; c < N; c++)
		{
			if(grid_[r][c] == 0 || isAdj(r, c))
			{
				return true;
			}

		}
	}
	return false;
}

bool Board::isEqual(Board board2) const
{
	for(std::size_t r { }; r < N; r++)
	{
		for(std::size_t c { }; c < N; c++)
		{
			if(grid_[r][c] != board2.get(r, c))
				return false;
		}
	}
	return true;
}

Board& Board::operator=(const Board& b)
{
	if(this == &b) return *this;
	for(std::size_t r { }; r < N; r++)
	{
		for(std::size_t c { }; c < N; c++)
		{
			grid_[r][c] = b.get(r,c);
		}
	}
	return *this;
}