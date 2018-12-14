N = int(input())
F = []
P = []
for i in range(N):
	f = list(map(int, input().split()))
	F.append(f)

ans =0

for i in range(N):
	p = list(map(int, input().split()))
	P.append(p)

for i in range(N):
	for j in range(10):
		print(F[i][j] * P[i][j])
		ans += F[i][j] * P[i][j]
print(ans)