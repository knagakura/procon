N = int(input())
A = list(map(int, input().split()))

s = 1
ans = 0
for a in A:	
	while a % 2 == 0:
		a = a // 2
		ans += 1
print(ans)