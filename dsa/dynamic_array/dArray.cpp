#include <cstdio>

template <typename T>
struct darray {
    darray() : length{}, max_cap{2} {
        arr = new int[max_cap];
    }
    darray(size_t cap) : max_cap{cap}, length{} {
        arr = new int[max_cap];
    }
    ~darray() {
        printf("releasing array memory\n");
        delete[] arr;
    }

    void push(int val) {
        if (length == max_cap) {
            // double the max_cap, create a new dummy array & copy all the elements
            max_cap *= 2;
            int* new_arr = new int[max_cap];
            this->copy_elements(new_arr, arr, length);

            delete[] arr;
            arr = new_arr;
            arr[length++] = val;
            printf("growing array, new cap = %ld\n", max_cap);
            return;
        }

        arr[length++] = val;
        return;
    }

    int pop() {
        if (length == 0)
            return -1;

        // if array length drops below, shrinking the array
        if (length < max_cap / 2) {
            max_cap /= 2;
            int* new_arr = new int[max_cap];
            this->copy_elements(new_arr, arr, length);
            delete[] arr;
            arr = new_arr;
            printf("shrinking array, new_cap = %ld\n", max_cap);
            return arr[--length];
        }

        return arr[--length];
    }

    void copy_elements(int* dest, int* src, size_t length) {
        for (size_t i = 0; i < length; i++) {
            dest[i] = src[i];
        }
    }

    void print() {
        for (size_t i = 0; i < length; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

   private:
    // length represents curent length and also the index where the next value will be inserted
    size_t length;
    size_t max_cap;
    T* arr = nullptr;
};

int main() {
    darray<int> arr{3};

    arr.push(10);
    arr.push(20);
    arr.push(30);
    arr.push(40);
    arr.push(50);
    arr.push(60);
    arr.push(70);
    arr.push(80);
    arr.print();

    printf("pop = %d\n", arr.pop());
    printf("pop = %d\n", arr.pop());
    printf("pop = %d\n", arr.pop());
    printf("pop = %d\n", arr.pop());
    printf("pop = %d\n", arr.pop());
    printf("pop = %d\n", arr.pop());
    printf("pop = %d\n", arr.pop());
    printf("pop = %d\n", arr.pop());

    return 0;
}
