A, B= map(int,input().split( ))
ans = 'Impossible'
if A % 3 == 0 or B % 3 == 0 or (A + B) % 3 == 0:
	ans = 'Possible'
print(ans)
 