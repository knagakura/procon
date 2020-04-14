N = int(input())
F = []
P = []
for i in range(N):
	f = list(map(int, input().split()))
	F.append(f)

for i in range(N):
	p = list(map(int, input().split()))
	P.append(p)
ans = 0
ans_plus_l = []
ans_minus_l = []
count = 0
for i in range(N):
	ans_list = []
	for j in range(10):
		a = F[i][j] * P[i][j]
		ans_list.append(a)
		if sum(ans_list) >=0:
			ans_plus_l.append(sum(ans_list))
			ans += sum(ans_list)
		else:
			ans_minus_l.append(sum(ans_list))


if len(ans_plus_l) == 0:
	ans = max(ans_minus_l)
print(ans)
