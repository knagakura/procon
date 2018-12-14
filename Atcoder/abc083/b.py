N, A, B = map(int,input().split( ))
ans_list = []
for n in range(N+1):
	n_list = list(map(int, list(str(n))))
	if A <= sum(n_list) <= B:
		ans_list.append(n)

print(sum(ans_list))