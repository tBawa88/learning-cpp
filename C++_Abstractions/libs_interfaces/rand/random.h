#ifndef _random_h
#define _random_h

/**
 * Returns a random integer between the range of low to high
 *  [low..high)
 */
int RandomInt(int low, int high);

/**
 * Returns a random real number between the range low to high in the half open interval.
 * [low..high)
 */
double RandomReal(double low, double high);

/**
 * The probabily of returning true is dictated by the probability value passed as a parameter.
 * p >= 0(never) p <= 1(always)
 * Example RandomProb(0.4) will return true 40% of the time
 */
bool RandomProb(double p);

/**
 * It seeds the random number generator to make the value it returns, "truly random"
 */
void Randomize();

#endif
