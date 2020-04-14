A, B = map(int, input().split( ))
ans = A + B
if A + B >= 10:
	ans = 'error'
print(ans)