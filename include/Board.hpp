#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <random>

class Board
{
	
	public:
		static constexpr std::size_t N = 4;
		using Grid = std::array<std::array<int, N>, N>;

		Board();

		void reset();                    
		int spawnRandomTile();   
		void insertHelper(int randPos, int pos, std::size_t row, std::size_t col);
		void insertTwoOrFour();  
		bool isAdj(std::size_t r, std::size_t c) const;    
		bool canMove() const;            
		bool isGameOver() const { return !canMove(); }

		int  get(std::size_t r, std::size_t c) const { return grid_[r][c]; }
		void set(std::size_t r, std::size_t c, int value) { grid_[r][c] = value; }

		const Grid& grid() const { return grid_; }   // renderer can read
		Grid& grid() { return grid_; }               
	private:
		Grid grid_;
};

#endif

