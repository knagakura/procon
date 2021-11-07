N = int(input())
A = list(map(int, input().split()))
X = int(input())

summ = sum(A)

def check(k):
    cnt = k // N
    rem = int(k % N)
    res = cnt * summ
    for i in range(rem):
        res = res + A[i]

    return res > X

ng = 0
ok = int(1e18+5)
while ok - ng > 1:
    mid = (ok + ng) // 2
    if check(mid):
        ok = mid
    else:
        ng = mid
print(ok)

