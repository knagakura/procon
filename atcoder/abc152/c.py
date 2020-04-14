N = int(input())
P = list(map(int, input().split()))
minn = 1 << 32
ans = 0
for i in range(N):
    if(P[i] <= minn):
        ans += 1
        minn = P[i]
print(ans)