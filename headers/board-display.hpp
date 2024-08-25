#include "constants.hpp"
#include "chip.hpp"

#define ROWS 6
#define COLUMNS 7

#define BOARD_X_MARGIN 168
#define BOARD_Y_MARGIN 71

#define UNDO_BUTTON_WIDTH 284.f
#define UNDO_BUTTON_HEIGHT 55.f
#define UNDO_BUTTON_X_MARGIN 399.f
#define UNDO_BUTTON_Y_MARGIN 654.f

class BoardDisplay {
    private:
        sf::Texture backgrounds[3];
        sf::RectangleShape background;

        sf::Texture boardTexture;
        sf::RectangleShape board;

        sf::Texture chipTextures[2];
        Chip displayGrid[ROWS][COLUMNS];

        sf::FloatRect columnRegions[COLUMNS];

        // Back Button
        sf::Texture undoButtonTextures[2];
        sf::RectangleShape undoButton;
        sf::FloatRect undoButtonRegion;
    public:
        BoardDisplay();

        sf::RectangleShape renderBackground();
        sf::RectangleShape renderBoard();
        sf::RectangleShape renderUndo();

        Chip getCell(int, int);
        void placeCell(int, int, int);
        void resetCells();

        void setTurn(int);

        bool isOnColumn(sf::Vector2i, int);
        bool isOnUndoButton(sf::Vector2i);

        void selectColumn(int);
        void unselectColumn(int);
        void selectUndo();
        void unselectUndo();
};