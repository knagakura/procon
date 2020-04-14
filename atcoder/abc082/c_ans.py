N = input()
a = [int(x) for x in input().split()]

b = {}

for i in a:
    if i in b:
        b[i] += 1
    else:
        b[i] = 1
print(b)
ans = 0
for k,v in b.items():
    if v > k:
        ans += ( v - k )
    elif v < k:
        ans += v

print(ans)
