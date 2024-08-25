#include <SFML/Graphics.hpp>
#include "constants.hpp"

#define HOW_RETURN_BUTTON_WIDTH 625.f
#define HOW_RETURN_BUTTON_HEIGHT 127.f
#define HOW_RETURN_BUTTON_X_MARGIN 227.5f
#define HOW_RETURN_BUTTON_Y_MARGIN 635.f

class HowDisplay {
    private:
        sf::Texture background;
        sf::RectangleShape howDisplay;

        sf::Texture returnTextures[2];
        sf::RectangleShape returnButton;
        sf::FloatRect returnButtonRegion;

    public:
        HowDisplay();

        sf::RectangleShape renderHow();
        sf::RectangleShape renderReturnButton();

        bool isOnReturn(sf::Vector2i);
        void selectReturn();
        void unselectReturn();
};