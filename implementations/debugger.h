#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>

#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", debug(__VA_ARGS__)

string to_string(char c)
{
    return string(1, c);
}

string to_string(const char* c)
{
    return (string)c;
}

string to_string(bool b)
{
    return to_string((int)b);
}

string to_string(vector<bool> v)
{
    string res = "{";
    for (int i = 0; i < (int)v.size(); i++)
        res += (char)('0' + v[i]);
    res += "}";
    return res;
}

template <size_t siz>
string to_string(bitset<siz> b)
{
    string res = "{";
    for (int i = 0; i < siz; i++)
        res += (char)('0' + b[i]);
    res += "}";
    return res;
}

template <class A, class B>
string to_string(pair<A, B> p);

template <class A>
string to_string(A a)
{
    string res = "{";
    bool f = true;
    for (const auto& e : a)
    {
        if (!f)
            res += ", ";
        res += to_string(e);
        f = false;
    }
    res += "}";
    return res;
}

template <class A, class B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug()
{
    cerr << "]\n";
}

template <class A, class... B>
void debug(const A& a, const B&... b)
{
    cerr << to_string(a);
    if (sizeof...(b))
        cerr << ", ";
    debug(b...);
}
