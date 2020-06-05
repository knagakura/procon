A, B = map(float, input().split())
B *= 100
ans = 0
for i in range(int(B)):
    ans += A
ans = ans / 100
print(int(ans))