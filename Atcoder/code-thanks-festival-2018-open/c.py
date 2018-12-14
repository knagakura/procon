import itertools
N = int(input())
x = list(map(int, input().split()))

x.sort()
def  dis(x):
	return x[i+1] - x[i]

ans = 0
for i in range(N-1):
	xd = dis(x)
	c = (i + 1) * N - (i + 1)**2
	ans += c * xd
print(ans)
