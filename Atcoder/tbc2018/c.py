N = int(input())
A = []
for i in range(N):
	A.append(int(input()))
A.sort()
B = sorted(A,reverse  = True)

if N % 2  ==1:
	ans_1 = B[0]+B[1]-A[0]-A[0]
	for i in range((N-1)//2-1):
		ans_1 += B[2*i+1]+B[2*i]-A[2*i+1]-A[2*i+2]
	#########################################
	ans_2 = abs(A[0]+A[1]-B[0]-B[0])
	for i in range((N-1)//2-1):
		ans_2 += abs(A[2*i+1]+A[2*i]-B[2*i+1]-B[2*i+2])
else:
	ans_1 = B[0]+B[1]-A[0]-A[0]
	for i in range((N-1)//2-1):
		ans_1 += B[2*i+1]+B[2*i]-A[2*i+1]-A[2*i+2]
	ans_1 += A[N//2]-A[N//2-2]
	#########################################
	ans_2 = A[0]+A[1]-B[0]-B[0]
	for i in range((N-1)//2-1):
		ans_2 += abs(A[2*i+1]+A[2*i]-B[2*i+1]-B[2*i+2])
	ans_2 += B[N//2]-B[N//2-2]
if N == 2:
	ans_1 = abs(A[0]-A[1])
	ans_2 = ans_1
print(max(ans_1,ans_2))
