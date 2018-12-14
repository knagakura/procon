N, Y = map(int, input().split( ))

ans = '-1 -1 -1'
for n in range(N+1):
	for m in range(N-n+1):
		l = N - n - m
		sum_ot = n * 10000 + m * 5000 + l * 1000
		if Y == sum_ot:
			ans = str(n)+ ' ' + str(m) + ' ' + str(l)
			break
print(ans)

