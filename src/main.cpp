#include <SFML/Graphics.hpp>
#include "../include/Board.hpp"
#include "../include/Move.hpp"
#include "../include/Renderer.hpp"
#include <time.h>
#include <iostream>



int main()
{
    sf::RenderWindow window (sf::VideoMode(800,800), "2048");
    
    sf::Font font;
    font.loadFromFile("./assets/fonts/BitcountSingle-Regular.ttf");
    //board test
    Board board;
    Renderer boardView(font);
    board.insertTwoOrFour();
    board.insertTwoOrFour();
    



    // sf::Text text;

    
    // // if(!font.loadFromFile("./assets/fonts/BitcountSingle-Regular.ttf"))
    // // {
	// // std::cout << "Font file not found" << std::endl;
    // // }
    

    // // text.setFont(font);
    // // text.setCharacterSize(30);
    // // text.setString("hellllvdvdxl");
    // // text.setFillColor(sf::Color::Red);


    
//    board.set(0, 3, 2);
//    board.set(2, 3, 2);
  
    
       
    boardView.draw(window, board, 0);
   
    

    while(window.isOpen())
    {
        sf::Event e;
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed) window.close();
            // key presses
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
               
                moves::MoveResult res = moves::apply(board, moves::Directions::UP);
                if(res.moved)
                    board.insertTwoOrFour();
              
                
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                
                moves::MoveResult res = moves::apply(board, moves::Directions::LEFT);
                if(res.moved)
                    board.insertTwoOrFour();
               
               
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                moves::MoveResult res = moves::apply(board, moves::Directions::RIGHT);
                 if(res.moved)
                    board.insertTwoOrFour();
         
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                moves::MoveResult res = moves::apply(board, moves::Directions::DOWN);
                 if(res.moved)
                    board.insertTwoOrFour();
               
                
            }
        }
      
        window.clear();
        boardView.draw(window, board, 0);
        window.display();
    }
    
}

    

