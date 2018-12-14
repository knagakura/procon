import statistics
N = int(input())
A = list(map(int, input().split()))

for i in range(N):
	A[i] = A[i] - (i+1)
A.sort()

if N % 2 == 0:
	med1 = A[N // 2 - 1]
	med2 = A[N //2]
	ans = min(sum([abs(a - med1) for a in A]), sum([abs(a - med2) for a in A]))

else:
	med = A[N // 2]
	ans = sum([abs(a - med) for a in A])
	
print(ans)