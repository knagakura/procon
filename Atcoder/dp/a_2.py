N = int(input())
h = list(map(int,input().split()))

dp = []

for i in range(N):
	dp.append(float("inf"))
dp[0] = 0
for i in range(N):
	if not i+1 > N -1:
		dp[i+1] = min(dp[i+1], dp[i]+abs(h[i+1]-h[i]))
	if not i+2 > N -1:
		dp[i+2] = min(dp[i+2], dp[i]+abs(h[i+2]-h[i]))
print(dp[-1])