x, y = map(int,input().split( ))
a = [1,3,5,7,8,10,12]
b = [4,6,9,11]
c = [2]

ans = 'No'
if x in a and y in a:
	ans = 'Yes'
elif x in b and y in b:
	ans = 'Yes'
elif x in c and y in c:
	ans = 'Yes'

print(ans)