#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  set<string> done{s};
  vector<int> perm(s.size());
  iota(perm.begin(), perm.end(), 0);
  while (next_permutation(perm.begin(), perm.end())) {
    string temp = "";
    for (auto& e : perm) {
      temp += s[e];
    }
    if (done.find(temp) == done.end()) {
      done.insert(temp);
    }
  }
  cout << done.size() << '\n';
  for (auto& e : done) cout << e << '\n';
  return 0;
}
