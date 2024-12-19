#include "gameLogic.h"

#include <iostream>

#include "../nim_game/nimLogic.cpp"

void GiveInstructions() {
    std::cout << "Hello. Welcome to the game of nim.\nThe game starts with a pile of 13 coins on the table\n"
                 "On each turn, you and I will alternatively remove either 1, 2 or 3 coins from the pile\n"
                 "The player who picks the last coin from the pile loses.\n"
                 "----------------------------------------------------------------------------------------\n\n";
}

stateT NewGame() {
    stateT state;
    state.numCoins = 13;
    state.turn = Human;
    return state;
}

bool GameIsOver(stateT &state) {
    return state.numCoins == 1;
}

void DisplayGame(stateT &state) {
    std::cout << "There are " << state.numCoins << " coins in the pile.\n";
}

Player WhoseTurn(stateT &state) {
    return state.turn;
}

moveT GetUserMove(stateT &state) {
    moveT move;
    std::cout << "How many would you like to take? ";
    std::cin >> move.nTake;
    while (move.nTake < 1 || move.nTake > 3) {
        std::cout << "You can only take 1 or 2 or 3 coins from the pile\n";
        std::cout << "Please choose again ";
        std::cin >> move.nTake;
    }
    return move;
}

moveT ChooseComputerMove(stateT &stateT) {
    moveT move;
    move.nTake = FindGoodMove(stateT.numCoins);
    return move;
}

void DisplayComputerMove(moveT move) {
    std::cout << "I'll take " << move.nTake << " coins\n";
}

void MakeMove(stateT &state, moveT &move) {
    state.numCoins -= move.nTake;
    if (state.turn == Human)
        state.turn = Computer;
    else
        state.turn = Human;
}

void AnnouceWinner(stateT &state) {
    std::cout << "There's only " << state.numCoins << " coin left\n";
    if (state.turn == Human)
        std::cout << "I win\n";
    else
        std::cout << "You win\n";
}
