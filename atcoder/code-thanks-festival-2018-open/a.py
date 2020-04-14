t,a,b,c,d = map(int,input().split())
ans = 0

if a <= t and c <= t:
	if a + c <= t:
		ans += b + d
	else:
		ans += d

if a <= t and c > t:
	ans += b

if a > t and c <= t:
	ans += d

if a > t and  c > t:
	ans = 0
print(ans)
