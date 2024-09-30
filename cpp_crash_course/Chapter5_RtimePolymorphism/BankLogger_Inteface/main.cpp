#include <cstdio>

/**
 * Interface Logger ( A pure virtual class )
 */
struct Logger {
    virtual void log_transfer(long to, long from, double amount) = 0;
    virtual ~Logger() {}
};

struct ConsoleLogger : Logger {
    void log_transfer(long to, long from, double amount) override {
        printf("[cons] %ld -> %ld: %.2f\n", from, to, amount);
    }
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld,%ld,%.2f\n", from, to, amount);
    }
};
/**
 * The main reason polymorphism is possible is because of the "is-a" relation that comes from inheritence
 */

/**
 * constructor injection - store a reference of the interface as a class member and accept that reference in the constructor
 * property injection - creating a new function which accepts a reference to the interface type
 */
struct Bank {
    Bank(Logger& logger) noexcept : logger(logger) {
    }

    void SetLogger(Logger* new_logger) { loggerr = new_logger; }

    void make_transfer(long to, long from, double amount) {
        logger.log_transfer(to, from, amount);
    }

    void make_transfer2(long to, long from, double amount) {
        loggerr->log_transfer(to, from, amount);
    }

   private:
    // Since we're using a reference to the interface, it won't be reseated after it has been intialized
    Logger& logger;
    // Using an pointer to interface makes it more flexible
    Logger* loggerr;
};

int main() {
    FileLogger logger;
    Bank b{logger};
    b.make_transfer(100, 200, 234.34);

    ConsoleLogger* c = new ConsoleLogger{};
    b.SetLogger(c);
    b.make_transfer2(3434, 231, 4562.234);

    return 0;
}
