#include <cstdio>

struct ConsoleLogger {
    void log_transfer(long to, long from, double amount) {
        printf("%ld -> %ld : %.2f\n", from, to, amount);
    }
};

struct Bank {
    ConsoleLogger logger;

    void makeTransfer(long to, long from, double amount) {
        logger.log_transfer(to, from, amount);
    }
};

int main() {
    Bank b;
    b.makeTransfer(1000, 2000, 122343.534);

    return 0;
}
