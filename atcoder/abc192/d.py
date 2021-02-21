from collections import defaultdict
X = input()
M = int(input())
def base10int(value, base):
    n = len(value)
    res = 0
    for i in range(n):
        res += pow(base, n-i-1) * int(value[i])
    return res


dic = defaultdict(int)
d = 0
for i in range(len(X)):
    d = max(d, int(X[i]))

if len(X) == 1:
    if int(X) <= M:
        print(1)
    else:
        print(0)
    exit()
ok = d
ng = M+5
while(ng-ok > 1):
    mid = (ok+ng) // 2
    if(base10int(X, mid) <= M):
        ok = mid
    else:
        ng = mid
print(ok-d)