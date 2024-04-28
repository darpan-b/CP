N, W = map(int, input().split())
w, v = [], []
for i in range(N):
    tx, ty = map(int, input().split())
    w.append(tx)
    v.append(ty)

dp = [[0 for i in range(W+1)] for j in range(N)]

for i in range(N):
    for j in range(W+1):
        if i-1 >= 0:
            dp[i][j] = dp[i-1][j]
        if j-w[i] >= 0:
            if i > 0:
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i])
            else:
                dp[i][j] = max(dp[i][j], v[i])

print(max(dp[N-1]))
