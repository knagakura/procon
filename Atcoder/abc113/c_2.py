N ,M = map(int,input().split( ))
l = []
for i in range(M):
	p, y = map(int,input().split( ))
	l.append((y, p, i))
l.sort()


p_count  = [0 for i in range(N)]

l_2 = []
for i in range(M):
	p_count[l[i][1]-1] += 1
	l_2.append((l[i][2], l[i][1], p_count[l[i][1]-1]))
l_2.sort()
for i in range(M):
	print(str(l_2[i][1]).zfill(6)+str(l_2[i][2]).zfill(6))
