#include "nim.h"

#include <iostream>

#include "nimLogic.cpp"

NimGame::NimGame(int initialCoins) {
    this->initialCoins = initialCoins;
    currentCoins = initialCoins;
    gameOver = false;
}

bool NimGame::IsGameOver() { return gameOver; }

int NimGame::CoinsRemaining() { return currentCoins; }

void NimGame::StartGame() {
    std::cout << "Hello. Welcome to the game of nim.\nThe game starts with a pile of 13 coins on the table\n"
                 "On each turn, you and I will alternatively remove either 1, 2 or 3 coins from the pile\n"
                 "The player who picks the last coin from the pile loses.\n"
                 "----------------------------------------------------------------------------------------\n\n";
}

void NimGame::DisplayCurrentState() {
    std::cout << "There are " << currentCoins << " coins in the pile.\n";
}

void NimGame::TakeCoins(int coins) {
    currentCoins -= coins;
    if (currentCoins == 1)
        gameOver = true;
}

void NimGame::AskMove() {
    int n_take;
    std::cout << "How many would you like to take? ";
    std::cin >> n_take;
    while (n_take < 1 || n_take > 3) {
        std::cout << "You can only take 1 or 2 or 3 coins from the pile\n";
        std::cout << "Please choose again ";
        std::cin >> n_take;
    }
    TakeCoins(n_take);
    DisplayCurrentState();
}

void NimGame::PlayComputerMove() {
    int take = FindGoodMove(currentCoins);
    if (take == NO_GOOD_MOVES)
        take = currentCoins - 1;
    std::cout << "I'll take " << take << std::endl;
    TakeCoins(take);
}
