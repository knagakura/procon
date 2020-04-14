N, K = map(int, input().split( ))
ans = (N//K)**3
if K % 2 == 0:
	c = -(N//K)
	for i in range(N):
		if (i + 1) % (K // 2) == 0:
			c += 1
	ans += c**3
print(ans)
