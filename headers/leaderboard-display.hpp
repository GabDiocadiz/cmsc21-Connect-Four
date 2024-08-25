#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "constants.hpp"
#include "leaderboard.hpp"
#include "textbox.hpp"

/* ELEMENT DIMENSIONS */
#define BACKLEAD_BUTTON_WIDTH 395.f
#define BACKLEAD_BUTTON_HEIGHT 78.f
#define BACKLEAD_BUTTON_X_MARGIN 343.f
#define BACKLEAD_BUTTON_Y_MARGIN 610.f

class LeaderboardDisplay {
    private:
        sf::Texture leaderboardTexture;
        sf::RectangleShape leaderboardDisplay;

        // Back Button
        sf::Texture backButtonTextures[2];
        sf::RectangleShape backButton;
        sf::FloatRect backButtonRegion;

    public:
        LeaderboardDisplay();
        Leaderboard leaderboard;

        Textbox entryNames[5];
        Textbox entryScores[5];
        sf::Font font;

        sf::RectangleShape renderLeaderboard();
        sf::RectangleShape renderBackButton();

        bool isOnBackButton(sf::Vector2i);

        void selectBack();
        void unselectBack();

        void updateBoard();
};