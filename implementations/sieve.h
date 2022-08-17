struct sieve
{
    vector<bool> is_prime;

    sieve() {}

    sieve(int n)
    {
        is_prime.assign(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; i++)
        {
            if (!is_prime[i]) continue;
            for (int j = i + i; j <= n; j += i) is_prime[i] = false;
        }
    }

    bool prime(int x)
    {
        return sieve[x];
    }
};
