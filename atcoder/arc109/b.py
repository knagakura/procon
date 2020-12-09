N = int(input())

ng = 0
ok = N+1
a = N * (N+1) // 2
while ok - ng > 1:
    mid = (ok + ng) // 2
    b = N+1-mid
    summ = (N+1) * (N+2) // 2 - b * (b+1) // 2
    if summ >= a:
        ok = mid
    else:
        ng = mid
print(ok)