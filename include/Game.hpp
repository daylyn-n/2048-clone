#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Board.hpp"

enum State
{
	Playing, Quit
};
class Game
{
	private:
		static int score_;
	
	public:
		Game();
		void start();
		void restart(); // initiliaze board values to 0
		void quit();
		void displayScore(int score);


};

#endif
