N = int(input())
p = list(map(int, input().split()))
maxp = max(p)
dp = [[0]*(N*maxp+1) for _ in range(N+1)]
dp[0][0] = 1
for i in range(N):
	for j in range(N*maxp+1):
		if j+p[i] < N*maxp+1:
			if dp[i][j] == 1:
				dp[i][j+p[i]] = max(dp[i][j+p[i]], 1)
ans = 0

for i in range(N+1):
	for j in range(N*maxp+1):
		ans += dp[i][j]
#print(dp)
print(ans)