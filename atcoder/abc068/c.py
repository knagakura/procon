N, M = map(int,input().split( ))
l = []
for i in range(M):
	a,b = map(int,input().split( ))
	l.append([a, b])

t_a = []
t_b = []

ans = 'IMPOSSIBLE'
for i in range(M):
	if l[i][0] == 1:
		t_a.append(l[i][1])
	elif l[i][1] == N:
		t_b.append(l[i][0])
t_and = set(t_a) & set(t_b)
t_and_l = list(t_and)
if len(t_and_l) > 0:
	ans = 'POSSIBLE'
print(ans)