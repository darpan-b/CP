namespace Math {
  const ll MOD = 1e9 + 7;
  const int SIZE = 2e5 + 5;
  ll factorial[SIZE], inverse_factorial[SIZE];

  template<typename T>
  T gcd(T a, T b)
  {
    if (a > b) {
      swap(a, b);
    }
    return (a > 0 ? __gcd(a, b) : b);
  }

  template<typename T>
  T lcm(T a, T b)
  {
    return (a * b) / gcd(a, b);
  }

  ll add(ll a, ll b)
  {
    ll res = a + b;
    while (res >= MOD) {
      res -= MOD;
    }
    return res;
  }

  ll sub(ll a, ll b)
  {
    ll res = a - b;
    while (res < 0) {
      res += MOD;
    }
    return res;
  }

  ll mult(ll a, ll b)
  {
    return (a * b) % MOD;
  }

  ll fxp(ll x, ll p)
  {
    if (p == 0) {
      return 1LL;
    }
    ll res = fxp(x, p / 2);
    res *= res;
    res %= MOD;
    if (p % 2 != 0) {
      res *= x;
      res %= MOD;
    }
    return res;
  }
  
  /* Say ax+by = gcd(a,b)
   * Given a,b, extended euclid calculates the value of gcd(a,b) while simultaneously
   * finding out the coefficients for a and b, that is, x and y respectively.
  */
  ll extended_euclid(ll a, ll b, ll& x, ll& y)
  {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    ll x1, y1;
    ll g = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
  }

  ll modinv(ll x)
  {
    ll x1, y1, z = 0;
    ll g = extended_euclid(x, MOD, x1, y1);
    return g > 1 ? -1 : sub(x1, z);
  }

  /** ALWAYS INITIALIZE precompute() */
  void precompute()
  {
    factorial[0] = 1;
    for (int i = 1; i < SIZE; i++) {
      factorial[i] = mult(factorial[i - 1], i);
    }
    inverse_factorial[SIZE - 1] = modinv(factorial[SIZE - 1]);
    for (int i = SIZE - 2; i >= 0; i--) {
      inverse_factorial[i] = mult(inverse_factorial[i + 1], i + 1);
    }
  }

  ll nCr(ll n, ll r)
  {
    if (n < r) {
      return 0LL;
    }
    return mult(mult(inverse_factorial[r], inverse_factorial[n - r]), factorial[n]);
  }
}
using namespace Math;
