N = int(input())

root_N = pow(N,1/2)

ans = 1000
for i in range(int(root_N)+1):
	A = i+1
	if N%A == 0:
		B = N//A
		ans_l = max(len(str(A)), len(str(B)))
		ans = min(ans,ans_l)
print(ans)