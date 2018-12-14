a,b = map(int, input().split( ))
ans =  'Even'
if a * b % 2 == 1:
	ans = 'Odd'
print(ans)