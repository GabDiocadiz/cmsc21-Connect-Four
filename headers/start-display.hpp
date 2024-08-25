#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "constants.hpp"

/* ELEMENT DIMENSIONS */
#define TITLE_FRAMES 18

#define START_BUTTON_WIDTH 621.f
#define START_BUTTON_HEIGHT 127.f
#define START_BUTTON_X_MARGIN 250.f
#define START_BUTTON_Y_MARGIN 495.f

#define HOW_BUTTON_WIDTH 182.f
#define HOW_BUTTON_HEIGHT 70.f
#define HOW_BUTTON_X_MARGIN 3.f
#define HOW_BUTTON_Y_MARGIN 630.f

#define LEADERBOARD_BUTTON_WIDTH 390.f
#define LEADERBOARD_BUTTON_HEIGHT 76.f
#define LEADERBOARD_BUTTON_X_MARGIN 673.f
#define LEADERBOARD_BUTTON_Y_MARGIN 15.f

class StartDisplay {
    private:
        sf::Texture titleTextures[TITLE_FRAMES];
        sf::RectangleShape title;

        // Start Button
        sf::Texture startButtonTextures[2];
        sf::RectangleShape startButton;
        sf::FloatRect startButtonRegion;

        // How Button
        sf::Texture howButtonTextures[2];
        sf::RectangleShape howButton;
        sf::FloatRect howButtonRegion;

        // Leaderboard Button
        sf::Texture leaderboardButtonTextures[2];
        sf::RectangleShape leaderboardButton;
        sf::FloatRect leaderboardButtonRegion;
    public:
        StartDisplay();

        sf::RectangleShape renderTitle();
        sf::RectangleShape renderStartButton();
        sf::RectangleShape renderHowButton();
        sf::RectangleShape renderLeaderboardButton();

        bool isOnStartButton(sf::Vector2i);
        bool isOnHowButton(sf::Vector2i);
        bool isOnLeaderboardButton(sf::Vector2i);

        void selectStart();
        void unselectStart();
        void selectHow();
        void unselectHow();
        void selectLeaderboard();
        void unselectLeaderboard();
};