N = int(input())
F = []
P = []
for i in range(N):
	f = list(map(int, input().split()))
	F.append(f)
	

for i in range(N):
	p = list(map(int, input().split()))
	P.append(p)
c_plus = []
c_minus = []
ans = 0
for i in range(N):
	for j in range(10):
		a = F[i][j]*P[i][j]
		if a >= 0:
			c_plus.append(a)
		else:
			c_minus.append(a)

ans = sum(c_plus)
if len(c_plus) == 0:
	ans = max(c_minus)
print(ans)

