N,M = map(int,input().split())
A = []
B = []
for i in range(N):
	a,b = map(int,input().split())
	A.append([a,b])
for i in range(M):
	c,d = map(int, input().split())
	B.append([c,d])
#print(A,B)

for i in range(N):
	z = A[i]
	ans = []
	for j in range(M):
		ch = B[j]
		d = abs(z[0]-ch[0]) + abs(z[1]-ch[1])
		ans.append([j,d])
	#print(ans)
	ans.sort(key=lambda x:x[1])
	#print(ans)
	print(ans[0][0]+1)

