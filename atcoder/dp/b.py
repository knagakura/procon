N,K = map(int,input().split())
h = list(map(int,input().split()))
dp = []
for i in range(N):
	dp.append(float("inf"))

dp[0] = 0

for i in range(N):
	for k in range(K):
		if i+k+1 < N:
			dp[i+k+1] = min(dp[i+k+1], dp[i]+abs(h[i+k+1]- h[i]))

print(dp[N-1])