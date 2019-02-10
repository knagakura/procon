N,K = map(int,input().split( ))
ans = "NO"
if N%2 == 0:
	if N//2 >=K:
		ans = "YES"
else:
	if N //2+1 >=K:
		ans ="YES"
print(ans)