A, B, C, D = map(int, input().split( ))
if B <= C or D <= A:
	print(0)
else:
	print(min(B, D)- max(A,C))