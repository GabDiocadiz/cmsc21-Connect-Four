#include "playerSelect-display.hpp"

PlayerSelectDisplay::PlayerSelectDisplay() {
    // Background
    for (int i = 0; i < 3; i++) {
       playerSelectTextures[i].loadFromFile("assets/BGs/PLAYERSELECT_" + std::to_string(i) + ".png", sf::IntRect());
    }

    playerSelectDisplay.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    playerSelectDisplay.setTexture(&playerSelectTextures[0], true);
    playerSelectDisplay.setPosition(0, 0);

    // Back Button
    for (int i = 0; i < 2; i++) {
        backButtonTextures[i].loadFromFile("assets/Buttons/BACKLEAD_" + std::to_string(i) + ".png");
    }

    backButton.setPosition(sf::Vector2f(BACKSEL_BUTTON_X_MARGIN, BACKSEL_BUTTON_Y_MARGIN));
    backButton.setSize(sf::Vector2f(SEL_BUTTONS_WIDTH, SEL_BUTTONS_HEIGHT));
    backButton.setTexture(&backButtonTextures[0]);

    backButtonRegion = sf::FloatRect(backButton.getPosition(), backButton.getSize());

    // Enter Button
    for (int i = 0; i < 2; i++) {
        enterButtonTextures[i].loadFromFile("assets/Buttons/ENTER_" + std::to_string(i) + ".png");
    }

    enterButton.setPosition(sf::Vector2f(ENTER_BUTTON_X_MARGIN, ENTER_BUTTON_Y_MARGIN));
    enterButton.setSize(sf::Vector2f(SEL_BUTTONS_WIDTH, SEL_BUTTONS_HEIGHT));
    enterButton.setTexture(&enterButtonTextures[0]);

    enterButtonRegion = sf::FloatRect(enterButton.getPosition(), enterButton.getSize());

    // Text Input
    font.loadFromFile("assets/Fonts/GamestationCond.otf");
    textInput = Textbox(72, sf::Color::White, true);
    textInput.setPosition({252, 304});
    textInput.setFont(font);
    textInput.setLimit(true, 15);
}

sf::RectangleShape PlayerSelectDisplay::renderPlayerSelect() {
    return playerSelectDisplay;
}
sf::RectangleShape PlayerSelectDisplay::renderBackButton() {
    return backButton;
}
sf::RectangleShape PlayerSelectDisplay::renderEnterButton() {
    return enterButton;
}

bool PlayerSelectDisplay::isOnBackButton(sf::Vector2i mousePos) {
    return backButtonRegion.contains(static_cast<sf::Vector2f>(mousePos));
}
bool PlayerSelectDisplay::isOnEnterButton(sf::Vector2i mousePos) {
    return enterButtonRegion.contains(static_cast<sf::Vector2f>(mousePos));
}

void PlayerSelectDisplay::selectBack() {
    backButton.setTexture(&backButtonTextures[1]);
}
void PlayerSelectDisplay::unselectBack() {
    backButton.setTexture(&backButtonTextures[0]);
}
void PlayerSelectDisplay::selectEnter() {
    enterButton.setTexture(&enterButtonTextures[1]);
}
void PlayerSelectDisplay::unselectEnter() {
    enterButton.setTexture(&enterButtonTextures[0]);
}

void PlayerSelectDisplay::switchPlayer(int player) {
    playerSelectDisplay.setTexture(&playerSelectTextures[player], true);
}