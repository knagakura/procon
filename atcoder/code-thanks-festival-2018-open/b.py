x, y = map(int,input().split())
ans = 'No'
a = 3 * x - y
b = 3 * y - x

if a % 8 == 0  and b % 8 == 0 and a >= 0 and b >= 0:
	ans = 'Yes'
print(ans)