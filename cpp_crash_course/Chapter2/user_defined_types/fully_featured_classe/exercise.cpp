#include <cstdio>

// Create an enum class with that has values Add Subtract Multiply and Divide
enum class Operation {
    Add,
    Subtract,
    Divide,
    Multiply
};

// Create a Calculator struct, it should have a single constructor that takes an Operation

struct Calculator {
   private:
    Operation op;

   public:
    Calculator(Operation op) {
        // since there is a conflict of name, we need to use 'this' reference object
        // otherwise we can directly access class data members
        this->op = op;
    }

    int calculate(int a, int b) {
        switch (op) {
            case Operation::Add: {
                return a + b;
            } break;
            case Operation::Divide: {
                return a / b;
            } break;
            case Operation::Multiply: {
                return a * b;
            } break;
            case Operation::Subtract: {
                return a - b;
            } break;
            default: {
                return -1;
            }
        }
    }
};

int main() {
    Calculator c{Operation::Add};

    printf("Result of calculation  = %d\n", c.calculate(10, 20));

    return 0;
}
