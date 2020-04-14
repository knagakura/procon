N = int(input())

cnt = [[0] * 10 for _ in range(10)]

for i in range(1,N+1):
    S = str(i)
    cnt[int(S[0])][int(S[-1])] += 1

ans = 0
for i in range(1,10):
    for j in range(1,10):
        ans += cnt[i][j] * cnt[j][i]
print(ans)