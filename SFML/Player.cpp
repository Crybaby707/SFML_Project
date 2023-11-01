#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float frameTime, float speed, std::vector<sf::Texture*> textureList)
{
    this->speed = speed;
    this->texture = texture;
    texture = this->texture;
    this->textureList = textureList;
    row = 0;
    faceRight = true;
    comboCheck = 0;

    // Створити окремий спрайт для відображення анімації
    animationSprite.setTexture(*textureList[0]);
    animationSprite.setTextureRect(sf::IntRect(0, 0, 80, 80)); // Встановити розмір спрайту
    sf::FloatRect bounds = animationSprite.getLocalBounds();
    float centerX = bounds.width / 2.0f;
    float centerY = bounds.height / 2.0f;
    animationSprite.setOrigin(centerX, centerY);
    animationSprite.setPosition(206.0f, 206.0f);

    gameController.AddAnimation(texture, imageCount, frameTime);
    currentAnimationType = "Run";
    itsAttack = false;
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (!itsAttack)) {
        movement.x -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (!itsAttack)) {
        movement.x += speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        if (!itsAttack) {
            if (currentTime - comboTime > 0.9f) {
                comboCheck = 0;  // Обнулення comboCheck, якщо пройшло більше 0.5 секунд з останнього комбо
            }

            gameController.animationCheck = true;
            gameController.AnimtaionStop();
            itsAttack = true;
            animationCheck = true;
            currentAnimationType = "Attack";
            if (comboCheck < 2) {
                animationSprite.setTexture(*textureList[(2 + comboCheck)]);
                gameController.UpdateTexture(textureList[2 + comboCheck], sf::Vector2u(3, 1));
            }
            else {
                animationSprite.setTexture(*textureList[(2 + comboCheck)]);
                gameController.UpdateTexture(textureList[2 + comboCheck], sf::Vector2u(6, 1));
            }
            comboCheck++;
            if (comboCheck == 3) {
                comboCheck = 0;
            }
        }
        comboTime = currentTime;  // Зберегти час натискання клавіші "X" у comboTime
    }
    else if (gameController.animationCheck == false) {
        itsAttack = false;
        // comboTime += deltaTime; // Не потрібно більше цього рядка
    }

    if (!itsAttack) {
        if (movement.x == 0.0f && movement.y == 0.0f) {
            currentAnimationType = "Idle";
            animationSprite.setTexture(*textureList[0]);
            gameController.UpdateTexture(textureList[0], sf::Vector2u(8, 1));
        }
        else {
            if (movement.x > 0.0f && movement.y == 0.0f) {
                faceRight = true;
                currentAnimationType = "Run";
                animationSprite.setTexture(*textureList[1]);
                gameController.UpdateTexture(textureList[1], sf::Vector2u(8, 1));
            }
            else if (movement.x < 0.0f && movement.y == 0.0f) {
                faceRight = false;
                currentAnimationType = "Run";
                animationSprite.setTexture(*textureList[1]);
                gameController.UpdateTexture(textureList[1], sf::Vector2u(8, 1));
            }
        }
    }

    gameController.Update(row, deltaTime, faceRight);
    animationSprite.setTextureRect(gameController.uvRect);
    animationSprite.move(movement);

    currentTime += deltaTime;
}


void Player::Draw(sf::RenderWindow& window)
{
    window.draw(animationSprite);
}
