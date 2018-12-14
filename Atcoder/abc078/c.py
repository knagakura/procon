import math

N, M = map(int, input().split( ))
ans = 0

for i in range(int(math.log2(10**9))):
	ans += (1900 * M + 100 * (N - M)) * ((1/2)**M)**i
	
print(ans)