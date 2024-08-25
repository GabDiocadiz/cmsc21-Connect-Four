#include "leaderboard-display.hpp"

LeaderboardDisplay::LeaderboardDisplay() {
    // Leaderboard
    leaderboardTexture.loadFromFile("assets/BGs/LEADERBOARD.png");
    leaderboardDisplay.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    leaderboardDisplay.setTexture(&leaderboardTexture, true);
    leaderboardDisplay.setPosition(0, 0);

    // Entries
    updateBoard();
    font.loadFromFile("assets/Fonts/GamestationCond.otf");
    for (int i = 0; i < 5; i++) {
        entryNames[i] = Textbox(30, sf::Color::White, false);
        entryNames[i].setPosition({256, 202 + 78 * i});
        entryNames[i].setFont(font);

        entryScores[i] = Textbox(30, sf::Color::White, false);
        entryScores[i].setPosition({843, 202 + 78 * i});
        entryScores[i].setFont(font);
    }

    // Back Button
    for (int i = 0; i < 2; i++) {
        backButtonTextures[i].loadFromFile("assets/Buttons/BACKLEAD_" + std::to_string(i) + ".png");
    }

    backButton.setPosition(sf::Vector2f(BACKLEAD_BUTTON_X_MARGIN, BACKLEAD_BUTTON_Y_MARGIN));
    backButton.setSize(sf::Vector2f(BACKLEAD_BUTTON_WIDTH, BACKLEAD_BUTTON_HEIGHT));
    backButton.setTexture(&backButtonTextures[0]);

    backButtonRegion = sf::FloatRect(backButton.getPosition(), backButton.getSize());
}

void LeaderboardDisplay::updateBoard() {
    list<LeaderboardEntry>::iterator it = leaderboard.entries.begin();
    for (int i = 0; i < 5 && i < leaderboard.getSize(); i++) {
        if (i >= leaderboard.getSize()) {
            entryNames[i].clearText();
            entryScores[i].clearText();
        } else {
            entryNames[i].setText(it->name());
            entryScores[i].setText(std::to_string(it->score()));
            std::cout << "size " << leaderboard.getSize() << std::endl;
            ++it;
        }
    }
}

sf::RectangleShape LeaderboardDisplay::renderLeaderboard() {
    //update leaderboard before return
    updateBoard();
    return leaderboardDisplay;
}

sf::RectangleShape LeaderboardDisplay::renderBackButton() {
    return backButton;
}

bool LeaderboardDisplay::isOnBackButton(sf::Vector2i mousePos) {
    return backButtonRegion.contains(static_cast<sf::Vector2f>(mousePos));
}

void LeaderboardDisplay::selectBack() {
    backButton.setTexture(&backButtonTextures[1]);
}

void LeaderboardDisplay::unselectBack() {
    backButton.setTexture(&backButtonTextures[0]);
}