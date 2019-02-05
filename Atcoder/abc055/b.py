N= int(input())
ans = 1
for i in range(N):
	ans *= i+1
	ans %= 10**9 +7

print(ans)
