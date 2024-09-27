#include <cstdio>
#include <stdexcept>

struct Rectangle {
   private:
    int height, width;
    void check_invariant() const {
        if (height <= 0 || width <= 0) {
            throw std::logic_error{"Height and Width both must be positive"};
        }
    }

   public:
    Rectangle(int w, int h) : width(w), height(h) {
        check_invariant();
    }

    void resize(int w, int h) {
        width = w;
        height = h;
        check_invariant();
    }
};

int main() {
    try {
        Rectangle r{10, 50};
        r.resize(15, 30);
        r.resize(-4, 90);
    } catch (const std::exception &e) {
        printf("Logical exception throw %s\n", e.what());
    }

    return 0;
}
