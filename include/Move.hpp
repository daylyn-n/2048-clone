#ifndef MOVE_HPP
#define MOVE_HPP

#include <cstdint>

class Board;
namespace moves
{
	enum Directions
{
	LEFT, UP, DOWN, RIGHT
};

	struct MoveResult
	{
		bool moved {false};
		int scoreGained {};
		bool won {false};
	};

	MoveResult apply(Board& board, Directions dir);
};

#endif
