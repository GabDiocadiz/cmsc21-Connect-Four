#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define CHIP_DIAMETER 65.f
#define CHIP_X_GAP 35.75f
#define CHIP_Y_GAP 24.f

#define CHIP_FIRST_X 211
#define CHIP_FIRST_Y 112

class Chip {
    private:
        sf::Vector2f pos;
        sf::Color color;
        sf::CircleShape circle;
        sf::Texture texture;

        bool placed;

    public:
        Chip();

        sf::Vector2f getPos();
        int setPos(sf::Vector2f);
        sf::Color getColor();
        void setColor(sf::Color);
        void setTexture(sf::Texture);

        void place();
        void unplace();
        bool isPlaced();

        sf::CircleShape render();
};