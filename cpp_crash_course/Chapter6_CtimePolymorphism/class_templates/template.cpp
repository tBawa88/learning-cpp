#include <cstdio>

template <typename T, typename K>
struct MyTemplateClass {
    MyTemplateClass(T* val) : member(val) {}
    K& echo(K& val) {
        return val;
    }

   private:
    T* member;
};

/**
 * Instantiating a template class
 */
int main() {
    int k = 10;
    MyTemplateClass<int, char*> mtc{&k};

    char* name = "tejas";
    printf("%s\n", mtc.echo(name));

    return 0;
}
