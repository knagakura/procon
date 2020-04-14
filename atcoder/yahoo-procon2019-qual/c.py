K,A,B = map(int,input().split( ))

#お金に変えてからビスケットに変えるメリットがある場合
if B-A>2:
	b = 1
	K-=A-b
	b = A
	b+=(K//2)*(B-A)
	b+=K%2
else:
	b = 1+K

print(b)