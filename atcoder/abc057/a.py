a,b = map(int, input().split())
ans = a+b
if ans >23:
	ans = a+b-24
print(ans)