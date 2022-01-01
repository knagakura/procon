X = int(input())

ans = 0
for k in range(len(str(X))):
    ans += X
    X //= 10
print(ans)