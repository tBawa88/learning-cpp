
/**
 * const_cast() functions strips off the 'const' status and turns the value into normal, mutable value
 *
 * Only use const_cast to obtain 'write access' to const objects.
 * Any other type conversion will result in a compiler error
 */

void carbon_thaw(const int& isotope) {
    // isotope++;  can't do dis
    auto& iso = const_cast<int&>(isotope);
    iso++;
}
