#ifndef MOVE_HPP
#define MOVE_HPP

#include "Board.hpp"
enum Directions
{
	LEFT, UP, DOWN, RIGHT
};
class Move
{
	private:
		Directions dir_;
	public:
		// move left
		void moveLeft(Board& board)
		void compressLeft(Board& board);
		void mergeLeft(Board& board);

		// move up
		void moveUp(Board& board)
		void compressUp(Board& board);
		void mergeUp(Board& board);

		// move down
		void moveDown(Board& board)
		void compressDown(Board& board);
		void mergeDown(Board& board);

		// move right
		void moveRight(Board& board)
		void compressRight(Board& board);
		void mergeRight(Board& board);
	
};

#endif
