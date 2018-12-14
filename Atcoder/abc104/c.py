D, G = map(int, input().split( ))
p = []
c = []
for i in range(D):
	P,C = map(int, input().split( ))
	p.append(P)
	c.append(C)

mean = []
sum_list = []
for i in range(D):
	s = (i + 1) * 100 * p[i] + c[i]
	m = s / p[i]
	sum_list.append(s)
	mean.append(m)
print(sum_list)
print(mean)