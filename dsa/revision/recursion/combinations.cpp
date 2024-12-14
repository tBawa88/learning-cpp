

int combinations(int n, int r);

/**
 * Finding combination of nCr using pascal's triangles
 * If the terms are at the boundary, the answer is direct = 1
 * Else the answer to the combination is sum of the 2 terms above the current term
 *
 * base cases:
 *  if r == 0, return 1
 *  if n == r, return 1
 *
 * else
 *  return combination(n-1, r-1) + combination(n-1, r);
 *
 */

int combinations(int n, int r) {
    if (r == 0)
        return 1;
    if (n == r)
        return 1;

    return combinations(n - 1, r - 1) + combinations(n - 1, r);
}
