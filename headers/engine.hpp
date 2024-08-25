#include <SFML/Graphics.hpp>
#include <string>
#include "constants.hpp"
#include "game-states.hpp"
#include "start-display.hpp"
#include "leaderboard-display.hpp"
#include "playerSelect-display.hpp"
#include "how-display.hpp"
#include "board-display.hpp"
#include "end-display.hpp"
#include "board.hpp"
#include "sound-effect.hpp"

using namespace std;

class Engine {
    private:
        sf::RenderWindow window;
        sf::Music bgmusic;
        SoundEffect click;
        SoundEffect chipDrop;
        SoundEffect gameEnd;
        sf::Font font;

        GameState state;

        StartDisplay startMenu;
        LeaderboardDisplay leaderboardMenu;
        HowDisplay howMenu;

        PlayerSelectDisplay playerSelectMenu;

        BoardDisplay board;
        Board boardLogic;

        EndDisplay endMenu;
    
        void processEvents();
        void update();
        void render();

        void resetBoard();

        void handleStartInput(sf::Event);
        void handleLeaderboardInput(sf::Event);
        void handleHowInput(sf::Event);
        void handlePlayerSelectInput(sf::Event);
        void handleGameInput(sf::Event);
        void handleEndInput(sf::Event);

        void renderStart();
        void renderLeaderboard();
        void renderHow();
        void renderPlayerSelect();
        void renderGame();
        void renderEnd();

    public:
        string player;
        string player1;
        string player2;

        Engine();
        void run();
};