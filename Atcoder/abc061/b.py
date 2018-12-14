N, M = map(int,input().split( ))
l = []
for i in range(M):
	a, b = map(int, input().split( ))
	l.append(a)
	l.append(b)

import collections
l_c=collections.Counter(l)


for i in range(N):
	print(l_c[i+1])
