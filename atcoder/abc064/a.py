r, g, b = map(str, input().split( ))
ans = 'NO'

if int(r + g + b) % 4 ==0:
	ans = 'YES'
print(ans)