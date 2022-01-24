long long fxp(long long x, long long p, long long mod)
{
    if (p == 0)
        return 1;
    long long res = fxp(x, p / 2, mod);
    res *= res;
    res %= mod;
    if (p & 1)
        res *= x;
    res %= mod;
    return res;
}

long long multMod(long long a, long long b, long long mod)
{
    long long x = 0, y = a % mod;
    while (b > 0)
    {
        if (b & 1)
            x = (x + y) % mod;
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

/// Miller-Rabin primality test, #iTimes is directly proportional to accuracy
bool isProbablePrime(long long p, int iTimes)
{
    if (p < 2)
        return false;
    if (p != 2 && p % 2 == 0)
        return false;
    long long s = p - 1;
    while ((s & 1) ^ 1)
        s >>= 1;
    for (int i = 0; i < iTimes; i++)
    {
        long long a = rand() % (p - 1) + 1, temp = s;
        long long mod = fxp(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = multMod(mod, mod, p);
            temp <<= 1;
        }
        if (mod != p - 1 && ((temp & 1) ^ 1))
            return false;
    }
    return true;
}
