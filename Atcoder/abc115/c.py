N, K = map(int,input().split( ))
H =[]
for i in range(N):
	h = int(input())
	H.append(h)
ansl = []
H.sort()

for i in range(N - K + 1):
	#HK = H[i:i+K]
	#ans = max(HK)-min(HK)
	ans = H[i + K - 1] - H[i]
	ansl.append(ans)

print(min(ansl))
