N,M =map(int,input().split( ))
X = list(map(int,input().split( )))
if N >= M or M == 1:
	ans = 0
elif N == 1:
	X.sort()
	ans = X[-1] -X[0]
else:
	X.sort()
	D = []
	for i in range(M-1):
		d = X[i+1] - X[i]
		D.append([i,d])
	#print(X)

	D.sort(key = lambda x:(x[1]),reverse =True)
	#print(D)
	sikiri = []
	for i in range(N-1):
		sikiri.append(D[i][0])
	sikiri.sort()
	ans = X[sikiri[0]] - X[0]
	for i in range(N-1):
		l = sikiri[i]+1
		if i == N-2:
			r = M-1
		else:
			r = sikiri[i+1]
		ans+= X[r]-X[l]
print(ans)
'''
D_sorted = sorted(D)
print(D_sorted)
'''
'''
#ある点の左右の離れている距離
X_d = []
for i in range(len(D)):
	if i == 0:
		X_d.append(D[0])
	else:
		X_d.append(D[i-1] + D[i])
print(X_d)
'''