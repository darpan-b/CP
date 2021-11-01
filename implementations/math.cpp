namespace Math
{
const int64_t MOD = 1e9 + 7;
const int SIZE = 1e6 + 5;
template <typename T> T gcd(T a, T b)
{
    if (a > b) swap(a, b);
    return (a > 0 ? __gcd(a, b) : b);
}
template <typename T> T lcm(T a, T b)
{
    return (a * b) / gcd(a, b);
}
inline int64_t add(int64_t a, int64_t b)
{
    int64_t res = a + b;
    while (res >= MOD) res -= MOD;
    return res;
}
inline int64_t sub(int64_t a, int64_t b)
{
    int64_t res = a - b;
    while (res < 0) res += MOD;
    return res;
}
inline int64_t mult(int64_t a, int64_t b)
{
    return (a * b) % MOD;
}
int64_t fxp(int64_t x, int64_t p)
{
    if (p == 0) return 1L;
    int64_t res = fxp(x, p / 2);
    res *= res;
    res %= MOD;
    if (p & 1) res *= x;
    res %= MOD;
    return res;
}
/* 
 * Say ax+by = gcd(a,b)
 * Given a,b, extended euclid calculates the value of gcd(a,b) while simultaneously
 * finding out the coefficients for a and b, that is, x and y respectively.
 */
int64_t extendedEuclid(int64_t a, int64_t b, int64_t& x, int64_t& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t x1, y1;
    int64_t g = extendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}
int64_t modinv(int64_t x)
{
    int64_t x1, y1, z = 0;
    int64_t g = extendedEuclid(x, MOD, x1, y1);
    return (g > 1 ? -1 : sub(x1, z));
}
int64_t factorial[SIZE];
int64_t inverseFactorial[SIZE];
// TODO: ALWAYS INITIALIZE precompute() before using any functions in this namespace
void precompute()
{
    factorial[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        factorial[i] = mult(factorial[i - 1], i);
    }
    inverseFactorial[SIZE - 1] = modinv(factorial[SIZE - 1]);
    for (int i = SIZE - 2; i >= 0; i--) {
        inverseFactorial[i] = mult(inverseFactorial[i + 1], i + 1);
    }
}
int64_t nCr(int64_t n, int64_t r)
{
    return mult(mult(inverseFactorial[r], inverseFactorial[n - r]), factorial[n]);
}
}
using namespace Math;
