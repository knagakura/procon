a = []
l = []
for i in range(3):
	x,y = map(int,input().split( ))
	a.append(x)
	a.append(y)
a.sort()
for i in range(4):
	l.append(a.count(i+1))
ans ="YES"
if l.count(3) > 0:
	ans = "NO"
print(ans)
