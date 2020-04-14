N = int(input())
A = list(map(int, input().split( )))


A = [0] + A + [0]
ans = []
for i in range(N):
	ans_list = A[:i+1] + A[i+2:]
	for i in range(N):
		ans.append(abs(ans_list[i+1] - ans_list[i]))

	print(sum(ans))