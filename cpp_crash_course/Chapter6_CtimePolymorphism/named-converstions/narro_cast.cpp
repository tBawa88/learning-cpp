
/**
 * narrow_cast is not a built in named cast, this is a custom implementation
 * Following program is a custom static_cast which checks for rutime **narrowing**
 * narrowing is when a bigger data type is casted into a smaller type, resulting in data loss (like int to short)
 */

#include <stdexcept>

template <typename To, typename From>
To narrow_cast(From value) {
    const auto convertedValue = static_cast<To>(value);
    const auto backwards = static_cast<From>(convertedValue);
    if (value != backwards) throw std::runtime_error{"Narrowing has occured"};

    return convertedValue;
}

int main() {
    int perfect{496};
    // even though, we defined this template function with 2 template types, we don't have to explicitly pass in both
    // since we're passing an integer, the second template type is auto inferred as int
    auto perfect_result = narrow_cast<short>(perfect);
    printf("Casting occrured with no problem %d\n", perfect_result);  // in this case, 496 fits withing short boundaries

    try {
        int large_value{2293485};
        auto large_cast = narrow_cast<short>(large_value);
    } catch (const std::exception& e) {
        printf("casting error %s\n", e.what());
    }

    return 0;
}
