N = int(input())
L = [1]
for i in range(N):
	if 6**(i+1) <=N:
		L.append(6**(i+1))
	if 9**(i+1) <= N:
		L.append(9**(i+1))
	if 6**(i+1) >N:
		break
L.sort(reverse =True)
dp = []
dp = [float("inf")]*(N+1)

dp[0] = 0

for i in range(N+1):
	for l in L:
		if i+l <= N:
			dp[i+l] = min(dp[i+l], dp[i]+1)
print(dp[N])
