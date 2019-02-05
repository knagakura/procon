N,M = map(int,input().split())
A = []
B = []
for i in range(N):
	a = list(input())
	A.append(a)
for j in range(M):
	b = list(input())
	B.append(b)

ans = "No"

for i in range(N-M+1):
	for j in range(N-M+1):
		c = 0
		for k in range(M):
			for l in range(M):
				if A[i+k][j+l] == B[k][l]:
					c+=1
		if c == M**2:
			ans = "Yes"
			break

print(ans)