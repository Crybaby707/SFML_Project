#include <SFML/Graphics.hpp>
#include <unordered_map>

class GameController
{
public:
    void AddAnimation(sf::Texture* texture, sf::Vector2u imageCount, float frameTime);
    ~GameController();

    bool UpdateTexture(sf::Texture* texture, sf::Vector2u imageCount);
    void Update(int row, float deltaTime, bool faceRight);
    std::string GetCurrentAnimationType() const;
    void AnimtaionStop();

    //void UpdateTexture(sf::Texture* texture);

    sf::IntRect uvRect;
    bool animationCheck;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float frameTime = 0.2f;
    float timer = 0;
};