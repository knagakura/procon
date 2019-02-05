N,W = map(int,input().split())

w = []
v = []

for i in range(N):
	a,b = map(int,input().split())
	w.append(a)
	v.append(b)

dp = [[0]*(W+1) for _ in range(N+1)]
for i in range(N):
	for sum_w in range(W+1):
		if sum_w - w[i] >=0:
			dp[i+1][sum_w] = max(dp[i+1][sum_w], dp[i][sum_w - w[i]] + v[i])

		dp[i+1][sum_w] = max(dp[i+1][sum_w], dp[i][sum_w])

print(dp[N][W])
