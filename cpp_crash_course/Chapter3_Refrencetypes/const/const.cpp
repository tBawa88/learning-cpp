#include <cstdio>
#include <tuple>

struct Node {
   private:
    int data;
    const float PI;  // const data member must be either initialized at deifinition time, or at list using the "initializer list"
    Node *next;

   public:
    Node(int data, float pi, Node *nextptr) : data(data), PI(pi), next(nextptr) {
    }

    // A 'const' class method. Placing a const after function names promises that no data member will be modified in this method.
    //  Making this method a read-only method
    std::tuple<int, float, Node *> get_data() const {
        return std::tuple{this->data, this->PI, this->next};
    }
};

int main() {
    Node n{100, 3.1415, nullptr};

    // destructuring a tuple (kinda similar to Javscript)
    // type of each value in this auto is &&, which means a 'rValue' reference (study in future)
    // basically they're a reference to a temporary object which is not persisted in the memory yet.
    auto [data, pi, next] = n.get_data();
    printf("Node value = %d\n", data);
    printf("Node PI = %f\n", pi);
}
