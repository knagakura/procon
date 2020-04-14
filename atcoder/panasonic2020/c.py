a,b,c = map(int, input().split())
l = 4 * a * b
r = (c - a - b) * (c - a - b)

if c - a - b <= 0:
    print("No")
elif c < a or c < b:
    print("No")
elif l < r:
    print("Yes")
else:
    print("No")