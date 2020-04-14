N = int(input())
v = [2, 1]
for i in range(N):
	v.append(v[i]+v[i+1])
print(v[N])
