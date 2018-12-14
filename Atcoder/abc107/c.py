N, K = map(int, input().split( ))
x = list(map(int, input().split( )))

minus = [abs(i) for i in x if i < 0]
minus.sort()
plus  = [i for i in x if i >= 0]

print(minus)
print(plus)

ans_list = []
for i in range(K):
	ans_1 = 0
	ans_2 = 0
	h = min(i,len(plus),len(minus))
	ans_1 += 2 * plus[h] +     minus[K-1-h]
	ans_2 +=     plus[h] + 2 * minus[K-1-h]
	ans_list.append(ans_1,ans_2)

ans = min(ans_list)
print(ans)