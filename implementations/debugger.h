#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>

#define dbg(...) std::cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", debug(__VA_ARGS__)

std::string to_string(int value) { return std::to_string(value); }
std::string to_string(long value) { return std::to_string(value); }
std::string to_string(long long value) { return std::to_string(value); }
std::string to_string(unsigned value) { return std::to_string(value); }
std::string to_string(unsigned long value)  { return std::to_string(value); }
std::string to_string(unsigned long long value) { return std::to_string(value); }
std::string to_string(float value) { return std::to_string(value); }
std::string to_string(double value) { return std::to_string(value); }
std::string to_string(long double value) { return std::to_string(value); }

std::string to_string(char c)
{
	return std::string(1, c);
}

std::string to_string(const char* c)
{
	return (std::string)c;
}

std::string to_string(bool b)
{
	return to_string((int)b);
}

std::string to_string(std::vector<bool> v)
{
	std::string res = "{";
	for (int i = 0; i < (int)v.size(); i++)
		res += (char)('0' + v[i]);
	res += "}";
	return res;
}

template <size_t siz>
std::string to_string(std::bitset<siz> b)
{
	std::string res = "{";
	for (int i = 0; i < siz; i++)
		res += (char)('0' + b[i]);
	res += "}";
	return res;
}

template <class A, class B>
std::string to_string(std::pair<A, B> p);

template <class A>
std::string to_string(A a)
{
	std::string res = "{";
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
std::string to_string(std::pair<A, B> p)
{
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug()
{
	std::cerr << "]\n";
}

template <class A, class... B>
void debug(const A& a, const B&... b)
{
	std::cerr << to_string(a);
	if (sizeof...(b))
		std::cerr << ", ";
	debug(b...);
}
