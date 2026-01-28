#include <SFML/Graphics.hpp>
#include <array>
#include <time.h>

void drawB(sf::RenderWindow &window, 
		std::array<std::array<int,4>, 4> board)
{
	constexpr int N {4};
	constexpr float tileSize {120.f};
	constexpr float gap {10.f};
	constexpr sf::Vector2f origin(40.f, 40.f);

	sf::RectangleShape tile;
	tile.setSize({tileSize, tileSize});


	for(int i {}; i < N; i++)
	{
		for(int j {}; j < N; j++)
		{
			float x = origin.x + i * (tileSize + gap);
			float y = origin.y + j * (tileSize + gap);

			tile.setPosition(x,y);
			window.draw(tile);
		}
	}
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "2048");

	std::array<std::array<int, 4>, 4> board
	{{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	 }};
	while(window.isOpen())
	{
		sf::Event e;

		while(window.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
				window.close();
		}

		drawB(window, board);
		window.display();
	
		
	}

}
