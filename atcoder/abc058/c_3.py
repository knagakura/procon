n = int(input())
S = []

for i in range(n):
	s = list(input())
	S.append(s)

l = S[0]
for i in range(n):
	l_and = set(l) & set(S[i])
	l = l_and


print(l)