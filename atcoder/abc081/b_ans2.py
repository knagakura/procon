def how_many_times_divisible(n):
	ans = 0
	while n % 2 == 0:
		n /= 2
		ans += 1
	return ans

N = int(input())
A = list(map(int, input().split()))

ans = min(map(how_many_times_divisible, A))
print(ans)
