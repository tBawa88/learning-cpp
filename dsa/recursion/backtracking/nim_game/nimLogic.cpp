#define NO_GOOD_MOVES -1
#define MAX_TAKE 3

int FindGoodMove(int coins);
bool IsPositionBad(int coins);

/**
 * Purpose : Finds a good move(which leads to  a bad position for the opponent)
 * It tries all values from 1 to 3 and checks if any of these choices lead to a bad position
 */
int FindGoodMove(int coins) {
    for (int take = 1; take <= MAX_TAKE; take++) {
        if (IsPositionBad(coins - take))
            return take;
    }
    return NO_GOOD_MOVES;
}

/**
 * A position is Bad if there is 1 coin left
 * A position is Bad if the there are no good moves left (like 5 coins left -> every choice is doomed to fail)
 */
bool IsPositionBad(int coins) {
    if (coins == 1)
        return true;

    return FindGoodMove(coins) == NO_GOOD_MOVES;
}
