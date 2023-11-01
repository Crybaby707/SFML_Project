#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

static const float windowHeight = 512.0f;
static const float windowWidht = 512.0f;

void ResizeWindow(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(512.0f * aspectRatio, 512.0f);
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(windowHeight, windowWidht));

	sf::Texture playerTexture;
	sf::Texture playerRunTexture;
	sf::Texture playerFirstAttackTexture;
	sf::Texture playerSecondAttackTexture;
	sf::Texture playerJumpTexture;
	sf::Texture playerDashTexture;
	sf::Texture playerThirdAttackTexture;

	playerTexture.loadFromFile("images/Idle.png");
	playerRunTexture.loadFromFile("images/Run.png");
	playerFirstAttackTexture.loadFromFile("images/Attack01.png");
	playerSecondAttackTexture.loadFromFile("images/Attack02.png");
	playerThirdAttackTexture.loadFromFile("images/Attack03.png");
	playerJumpTexture.loadFromFile("images/Jump.png");
	playerDashTexture.loadFromFile("images/Dash1.png");
	
	

	std::vector<sf::Texture*> textureList;
	
	textureList.push_back(&playerTexture);
	textureList.push_back(&playerRunTexture);
	textureList.push_back(&playerFirstAttackTexture);
	textureList.push_back(&playerSecondAttackTexture);
	textureList.push_back(&playerThirdAttackTexture);
	textureList.push_back(&playerJumpTexture);

	//sf::Sprite sprite1(*textureList[0]);


	GameController gameController;

	Player player(&playerTexture, sf::Vector2u(8, 1), 0.3f, 200.0f, textureList);

	float deltaTime = 0.0f;
	sf::Clock clock;


	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeWindow(window, view);
				break;
			}
		}

		player.Update(deltaTime);
		//view.setCenter(player.GetPosition());


		window.clear(sf::Color::White);
		window.setView(view);
		player.Draw(window);
		window.display();

	}

	return 0;


};