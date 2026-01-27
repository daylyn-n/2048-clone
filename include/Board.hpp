#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <random>
#include <SFML/Graphics.hpp>

constexpr int ROW {4};
constexpr int COL {4};
constexpr int SIZE {4};

template <typename T, std::size_t Row, std::size_t Col>
using Array2d {std::array<std::array<T, Col>, Row>};

class Board
{
	private:
		Array2d board_<int, ROW, COL>;
	
	public:
		Board();
		void initializeBoard(Array2d &board);
		void drawBoard(sf::RenderWindow& window, Array2d board);
		bool isGameOver(Array2d &board);
		void insertTwoOrFour(Array2d &board);
		int generateRand();
};

#endif

