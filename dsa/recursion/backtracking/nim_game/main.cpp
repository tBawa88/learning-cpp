#include <iostream>

#include "nim.h"
using namespace std;

enum Player {
    Human,
    Computer
};

int main() {
    NimGame game;
    game.StartGame();
    Player p = Human;

    while (!game.IsGameOver()) {
        if (p == Human) {
            game.DisplayCurrentState();
            game.AskMove();
            p = Computer;

        } else {
            game.PlayComputerMove();
            p = Human;
        }
    }

    cout << "There is only " << game.CoinsRemaining() << " coin left." << endl;
    if (p == Human)
        cout << "I win\n";
    else
        cout << "You win\n";
    return 0;
}
