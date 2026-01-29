#include "../include/Renderer.hpp"
#include <iostream>
#include <cstdint>

// helper function for giving different colors based on the points
void setTileColor(int value, sf::RectangleShape &tile); 
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
    unsigned int fsize {50};
    sf::Text tilePts;
    tilePts.setFont(font_);
    tilePts.setColor(sf::Color::White);
    tilePts.setCharacterSize(fsize);
    tilePts.setStyle(sf::Text::Bold);

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
            
            int value = board.get(i, j);
            if(value == 0)
                tile.setFillColor(sf::Color(255, 255, 255));
            else
                setTileColor(value, tile);

            window.draw(tile);
            
            std::string sValue = std::to_string(board.get(i, j));
            
            tilePts.setString(sValue);
            sf::FloatRect textBounds = tilePts.getLocalBounds();
            
            
            tilePts.setOrigin(textBounds.left + textBounds.width / 2.0f,
                                textBounds.top + textBounds.height / 2.0f);
            tilePts.setPosition(x + tileSize / 2.0f, y + tileSize / 2.0f);
                
            if(value != 0)
                window.draw(tilePts);
		}
	}
}
void setTileColor(int value, sf::RectangleShape &tile)
{
     
    switch(value)
    {   
                    
        case 2:
            tile.setFillColor(sf::Color(207, 205, 205));
            break;
        case 4:
            tile.setFillColor(sf::Color(230, 201, 141));
            break;
        case 8:
            tile.setFillColor(sf::Color(250, 179, 55));
            break;
        case 16:
            tile.setFillColor(sf::Color(237, 99, 247));
            break;
        case 32:
            tile.setFillColor(sf::Color(29, 255, 237));
            break;
        case 64:
            tile.setFillColor(sf::Color(0, 255, 92));
            break;
        case 128:
            tile.setFillColor(sf::Color(160, 0, 144));
            break;
        case 256:
            tile.setFillColor(sf::Color(72, 255, 0));
            break;
        case 512:
            tile.setFillColor(sf::Color(255, 255, 0));
            break;
        case 1024:
            tile.setFillColor(sf::Color(255, 143, 0));
            break;
        case 2048:
            tile.setFillColor(sf::Color(255, 0, 2));
            break;
                    
    }
                
            
}