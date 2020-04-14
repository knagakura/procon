X,A,B = map(int,input().split( ))
if  0 < B - A <= X:
	ans = 'safe'
elif B - A <=0:
	ans = 'delicious'
else:
	ans = 'dangerous'
print(ans)