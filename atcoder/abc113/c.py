N ,M = map(int,input().split( ))
P = []
Y = []

l = []
for i in range(N):
	l.append([])

for i in range(M):
	p, y = map(int,input().split( ))
	P.append(p)
	Y.append(y)
	l[P[i]-1].append(Y[i])

for i in range(N):
	l[i].sort()


for i in range(M):
	Y[i] = l[P[i]-1].index(Y[i]) + 1
	while len(str(P[i])) < 6 :
		P[i] = '0' + str(P[i])
	while len(str(Y[i])) < 6 :
		Y[i] = '0' + str(Y[i])
	print(P[i] + Y[i])
