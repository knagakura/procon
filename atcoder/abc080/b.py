N = int(input())
s=list(map(int, list(str(N))))
ans = 'No'
if N % sum(s) == 0:
	ans = 'Yes'

print(ans)