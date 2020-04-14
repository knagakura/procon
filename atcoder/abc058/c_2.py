n = int(input())
S = []
ans = ''
for i in range(n):
	s = list(input())
	S.append(s)


S[0].sort()

for i in range(len(S[0])):
	if n == 1:
		ans = ''.join(S[0])
	a = S[0][i]
	l = 0
	for j in range(n - 1):
		if a in S[j + 1]:
			S[j + 1].remove(a)
			l += 1
		if l == n - 1:
			ans += a


print(ans)