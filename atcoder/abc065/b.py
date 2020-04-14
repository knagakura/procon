N = int(input())
a  = []
for  i  in range(N):
	a.append(int(input()))

ans = 1
while a[0] !=  2:
	n = a[0]
	a[0] = a[n-1]
	ans += 1
	if  ans > N:
		ans = -1
		break

print(ans)