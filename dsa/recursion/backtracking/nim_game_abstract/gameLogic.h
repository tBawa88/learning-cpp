/**
 * File: gameLogic.h
 * -------------------
 * This file contains logic for the nim game(coin version)
 */

#ifndef _game_logic_h
#define _game_logic_h

enum Player {
    Human,
    Computer
};

struct stateT {
    int numCoins;
    Player turn;
};

struct moveT {
    int nTake;
};

void GiveInstructions();

stateT NewGame();

bool GameIsOver(stateT &state);

void DisplayGame(stateT &state);

Player WhoseTurn(stateT &stateT);

moveT GetUserMove(stateT &stateT);

moveT ChooseComputerMove(stateT &stateT);

void MakeMove(stateT &state, moveT &move);

void DisplayComputerMove(moveT move);

void AnnouceWinner(stateT &state);

#endif
