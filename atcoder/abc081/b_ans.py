N = int(input())
A = list(map(int, input().split()))

def percent_2(x):
	x = x % 2
	return x

def slash_2(x):
	x = x / 2
	return x
ans = 0

while sum(list(map(percent_2, A))) == 0:
	ans += 1
	A = list(map(slash_2, A))
print(ans)
