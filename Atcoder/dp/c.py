N = int(input())

ABC = []

for i in range(N):
	abc = list(map(int,input().split()))
	ABC.append(abc)

dp = []

for i in range(N):
	dp.append([0,0,0])

dp[0] = ABC[0]

for i in range(N-1):
	for j in range(3):
		for k in range(3):
			if j!=k:
				dp[i+1][k] = max(dp[i+1][k], dp[i][j] + ABC[i+1][k])

print(max(dp[N-1]))
