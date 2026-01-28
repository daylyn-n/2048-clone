#include <SFML/Graphics.hpp>
#include "../include/Board.hpp"
#include <time.h>
#include <iostream>



int main()
{
    sf::RenderWindow window (sf::VideoMode(800,800), "2048");
    
    //board test
    Board board;
  
    for(std::size_t i {}; i < 4; i++)
    {
        for(std::size_t j {}; j < 4; j++)
        {
            std::cout << board.get(i, j) << ' ';
        }
        std::cout << '\n';
    }

    while(window.isOpen())
    {
        sf::Event e;
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed) window.close();
        }
    }
    return 0;
}
