A, B, K = map(int,input().split( ))
for i in range(K):
	if A%2 ==1:
		A =(A-1)//2 
		B = B + A
		A, B = B, A

	else:
		A = A//2
		B = B+A
		A,B = B,A
if K % 2 ==0:
	print(A,B)
else:
	print(B,A)
