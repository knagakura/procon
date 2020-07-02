N, M, K = map(int,input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

cumA = [0] * (N+1)
cumB = [0] * (M+1)

for i in range(N):
    cumA[i+1] = cumA[i] + A[i]
for i in range(M):
    cumB[i+1] = cumB[i] + B[i]

def check(X):
    res = 1e9+1
    for i in range(N+1):
        j = X - i
        if j < 0 or M < j: continue
        if(cumA[i] + cumB[j] < res):
            res = cumA[i] + cumB[j]
    return res <= K

ok = 0
ng = N + M + 1

while ng - ok > 1:
    mid = (ok + ng) // 2
    if(check(mid)): ok = mid
    else: ng = mid

print(ok)