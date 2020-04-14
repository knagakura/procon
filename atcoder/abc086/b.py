import math

a,b = map(str, input().split( ))
ab = int(a+b)

ans = 'No'

if math.sqrt(ab).is_integer():
	ans = 'Yes'
print(ans)

