N = int(input())
S = ''
ans_l = []
if N != 0:
	while N != 0:
		if N % 2 == 0:
			N = N // (-2)
			S = '0' + S
		else:
			N = (N-1) // (-2)
			S = '1' + S
else:
	S = '0'
print(S)

