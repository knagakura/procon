a, b = map(int,input().split( ))
x  = (a + b) / 2
ans = int(x)
if (a + b) % 2 == 1:
	ans =  int(x) + 1

print(ans)