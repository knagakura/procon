N = int(input())
A = []
C2 = [0] * N
C5 = [0] * N

P = 1000000000
for i in range(N):
    tmp = input().split(".")
    if len(tmp) == 2:
        a = int(tmp[1])
        for j in range(9-len(tmp[1])):
            a *= 10
        A.append(int(tmp[0]) * P + a)
    else:
        A.append(int(tmp[0]) * P)
for i in range(N):
    tmpp = A[i]
    tmp2 = A[i]
    while tmpp > 0:
        if tmpp % 2 == 0:
            tmpp //= 2
            C2[i] += 1
        else:
            break
    while tmp2 > 0:
        if tmp2 % 5 == 0:
            tmp2 //= 5
            C5[i] += 1
        else:
            break

Cc = [[0] * 19 for _ in range(19)]

for i in range(N):
    Cc[min(18, C2[i])][min(18, C5[i])]+=1

ans = 0
for i in range(N):
    if C2[i] >= 9 and C5[i] >= 9:
        ans -= 1
    l2 = max(0, 18 - C2[i])
    l5 = max(0, 18 - C5[i])
    for j in range(l2, 19):
        for k in range(l5, 19):
            ans += Cc[j][k]
print(ans//2)