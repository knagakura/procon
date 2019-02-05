x = int(input())

ans = 1
for b in range(1,32):
	for p in range(2,10):
		l = b**p
		if l <= x and l > ans:
			ans = l
print(ans)