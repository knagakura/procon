H, W = map(int,input().split( ))
a = []
for i in range(H):
	a_i = str(input())
	a.append(a_i)

s = ''
for i in range(W+2):
	s += '#'
for i in range(H+2):
	if i == 0 or i == H+1:
		print(s)
	else:
		print('#' + a[i-1] + '#')

