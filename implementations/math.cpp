namespace Math
{
    const long long MOD = (long long) 1e9 + 7;
    const int SIZE = (int) 1e6 + 5;

    template <typename T> T gcd(T a, T b)
    {
        if (a > b) swap(a, b);
        return (a > 0 ? __gcd(a, b) : b);
    }

    template <typename T> T lcm(T a, T b)
    {
        return (a * b) / gcd(a, b);
    }

    inline long long add(long long a, long long b)
    {
        long long res = a + b;
        while (res >= MOD) res -= MOD;
        return res;
    }

    inline long long sub(long long a, long long b)
    {
        long long res = a - b;
        while (res < 0) res += MOD;
        return res;
    }

    inline long long mult(long long a, long long b)
    {
        return (a * b) % MOD;
    }

    long long fxp(long long x, long long p)
    {
        if (p == 0) return 1LL;
        long long res = fxp(x, p / 2);
        res *= res;
        res %= MOD;;

        if (p & 1) res *= x;
        res %= MOD;
        return res;
    }

    /* 
     * Say ax+by = gcd(a,b)
     * Given a,b, extended euclid calculates the value of gcd(a,b) while simultaneously
     * finding out the coefficients for a and b, that is, x and y respectively.
     */
    long long extendedEuclid(long long a, long long b, long long& x, long long& y)
    {
        if (b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }
        long long x1, y1;
        long long g = extendedEuclid(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return g;
    }

    long long modinv(long long x)
    {
        long long x1, y1, z = 0;
        long long g = extendedEuclid(x, MOD, x1, y1);
        return (g > 1 ? -1 : sub(x1, z));
    }

    long long factorial[SIZE];
    long long inverseFactorial[SIZE];
    // TODO: ALWAYS INITIALIZE precompute() before using any functions in this namespace
    
    void precompute()
    {
        factorial[0] = 1;
        for (int i = 1; i < SIZE; i++)
        {
            factorial[i] = mult(factorial[i - 1], i);
        }
        inverseFactorial[SIZE - 1] = modinv(factorial[SIZE - 1]);
        for (int i = SIZE - 2; i >= 0; i--)
        {
            inverseFactorial[i] = mult(inverseFactorial[i + 1], i + 1);
        }
    }

    long long nCr(long long n, long long r)
    {
        return mult(mult(inverseFactorial[r], inverseFactorial[n - r]), factorial[n]);
    }
}

using namespace Math;
