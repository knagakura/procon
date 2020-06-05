N = int(input())
A = list(map(int, input().split()))

for i in range(N):
    if A[i] == 0:
        print(0)
        exit()
ans = 1
for i in range(N):
    ans *= A[i]
    if ans > 1e18:
        print(-1)
        exit()

print(ans)