N = int(input())
D, X = map(int, input().split( ))
ans = X
for i in range(N):
	A = int(input())
	if D == A * (D//A):
		ans += D//A

	else:
		ans += D//A + 1 

print(ans)