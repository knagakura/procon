def mod_10(x):
	x = x % 10
	return x

N = int(input())
s = []
for i in range(N):
	s_i = int(input())
	s.append(s_i)

s.sort()

m_l = list(map(mod_10, s))

ans = sum(s)
if ans % 10 ==0:
	for i in range(N):
		if m_l[i] != 0:
			ans = ans - s[i]
			break
if sum(m_l) == 0:
	ans = 0

print(ans)


