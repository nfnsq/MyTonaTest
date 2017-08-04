#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Bird.h"
#include "Game.h"
#include "TubeUp.h"
#include "TubeDown.h"
#include "Menu.h"
#include "HighScores.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode(WIDTH, HEIGHT), "Flappy Bird");
	
	bool done = false;
	bool redraw = true;
	GameState gameState = MENU;
	HighScores highScores(&window);
	Menu menu(&window);
	Game game(&window);

	while (!done)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				done = true;
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (gameState == MENU)
				{
					switch (event.key.code) {
					case sf::Keyboard::Escape:
						done = true;
						window.close();
						break;
					case sf::Keyboard::Up:
						menu.Up();
						break;
					case sf::Keyboard::Down:
						menu.Down();
						break;
					case sf::Keyboard::Return:
						ActionMenu action = menu.Action();
						switch (action)
						{
						case NEWGAME:
							gameState = GAME;
							game.Run();
							gameState = MENU;
							break;
						case SCORES:
							highScores.Run();
							gameState = HSCORES;
							break;
						case QUIT:
							done = true;
							window.close();
							break;
						}
						break;
					}
				}
				else if (gameState == GAME) {
					game.Run();
					switch (event.key.code)
					{
					case sf::Keyboard::Escape: 
						gameState = MENU;
						done = false;
						break;
					}
					break;
				}
				else if (gameState == HSCORES) {
					highScores.Run();
					switch (event.key.code)
					{
					case sf::Keyboard::Escape:
						gameState = MENU;
						done = false;
						break;
					}
					break;
				}
			}
		}
		if (gameState == MENU) {
			menu.Render();
		}
		else if (gameState == HSCORES) {
			highScores.Render();
		}
	}
	return 0;
}