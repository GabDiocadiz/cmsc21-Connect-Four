#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "constants.hpp"
#include "textbox.hpp"

/* ELEMENT DIMENSIONS */
#define SEL_BUTTONS_WIDTH 395.f
#define SEL_BUTTONS_HEIGHT 78.f
#define BACKSEL_BUTTON_X_MARGIN 343.f
#define BACKSEL_BUTTON_Y_MARGIN 553.f
#define ENTER_BUTTON_X_MARGIN 343.f
#define ENTER_BUTTON_Y_MARGIN 433.f

class PlayerSelectDisplay {
    private:
        sf::Texture playerSelectTextures[3];
        sf::RectangleShape playerSelectDisplay;
        int player;

        // Back Button
        sf::Texture backButtonTextures[2];
        sf::RectangleShape backButton;
        sf::FloatRect backButtonRegion;

        // Enter Button
        sf::Texture enterButtonTextures[2];
        sf::RectangleShape enterButton;
        sf::FloatRect enterButtonRegion;

        // Text Input
        
        sf::Font font;

    public:
        PlayerSelectDisplay();
        Textbox textInput;

        sf::RectangleShape renderPlayerSelect();
        sf::RectangleShape renderBackButton();
        sf::RectangleShape renderEnterButton();

        bool isOnBackButton(sf::Vector2i);
        bool isOnEnterButton(sf::Vector2i);

        void selectBack();
        void unselectBack();
        void selectEnter();
        void unselectEnter();

        void switchPlayer(int);
};