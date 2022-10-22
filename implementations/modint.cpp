template<const int& MOD>
struct ModInt
{
	int val;
	ModInt(ll v=0)
	{
		if(v < 0) v = (v%MOD)+MOD;
		if(v >= MOD) v %= MOD;
		val = (int)v;
	}
	ModInt(unsigned ll v)
	{
		if(v >= MOD) v %= MOD;
		val = (int)v;
	}
	ModInt(int v): ModInt((ll)v){}
	ModInt(unsigned int v): ModInt((unsigned ll)v){}
	explicit operator int() const
	{
		return val;
	}
	explicit operator unsigned int() const
	{
		return val;
	}
	explicit operator ll() const
	{
		return val;
	}
	explicit operator unsigned ll() const
	{
		return val;
	}
	explicit operator double() const
	{
		return val;
	}
	explicit operator long double() const
	{
		return val;
	}
	ModInt& operator +=(const ModInt& other)
	{
		val -= MOD-other.val;
		if(val < 0) val += MOD;
		return *this;
	}
	ModInt& operator -=(const ModInt& other)
	{
		val -= other.val;
		if(val < 0) val += MOD;
		return *this;
	}
	static unsigned fast_mod(unsigned ll x, unsigned m=MOD)
	{
		#if!defined(_WIN32) || defined(_WIN64)
		return (unsigned)x%m;
		#endif
		unsigned x_high = (unsigned)x>>32, x_low = (unsigned)x;
		unsigned quot,rem;
		asm("divl %4\n": "=a"(quot), "=d"(rem): "d"(x_high), "a"(x_low), "r"(m));
		return rem;		        
	}
	ModInt& operator *=(const ModInt& other)
	{
		val = fast_mod((unsigned ll)val*other.val);
		return *this;
	}
	ModInt& operator /=(const ModInt& other)
	{
		return *this *= other.inv();
	}
	friend ModInt operator +(const ModInt& a,const ModInt& b)
	{
		return ModInt(a) += b;
	}
	friend ModInt operator -(const ModInt& a,const ModInt& b)
	{
		return ModInt(a) -= b;
	}
	friend ModInt operator *(const ModInt& a,const ModInt& b)
	{
		return ModInt(a) *= b;
	}
	friend ModInt operator /(const ModInt& a,const ModInt& b)
	{
		return ModInt(a) /= b;
	}
	ModInt& operator++()
	{
		val = (val == MOD-1? 0:val+1);
		return *this;
	}
	ModInt& operator--()
	{
		val = (val == 0? MOD-1:val-1);
		return *this;
	}
	ModInt operator++(int)
	{
		ModInt before = *this;
		++(*this);
		return before;
	}
	ModInt operator--(int)
	{
		ModInt before = *this;
		--(*this);
		return before;
	}
	ModInt operator -() const
	{
		return (val == 0? 0:MOD-val);
	}
	friend bool operator ==(const ModInt& a,const ModInt& b)
	{
		return a.val == b.val;
	}
	friend bool operator ==(const ModInt& a,const ModInt& b)
	{
		return a.val == b.val;
	}
	friend bool operator !=(const ModInt& a,const ModInt& b)
	{
		return a.val != b.val;
	}
	friend bool operator <(const ModInt& a,const ModInt& b)
	{
		return a.val < b.val;
	}
	friend bool operator >(const ModInt& a,const ModInt& b)
	{
		return a.val > b.val;
	}
	friend bool operator <=(const ModInt& a,const ModInt& b)
	{
		return a.val <= b.val;
	}
	friend bool operator >=(const ModInt& a,const ModInt& b)
	{
		return a.val >= b.val;
	}
	static const int SAVE_INV = 1e6+5;
	static ModInt save_inv[SAVE_INV];
	static void prepare_inv()
	{
		// MOD should be prime for inverse algo to work.
		for(ll p = 2; p*p <= MOD; p += p%2+1) assert(MOD%p != 0);
		save_inv[0] = 0;
		save_inv[1] = 1;
		for(int i = 2; i < SAVE_INV; i++) save_inv[i] = save_inv[MOD%i] * (MOD-(MOD/i));
	}
	ModInt inv() const
	{
		if(save_inv[1] == 0) prepare_inv();
		if(val < SAVE_INV) return save_inv[val];
		ModInt product = 1;
		int v = val;
		while(v >= SAVE_INV)
		{
			product *= MOD - MOD/v;
			v = MOD%v;
		}
		return product*save_inv[v];
	}
	ModInt pow(ll p) const
	{
		if(p < 0) return inv().pow(-p);
		ModInt a = *this,result = 1;
		while(p > 0)
		{
			if(p&1) result *= a;
			p >>= 1;
			if(p > 0) a *= a;
		}
		return result;
	}
	friend ostream& operator <<(ostream& os,const ModInt& m)
	{
		return os << m.val;
	}
};
template<const int& MOD> ModInt<MOD> ModInt<MOD>::save_inv[ModInt<MOD>::SAVE_INV];
extern const int MOD = 998244353;
using mint = ModInt<MOD>;
