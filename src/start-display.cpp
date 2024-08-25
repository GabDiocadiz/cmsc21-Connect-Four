#include "start-display.hpp"
#include <dos.h>

StartDisplay::StartDisplay() {
    // Title Sequence
    for (int i = 1; i <= TITLE_FRAMES; i++) {
        titleTextures[i-1].loadFromFile("assets/BGs/" + std::to_string(i) + ".png");
    }

    title.setPosition(0, 0);
    title.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    title.setTexture(&titleTextures[TITLE_FRAMES-1], true);

    // Start Button
    for (int i = 0; i < 2; i++) {
        startButtonTextures[i].loadFromFile("assets/Buttons/PLAY_" + std::to_string(i) + ".png");
    }

    startButton.setPosition(sf::Vector2f(START_BUTTON_X_MARGIN, START_BUTTON_Y_MARGIN));
    startButton.setSize(sf::Vector2f(START_BUTTON_WIDTH, START_BUTTON_HEIGHT));
    startButton.setTexture(&startButtonTextures[0]);

    startButtonRegion = sf::FloatRect(startButton.getPosition(), startButton.getSize());

    // How to Play Button
    for (int i = 0; i < 2; i++) {
        howButtonTextures[i].loadFromFile("assets/Buttons/HOW_" + std::to_string(i) + ".png");
    }

    howButton.setPosition(sf::Vector2f(HOW_BUTTON_X_MARGIN, HOW_BUTTON_Y_MARGIN));
    howButton.setSize(sf::Vector2f(HOW_BUTTON_WIDTH, HOW_BUTTON_HEIGHT));
    howButton.setTexture(&howButtonTextures[0]);

    howButtonRegion = sf::FloatRect(howButton.getPosition(), howButton.getSize());

    // Leaderboard Button
    for (int i = 0; i < 2; i++) {
        leaderboardButtonTextures[i].loadFromFile("assets/Buttons/LEADERBOARD_" + std::to_string(i) + ".png");
    }

    leaderboardButton.setPosition(sf::Vector2f(LEADERBOARD_BUTTON_X_MARGIN, LEADERBOARD_BUTTON_Y_MARGIN));
    leaderboardButton.setSize(sf::Vector2f(LEADERBOARD_BUTTON_WIDTH, LEADERBOARD_BUTTON_HEIGHT));
    leaderboardButton.setTexture(&leaderboardButtonTextures[0]);

    leaderboardButtonRegion = sf::FloatRect(leaderboardButton.getPosition(), leaderboardButton.getSize());
}


sf::RectangleShape StartDisplay::renderTitle() {
    return title;
}
        
sf::RectangleShape StartDisplay::renderStartButton() {
    return startButton;
}

sf::RectangleShape StartDisplay::renderHowButton() {
    return howButton;
}

sf::RectangleShape StartDisplay::renderLeaderboardButton() {
    return leaderboardButton;
}

bool StartDisplay::isOnStartButton(sf::Vector2i mousePos) {
    return startButtonRegion.contains(static_cast<sf::Vector2f>(mousePos));
}

bool StartDisplay::isOnHowButton(sf::Vector2i mousePos) {
    return howButtonRegion.contains(static_cast<sf::Vector2f>(mousePos));
}

bool StartDisplay::isOnLeaderboardButton(sf::Vector2i mousePos) {
    return leaderboardButtonRegion.contains(static_cast<sf::Vector2f>(mousePos));
}

void StartDisplay::selectStart() {
    startButton.setTexture(&startButtonTextures[1]);
}

void StartDisplay::unselectStart() {
    startButton.setTexture(&startButtonTextures[0]);
}

void StartDisplay::selectHow() {
    howButton.setTexture(&howButtonTextures[1]);
}

void StartDisplay::unselectHow() {
    howButton.setTexture(&howButtonTextures[0]);
}

void StartDisplay::selectLeaderboard() {
    leaderboardButton.setTexture(&leaderboardButtonTextures[1]);
}

void StartDisplay::unselectLeaderboard() {
    leaderboardButton.setTexture(&leaderboardButtonTextures[0]);
}