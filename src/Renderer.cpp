#include "../include/Renderer.hpp"
#include <iostream>
#include <cstdint>

Renderer::Renderer(sf::Font& font) : font_(font)
{
    if(!font.loadFromFile("./assets/fonts/BitcountSingle-Regular.ttf"))
    {
        throw "Could not open font folder";
    }
}


void Renderer::draw(sf::RenderWindow &window, 
		Board& board,
        int score)
{
	const int N {4};
	const float tileSize {120.f};
	const float gap {10.f};
	const sf::Vector2f origin(40.f, 40.f);

	sf::RectangleShape tile;
	tile.setSize({tileSize, tileSize});
    unsigned int fsize = 49;
    sf::Text tilePts;
    tilePts.setFont(font_);
    tilePts.setColor(sf::Color::Red);
    tilePts.setCharacterSize(fsize);

    sf::Text scoreText;
    scoreText.setFont(font_);
    scoreText.setCharacterSize(60.0f);

	for(std::size_t i {}; i < N; i++)
	{
		for(std::size_t j {}; j < N; j++)
		{
			float x = origin.x + j * (tileSize + gap);
			float y = origin.y + i * (tileSize + gap);

			tile.setPosition(x,y);

            std::string value = std::to_string(board.get(i, j));
          
          
			window.draw(tile);
            tilePts.setString(value);
            sf::FloatRect textBounds = tilePts.getLocalBounds();
            
            
            tilePts.setOrigin(textBounds.left + textBounds.width / 2.0f,
                                textBounds.top + textBounds.height / 2.0f);
            tilePts.setPosition(x + tileSize / 2.0f, y + tileSize / 2.0f);
        
            window.draw(tilePts);
		}
	}
}
