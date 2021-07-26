#include <bits/stdc++.h>
 
using namespace std;
 
long long fxp(long long x, long long p) {
  if (p == 0) return 1LL;
  long long res = fxp(x, p / 2);
  res *= res;
  if (p & 1) res *= x;
  return res;
} 
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  vector<long long> numberOfDigits;
  for (int i = 0; i < 18; i++) {
    numberOfDigits.push_back(9 * fxp(10, i) * (i + 1));
  }
  
  int q;
  cin >> q;
  while (q--) {
    long long x;
    cin >> x;
    int digits = 18;
    long long cursum = 0;
    for (int i = 0; i < 18; i++) {
      if (cursum + numberOfDigits[i] >= x) {
        digits = i + 1;
        break;
      } else {
        cursum += numberOfDigits[i];
      }
    }
    
    long long lo = fxp(10, digits - 1), hi = fxp(10, digits) - 1, mid;
    long long number = -1, numberBeg = -1;
    while (lo <= hi) {
      mid = (lo + hi) / 2;
      long long thisbeg = (mid - fxp(10, digits - 1) + 1) * digits + cursum - digits + 1;
      if (thisbeg > x) {
        hi = mid - 1;
      } else if (thisbeg + digits - 1 < x) {
        lo = mid + 1;
      } else {
        number = mid;
        numberBeg = thisbeg;
        break;
      }
    }
    
    string nstr = to_string(number);
    long long dif = x - numberBeg;
    cout << nstr[dif] << '\n';
  }
  return 0;
}
