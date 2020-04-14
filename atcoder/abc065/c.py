N,M = map(int,input().split())

mod = 10**9 + 7
def kaijou(N):
	x = 1
	for i in range(N):
		x*=i+1
		x%=mod
	return x

kn = kaijou(N)
km = kaijou(M)
if abs(N-M) >=2:
	ans = 0

else:
	if abs(N-M) == 0:
		
		ans = kn*kn*2 % mod

	if abs(N-M) == 1:

		ans = kn * km % mod

print(ans)