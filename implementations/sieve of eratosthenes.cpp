// implementation of sieve of eratosthenes to find the primes within a given range
// all prime[i] (1<=i<=MAXN) is initialized to true before function call 

bool prime[MAXN];

void sieve(int n){
	for(int i = 2; i <= n; i++){
		if(prime[i]){
			for(int j = i*2; j <= n; j+=i){
				prime[j] = false;
			}
		}
	}
} 
