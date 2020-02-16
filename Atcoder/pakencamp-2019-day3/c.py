n,m = map(int, input().split())
A = [[0] for _ in range(n)]

for i in range(n):
    _a = list(map(int, input().split()))
    A[i] = _a
ans = 0
for i in range(m):
    for j in range(m):
        tmp = 0
        if i == j:continue
        for k in range(n):
            tmp += max(A[k][i], A[k][j])
        ans = max(ans, tmp)
print(ans)
