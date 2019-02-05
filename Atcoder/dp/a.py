N = int(input())
h = list(map(int,input().split()))

dp = []

for i in range(N):
	dp.append(float("inf"))

for i in range(N):
	if i ==0:
		dp[i] = 0
	else:
		dp[i] = min(dp[i],dp[i-1]+abs(h[i]-h[i-1]))
		if i > 1:
			dp[i] = min(dp[i], dp[i-2]+abs(h[i]-h[i-2]))

print(dp[-1])