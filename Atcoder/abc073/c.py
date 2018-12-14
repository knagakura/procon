N = int(input())
A = []
for i in range(N):
	a = int(input())
	A.append(a)

import collections
A_c=collections.Counter(A)

ans = 0
for k,v in A_c.items():
	if v % 2 == 1:
		ans += 1
print(ans)
