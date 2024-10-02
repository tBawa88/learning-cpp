
#include <cstdio>

int main() {
    // it tells the compiler that whatever value is stored at this address, convert it into unsigned long
    // trust me bro, the stored value exists and it's logically compaitble with unsigned long

    auto timer = reinterpret_cast<const unsigned long*>(0x1000);
    printf("%lu\n", *timer);
}
