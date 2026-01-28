#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include "Board.hpp"
class Renderer
{
    public:
        Renderer(sf::Font &font);
        void draw(sf::RenderWindow &window, Board& board, int score);

    private:
        sf::Font font_;

};

#endif
