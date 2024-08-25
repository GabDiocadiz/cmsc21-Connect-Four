#include "engine.hpp"

/* PRIMARY FUNCTIONS */

Engine::Engine() 
: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME)
{
    state = start;

    bgmusic.openFromFile("assets/Audios/background-music.mp3");
    bgmusic.setLoop(true);
    bgmusic.setVolume(50);
    bgmusic.play();

    click.setSound("assets/Audios/button.mp3", 50);
    chipDrop.setSound("assets/Audios/chip.mp3", 50);
    gameEnd.setSound("assets/Audios/winner.mp3", 50);
}

void Engine::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Engine::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            window.close();
            leaderboardMenu.leaderboard.saveLeaderboard();
            break;
        }

        switch (state) {
            case start:
                handleStartInput(event);
                break;
            case how:
                handleHowInput(event);
                break;
            case game:
                handleGameInput(event);
                break;
            case finish:
                handleEndInput(event);
                break;
            case leaderboard:
                handleLeaderboardInput(event);
                break;
            case playerSelect:
                handlePlayerSelectInput(event);
                break;
            case playerSelect1:
                handlePlayerSelectInput(event);
                break;
            case playerSelect2:
                handlePlayerSelectInput(event);
                break;
            default:
                break;
        }

    }
}

void Engine::update() {
    // Logic Here!
    if (state == game) {
        // Update board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                int cellVal = boardLogic.getCell(i, j);

                if (cellVal != 0) 
                    board.placeCell(i, j, cellVal - 1);
                
            }
        }

        board.setTurn(boardLogic.getCurrentPlayer());


        // End game
        if (boardLogic.getWinner() != 0) {
            int winner = boardLogic.getWinner();
            state = finish;
            gameEnd.play();
            endMenu.setResult(winner);

            // Points: Win - 2, Draw - 1, Lose - 0
            if (winner == 1) {
                leaderboardMenu.leaderboard.update(player1, 2);
                leaderboardMenu.leaderboard.update(player2, 0);
            }
            else if (winner == 2) {
                leaderboardMenu.leaderboard.update(player1, 0);
                leaderboardMenu.leaderboard.update(player2, 2);
            } else {
                leaderboardMenu.leaderboard.update(player1, 1);
                leaderboardMenu.leaderboard.update(player2, 1);
            }
        }
    }

}

void Engine::render() {
    window.clear(sf::Color::Cyan);

    switch (state) {
        case start:
            renderStart();
            break;
        case how:
            renderHow();
            break;
        case game:
            renderGame();
            break;
        case finish:
            renderEnd();
            break;
        case leaderboard:
            renderLeaderboard();
            break;
        case playerSelect:
            renderPlayerSelect();
            break;
        case playerSelect1:
            renderPlayerSelect();
            break;
        case playerSelect2:
            renderPlayerSelect();
            break;
        default:
            renderStart();
    }
    
    window.display();
}

void Engine::resetBoard() {
    boardLogic = Board();
    board.resetCells();
}

/* EVENT HANDLERS */
void Engine::handleStartInput(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (startMenu.isOnStartButton(sf::Mouse::getPosition(window))) {
            state = playerSelect1;
            click.play();
        }
        else if (startMenu.isOnHowButton(sf::Mouse::getPosition(window))) {
            state = how;
            click.play();
        }
        else if (startMenu.isOnLeaderboardButton(sf::Mouse::getPosition(window))) {
            state = leaderboard;
            click.play();
        }
    } else {
        // Mouse Hover
        if (startMenu.isOnStartButton(sf::Mouse::getPosition(window))) {
            startMenu.selectStart();
        } else {
            startMenu.unselectStart();
        }

        if (startMenu.isOnHowButton(sf::Mouse::getPosition(window))) {
            startMenu.selectHow();
        } else {
            startMenu.unselectHow();
        }

        if (startMenu.isOnLeaderboardButton(sf::Mouse::getPosition(window))) {
            startMenu.selectLeaderboard();
        } else {
            startMenu.unselectLeaderboard();
        }
    }
}

void Engine::handleLeaderboardInput(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (leaderboardMenu.isOnBackButton(sf::Mouse::getPosition(window))) {
            state = start;
            click.play();
        }
        
    } else {
        // Mouse Hover
        if (leaderboardMenu.isOnBackButton(sf::Mouse::getPosition(window))) {
            leaderboardMenu.selectBack();
        } else {
            leaderboardMenu.unselectBack();
        }

    }
}    

void Engine::handleHowInput(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (howMenu.isOnReturn(sf::Mouse::getPosition(window))) {
            state = start;
            click.play();
        }
        
    } else {
        // Mouse Hover
        if (howMenu.isOnReturn(sf::Mouse::getPosition(window))) {
            howMenu.selectReturn();
        } else {
            howMenu.unselectReturn();
        }

    }
}    

void Engine::handlePlayerSelectInput(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (playerSelectMenu.isOnEnterButton(sf::Mouse::getPosition(window))) {
            // Save name, change state
            if (state == playerSelect) {
                state = game;
                player = playerSelectMenu.textInput.getText();
            }
            else if (state == playerSelect1) {
                state = playerSelect2;
                player1 = playerSelectMenu.textInput.getText();
                cout << player1 << endl;
            }
            else if (state == playerSelect2) {
                state = game;
                player2 = playerSelectMenu.textInput.getText();
                cout << player2 << endl;
            }
            playerSelectMenu.textInput.clearText();
            click.play();
        }
        else if (playerSelectMenu.isOnBackButton(sf::Mouse::getPosition(window))) {
            state = start;
            click.play();
        }
    } else if (event.type == sf::Event::TextEntered) {
        playerSelectMenu.textInput.typedOn(event);
    } else {
        // Mouse Hover
        if (playerSelectMenu.isOnEnterButton(sf::Mouse::getPosition(window))) {
            playerSelectMenu.selectEnter();
        } else {
            playerSelectMenu.unselectEnter();
        }

        if (playerSelectMenu.isOnBackButton(sf::Mouse::getPosition(window))) {
            playerSelectMenu.selectBack();
        } else {
            playerSelectMenu.unselectBack();
        }

    }
}

void Engine::handleGameInput(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        for (int i = 0; i < COLUMNS; i++) {
            if (board.isOnColumn(sf::Mouse::getPosition(window), i)) {
                // Give column to input to board
                printf("%i\n", i);
                if (boardLogic.playTurn(i))
                    chipDrop.play();
            }
        }
    } else {
        // Mouse Hover
        for (int i = 0; i < COLUMNS; i++) {
            if (board.isOnColumn(sf::Mouse::getPosition(window), i)) {
                board.selectColumn(i);
            } else {
                board.unselectColumn(i);
            }

        }
    }
}

void Engine::handleEndInput(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (endMenu.isOnReturn(sf::Mouse::getPosition(window))) {
            state = start;
            click.play();
        }
        
    } else {
        // Mouse Hover
        if (endMenu.isOnReturn(sf::Mouse::getPosition(window))) {
            endMenu.selectReturn();
            resetBoard();
        } else {
            endMenu.unselectReturn();
        }

    }
}



/* SUB-RENDER FUNCTIONS */

void Engine::renderStart() {
    window.draw(startMenu.renderTitle());
    window.draw(startMenu.renderStartButton());
    window.draw(startMenu.renderHowButton());
    window.draw(startMenu.renderLeaderboardButton());
}

void Engine::renderLeaderboard() {
    window.draw(leaderboardMenu.renderLeaderboard());
    window.draw(leaderboardMenu.renderBackButton());

    for (int i = 0; i < 5; i++) {
        leaderboardMenu.entryNames[i].drawTo(window);
        leaderboardMenu.entryScores[i].drawTo(window);
    }
}

void Engine::renderPlayerSelect() {
    if (state == playerSelect) {
        playerSelectMenu.switchPlayer(0);
    }
    if (state == playerSelect1) {
        playerSelectMenu.switchPlayer(1);
    }
    if (state == playerSelect2) {
        playerSelectMenu.switchPlayer(2);
    }

    window.draw(playerSelectMenu.renderPlayerSelect());
    window.draw(playerSelectMenu.renderEnterButton());
    window.draw(playerSelectMenu.renderBackButton());
    playerSelectMenu.textInput.drawTo(window);
}

void Engine::renderHow() {
    window.draw(howMenu.renderHow());
    window.draw(howMenu.renderReturnButton());
}

void Engine::renderGame() {
    window.draw(board.renderBackground());
    window.draw(board.renderBoard());

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {

            window.draw(board.getCell(i,j).render());

        }
    }
}

void Engine::renderEnd() {
   window.draw(endMenu.renderResult());
   window.draw(endMenu.renderReturnButton());
}