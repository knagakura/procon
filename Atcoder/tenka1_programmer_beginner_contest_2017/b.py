from collections import defaultdict

N = int(input())
A = []
B = []

d = defaultdict(int)

for i in range(N):
	a, b = map(int, input().split())
	A.append(a)
	B.append(b)
	d[a] = b

ans = max(A)

ans += d[max(A)]

print(ans)

