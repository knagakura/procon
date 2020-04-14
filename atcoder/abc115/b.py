N = int(input())

P = []
ans = 0
for i in range(N):
	p = int(input())
	P.append(p)
	ans += p
ans -= max(P)//2
print(ans)