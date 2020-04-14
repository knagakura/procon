N = int(input())
A_1 = list(map(int, input().split( )))
A_2 = list(map(int, input().split( )))

ans_list = []
for i in range(N):
	ans_v = sum(A_1[0:i+1]) + sum(A_2[i:N+1])
	ans_list.append(ans_v)


ans = max(ans_list)
print(ans)