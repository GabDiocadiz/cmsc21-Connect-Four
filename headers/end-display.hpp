#include <SFML/Graphics.hpp>
#include "constants.hpp"

#define RETURN_BUTTON_WIDTH 625.f
#define RETURN_BUTTON_HEIGHT 127.f
#define RETURN_BUTTON_X_MARGIN 227.5f
#define RETURN_BUTTON_Y_MARGIN 535.f

class EndDisplay {
    private:
        sf::Texture results[3];
        sf::RectangleShape resultDisplay;

        sf::Texture returnTextures[2];
        sf::RectangleShape returnButton;
        sf::FloatRect returnButtonRegion;

    public:
        EndDisplay();

        void setResult(int);

        sf::RectangleShape renderResult();
        sf::RectangleShape renderReturnButton();

        bool isOnReturn(sf::Vector2i);
        void selectReturn();
        void unselectReturn();
};