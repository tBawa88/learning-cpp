#include "gameLogic.h"

int main() {
    stateT state = NewGame();
    moveT move;
    GiveInstructions();
    while (!GameIsOver(state)) {
        DisplayGame(state);
        switch (state.turn) {
            case Human:
                move = GetUserMove(state);
                break;
            case Computer:
                move = ChooseComputerMove(state);
                DisplayComputerMove(move);
                break;
        }
        MakeMove(state, move);
    }
    AnnouceWinner(state);

    return 0;
}
