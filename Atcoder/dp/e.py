N,W = map(int,input().split())

w = []
v = []

for i in range(N):
	a,b = map(int,input().split())
	w.append(a)
	v.append(b)
V = max(v)

dp = [[float("inf")]*(N*V+1) for _ in range(N+1)]
dp[0][0] = 0
for i in range(N):
	for sum_v in range(N*V+1):
		if sum_v - v[i] >=0:
			dp[i+1][sum_v] = min(dp[i+1][sum_v], dp[i][sum_v - v[i]] + w[i])

		dp[i+1][sum_v] = min(dp[i+1][sum_v], dp[i][sum_v])


for sum_v in range(N*V+1):
	if dp[N][sum_v] <= W:
		ans = sum_v
print(ans)
