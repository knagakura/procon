N, K = map(int, input().split( ))
x = list(map(int, input().split( )))
ans_list = []
for i in range(N-K+1):
	ans_list.append(abs(x[i])+abs(x[i]-x[K+i-1]))
	ans_list.append(abs(x[K+i-1])+abs(x[i]-x[K+i-1]))
print(min(ans_list))
	