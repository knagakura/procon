N = int(input())
A = list(map(int, input().split( )))


A = [0] + A + [0]
d = 0
for i in range(N+1):
	d += abs(A[i+1]- A[i])

for i in range(N):
	ans = d - abs(A[i+2]- A[i+1]) - abs(A[i+1]- A[i]) + abs(A[i+2]-A[i])
	print(ans)
