H = int(input())

ans = 0
cnt = 1
while(H > 0):
    ans += cnt
    cnt *= 2
    H //= 2
print(ans)