n = int(input())
S = []

for i in range(n):
	s = list(input())
	S.append(s)

ans = ''

for i in range(len(S[0])):
	S[0].sort()
	print(S[0])
	for j in range(n-1):
		l = 0
		if S[0][i] in S[j + 1]:
			l += 1
			print(l)
	if l == n - 1:
		ans +=S[0][i]

print(ans)