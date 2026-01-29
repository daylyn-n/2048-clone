#ifndef MOVE_HPP
#define MOVE_HPP

#include <cstdint>
#include <array>
#include "Board.hpp"


namespace moves
{
	enum Directions : uint8_t
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
	void moveLine(std::array<int, 4> &line, MoveResult &res);
};
#endif
