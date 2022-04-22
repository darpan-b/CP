n = int(input())
dp = [0]*(n+1)
mod = int(1e9+7)
dp[0] = 1
for i in range(n+1):
	for j in range(1,7):
		if i-j >= 0:
			dp[i] += dp[i-j]
			dp[i] %= mod
print(dp[n])
