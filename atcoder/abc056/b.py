W,a,b = map(int,input().split())
A = min(a,b)
B = max(a,b)
if B-A >= W:
	ans = B-A-W
else:
	ans = 0
print(ans)