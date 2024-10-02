#include <cstdio>

/**
 *
 * static_cast : reverses a well defined implicit conversion. Such as short to int, void pointer to int pointer
 * The object_to_cast in this case must be something that the desired_type can implicitly convert to
 * So bascially related types
 *
 * One of the most common use case of static_cast is converting void pointers into desired type
 * void pointers can point to any type, BUT since they donot have any type information associated to them...
 * you cannot derefrence them directly.
 * You must static_cast<>() them to gain the ability to derefrence
 */

// when passing a short pointer to this function, it 'implicitly' converts into a void pointer
// and we're using static_cast to reverse that implicit conversion
short increment_as_short(void* target) {
    auto short_value = static_cast<short*>(target);
    *short_value = ++(*short_value);
    return *short_value;
}

int main() {
    short val{256};
    auto mark_of_the_beast = increment_as_short(&val);

    printf("value = %d\n", mark_of_the_beast);
    return 0;
}
