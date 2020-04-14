N =  int(input())
a = list(map(int,input().split( )))
ans = a[0]
if N % 2  == 1:
	for i in range(N-1):
		if (i+1) % 2 == 0:
			ans = str(a[i+1]) + ' ' + str(ans)
		else:
			ans = str(ans) + ' ' + str(a[i+1])
else:
	for i in range(N-1):
		if (i+1) % 2 == 1:
			ans = str(a[i+1]) + ' ' + str(ans)
		else:
			ans = str(ans) + ' ' + str(a[i+1])

print(ans)



