#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define V vector
#define F first
#define S second
#define SZ(x) (int) x.size()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define F0R(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(auto i = (a); i <= (b); i++)
#define ROF(i,a,b) for(auto i = (a); i >= (b); i--)

#define STS string to_string
STS(char c) { return string(1,c); }
STS(const char* c) { return (string)c; }
STS(string s) { return s; }
STS(bool b) { return to_string((int)b); }
STS(V<bool> v) {
    string res = "{"; F0R(i,SZ(v)) res += (char)('0'+v[i]);
    res += "}"; return res;
}
template<size_t siz> STS(bitset<siz> b) {
    string res = "{"; F0R(i,siz) res += (char)('0'+b[i]);
    res += "}"; return res;
}
template<class A, class B> STS(pair<A,B> p);
template<class A> STS(A a) {
    string res = "{"; bool f = true;
    for(const auto& e : a) { if(!f) res += " ,"; res += to_string(e); f = false; }
    res += "}"; return res; 
}
template<class A, class B> STS(pair<A,B> p) {
    return "("+to_string(p.F)+", "+to_string(p.S)+")";
}
void debug() { cerr << "]\n"; }
template<class A, class... B> void debug(const A& a, const B&... b) {
    cerr << to_string(a); if(sizeof...(b)) cerr << ", "; debug(b...);
}

// int main() {

// }
