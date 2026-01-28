#include <SFML/Graphics.hpp>
#include "../include/Board.hpp"
#include "../include/Move.hpp"
#include <time.h>
#include <iostream>



int main()
{
   sf::RenderWindow window (sf::VideoMode(800,800), "2048");
    
    //board test
    Board board;

    sf::Text text;
    sf::Font font;
    
    if(!font.loadFromFile("./assets/fonts/BitcountSingle-Regular.ttf"))
    {
	std::cout << "Font file not found" << std::endl;
    }
    

    text.setFont(font);
    text.setCharacterSize(30);
    text.setString("hellllvdvdxl");
    text.setFillColor(sf::Color::Red);
    
//    board.set(0, 3, 2);
//    board.set(2, 3, 2);
  
//     for(std::size_t i {}; i < 4; i++)
//     {
//         for(std::size_t j {}; j < 4; j++)
//         {
//             std::cout << board.get(i, j) << ' ';
//         }
//         std::cout << '\n';
//     }
//     std::cout << '\n';
//     while(true)
//     {
//         char input;
//         std::cin >> input;
//         if(input == 'w') moves::apply(board, moves::Directions::UP);
//         else if(input == 'a')moves::apply(board, moves::Directions::LEFT);
//         else if(input == 'd')moves::apply(board, moves::Directions::RIGHT);
//         else moves::apply(board, moves::Directions::DOWN);
//         board.insertTwoOrFour();
//         for(std::size_t i {}; i < 4; i++)
//         {
//             for(std::size_t j {}; j < 4; j++)
//             {
//                 std::cout << board.get(i, j) << ' ';
//             }
//             std::cout << '\n';
//         }
       // board.insertTwoOrFour();

       
    //}
   

        while(window.isOpen())
        {
            sf::Event e;
            while(window.pollEvent(e))
            {
                if(e.type == sf::Event::Closed) window.close();
            }
        window.clear();
	    window.draw(text);
        window.display();
    }
    return 0;
}
