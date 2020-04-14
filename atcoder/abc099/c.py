N = int(input())
l = []
for i in range(N):
	if 6**(i+1) <=N:
		l.append(6**(i+1))
	if 9**(i+1) <= N:
		l.append(9**(i+1))
	if 9**(i+1) >N:
		break
l.sort(reverse =True)
dp = [float("inf")]*(len(l)+1)
print(l)
dp[0] = N
#print(l)
c = 0
for i in range(len(l)):
	if dp[i] - l[i]>=0:
		c+=dp[i]//l[i]
		dp[i+1] = min(dp[i+1], dp[i]%l[i])
	print(c)
	dp[i+1] = min(dp[i+1], dp[i])
print(dp)
print(c+dp[-1])

