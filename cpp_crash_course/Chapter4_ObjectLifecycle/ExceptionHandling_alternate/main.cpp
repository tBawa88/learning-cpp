
/**
 * Always prefer exception handling over manual error checking.
 * Exception handled code runs faster than manual error checked code 'when there are no errors' (because of no extra checks), but slower and more robust when there is one.
 * In situations (like embedded environments) where exception handling is not available, there are 2 methods of enforcing error checking
 * 1. Manually enforcing class invariants through a class method
 * 2. Returning multiple values from a function using 'structured binding declaration'. Usually a boolean and a message string
 */

struct HumptyDumpty {
    bool is_together_again() {}
};

bool send_kings_and_horses() {
    HumptyDumpty hd{};
    if (hd.is_together_again()) {
        return false;
        // class invariants have been established, no need to send kings and horses
    }
    return true;
}

// 2nd alternative

struct Result {
    HumptyDumpty hd;
    bool success;
};

Result make_humpty() {
    HumptyDumpty hd{};
    bool is_valid;

    // check if hd is valid and set is_valid accordingly
    return {hd, is_valid};
}

bool send_kings_and_mens() {
    auto [hd, success] = make_humpty();  //
    if (!success) return false;

    // class invariants have been established
    return true;
}
