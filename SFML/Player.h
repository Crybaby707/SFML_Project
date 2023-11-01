#pragma once
#include <SFML/Graphics.hpp>
#include "GameController.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float frameTime, float speed, std::vector<sf::Texture*>);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return animationSprite.getPosition(); }

private:
	sf::RectangleShape body;
	GameController gameController;
	unsigned int row;
	float speed;
	bool faceRight;
	std::string currentAnimationType;
	std::vector<sf::Texture*> textureList;
	sf::Texture* texture;
	bool itsAttack;
	sf::Sprite animationSprite;
	bool animationCheck;
	float comboTime;
	int comboCheck;
	float currentTime;
};
