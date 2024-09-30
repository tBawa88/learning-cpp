#include <cstdio>

struct ConsoleLogger {
    void log_transfer(long to, long from, double amount) {
        printf("%ld -> %ld : %.2f\n", from, to, amount);
    }
};

struct FileLogger {
    void log_transfer(long to, long from, double amount) {
        printf("[file] %ld , %ld , %.2f\n", from, to, amount);
    }
};

enum class LoggerType {
    Console,
    File
};

struct Bank {
    ConsoleLogger clog;
    FileLogger flog;
    LoggerType type;

    Bank() : type{LoggerType::Console} {}

    void switchType(LoggerType newType) {
        type = newType;
    }

    void log_transaction(long to, long from, double amount) {
        switch (type) {
            case LoggerType::Console:
                clog.log_transfer(to, from, amount);
                break;
            case LoggerType::File:
                flog.log_transfer(to, from, amount);
                break;
            default:
                break;
        }
    }
};

int main() {
    Bank b;
    b.log_transaction(1000, 2000, 2340.34);
    b.log_transaction(1000, 3000, 2340.34);

    b.switchType(LoggerType::File);
    b.log_transaction(4000, 3000, 2340.34);

    return 0;
}
