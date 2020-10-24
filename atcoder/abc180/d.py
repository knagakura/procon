
x, y, a, b = map(int, input().split())

ans = 0
while(x * a - x < b and x * a < y):
    x *= a;
    ans += 1
ans += (y-x) // b
x += (y-x) // b * b
if x == y:
    ans -= 1
print(ans)