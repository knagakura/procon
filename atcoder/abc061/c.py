from collections import defaultdict

N, K = map(int,input().split( ))

a = []
b = []

for i in range(N):
	a_i, b_i = map(int, input().split( ))
	a.append(a_i)
	b.append(b_i)

d = defaultdict(int)

for i in range(N):
    if a[i] in d:
        d[a[i]] += b[i]
    else:
        d[a[i]] = b[i]

d_sorted = sorted(d.items())

l = 0

for i in range(N):
	a_i = d_sorted[i][0]
	b_i = d_sorted[i][1]
	l += b_i
	if l >= K:
		print(a_i)
		break



