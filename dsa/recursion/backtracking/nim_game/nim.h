/**
 * File : nim.h
 * --------------
 * This file contains the nim class which models the game and contains all the necessary method to play the game
 */

#ifndef _nim_h
#define _nim_h

class NimGame {
   public:
    NimGame(int initialCoins = 13);
    bool IsGameOver();
    int CoinsRemaining();
    void StartGame();
    void TakeCoins(int coins);
    void AskMove();
    void PlayComputerMove();
    void DisplayCurrentState();

   private:
    int initialCoins;
    int currentCoins;
    bool gameOver;
};

#endif
