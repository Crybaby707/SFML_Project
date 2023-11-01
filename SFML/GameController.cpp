#include "GameController.h"

void GameController::AddAnimation(sf::Texture* texture, sf::Vector2u imageCount, float frameTime)
{
    this->imageCount = imageCount;
    this->frameTime = frameTime;
    timer = 0.0f;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
    //UpdateTexture(texture);

}

GameController::~GameController()
{

    
}


void GameController::AnimtaionStop()
{

    currentImage.x = 0;

}

bool GameController::UpdateTexture(sf::Texture* texture, sf::Vector2u imageCount)
{
    this->imageCount = imageCount;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);


    return true;
}

void GameController::Update(int row, float deltaTime, bool faceRight)
{
    currentImage.y = row;

    timer += deltaTime;

    if (currentImage.x >= imageCount.x) {
        currentImage.x = 0;

    }



    if (timer >= frameTime) {
        timer = 0;
        currentImage.x++;


        if (currentImage.x >= imageCount.x) {
            currentImage.x = 0;
            animationCheck = false;
        }
    }


    uvRect.top = currentImage.y * uvRect.height;

    if (faceRight)
    {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }

}