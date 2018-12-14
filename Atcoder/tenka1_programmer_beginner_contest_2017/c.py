N = int(input())
ans = 0
r = range(3500)
if N > 2500:
	r = reversed(r)
while ans == 0: 
	for h in r:
		h = h + 1
		for n in r:
			n = n + 1
			up = 4*h*n - n*N - N*h
			down = N*h*n
			if up > 0:
				if down % up == 0:
					w = down // up
					ans = 1
					break
		if ans == 1:
			break
print(h, n , w)