N =int(input())
a = list(map(int,input().split( )))

X = sum(a)
x = 0
ans = 10**100
for i in range(N-1):

	x += a[i]
	ans = min(ans,abs(X - 2 * x))


print(ans)