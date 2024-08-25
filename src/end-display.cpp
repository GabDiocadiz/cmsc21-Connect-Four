#include "end-display.hpp"

EndDisplay::EndDisplay() {
    // Background
    for (int i = 0; i < 3; i++) {
       results[i].loadFromFile("assets/BGs/END_" + std::to_string(i) + ".png", sf::IntRect());
    }

    resultDisplay.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    resultDisplay.setTexture(&results[0], true);
    resultDisplay.setPosition(0, 0);

    // Button
    for (int i = 0; i < 2; i++) {
       returnTextures[i].loadFromFile("assets/Buttons/BACK_" + std::to_string(i) + ".png", sf::IntRect());
    }

    returnButton.setSize(sf::Vector2f(RETURN_BUTTON_WIDTH, RETURN_BUTTON_HEIGHT));
    returnButton.setTexture(&returnTextures[0], true);
    returnButton.setPosition(RETURN_BUTTON_X_MARGIN, RETURN_BUTTON_Y_MARGIN);

    returnButtonRegion = sf::FloatRect(returnButton.getPosition(), returnButton.getSize());
}


void EndDisplay::setResult(int result) {
    resultDisplay.setTexture(&results[result-1]);
}

sf::RectangleShape EndDisplay::renderResult() {
    return resultDisplay;
}

sf::RectangleShape EndDisplay::renderReturnButton() {
    return returnButton;
}


bool EndDisplay::isOnReturn(sf::Vector2i mousePos) {
    return returnButtonRegion.contains(static_cast<sf::Vector2f>(mousePos));
}

void EndDisplay::selectReturn() {
    returnButton.setTexture(&returnTextures[1]);
}

void EndDisplay::unselectReturn() {
    returnButton.setTexture(&returnTextures[0]);
}