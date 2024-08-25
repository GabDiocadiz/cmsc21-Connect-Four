#include "how-display.hpp"

HowDisplay::HowDisplay() {
    // Background

    background.loadFromFile("assets/BGs/HOW.png");
    howDisplay.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    howDisplay.setTexture(&background, true);
    howDisplay.setPosition(0, 0);

    // Button
    for (int i = 0; i < 2; i++) {
       returnTextures[i].loadFromFile("assets/Buttons/BACK_" + std::to_string(i) + ".png", sf::IntRect());
    }

    returnButton.setSize(sf::Vector2f(HOW_RETURN_BUTTON_WIDTH, HOW_RETURN_BUTTON_HEIGHT));
    returnButton.setTexture(&returnTextures[0], true);
    returnButton.setPosition(HOW_RETURN_BUTTON_X_MARGIN, HOW_RETURN_BUTTON_Y_MARGIN);

    returnButtonRegion = sf::FloatRect(returnButton.getPosition(), returnButton.getSize());
}


sf::RectangleShape HowDisplay::renderHow() {
    return howDisplay;
}

sf::RectangleShape HowDisplay::renderReturnButton() {
    return returnButton;
}


bool HowDisplay::isOnReturn(sf::Vector2i mousePos) {
    return returnButtonRegion.contains(static_cast<sf::Vector2f>(mousePos));
}

void HowDisplay::selectReturn() {
    returnButton.setTexture(&returnTextures[1]);
}

void HowDisplay::unselectReturn() {
    returnButton.setTexture(&returnTextures[0]);
}