N = int(input())
l = list(map(int,input().split( )))

lmax = max(l)
lsum = sum(l) - lmax
ans = "No"
if lmax < lsum:
	ans = "Yes"
print(ans)