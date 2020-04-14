N,M = map(int,input().split())
ans = 0 
#S型をN個を使い切る
if 2*N <= M:
	M -= 2*N
ans +=  N

#C型で作る
ans += M//4

print(ans)