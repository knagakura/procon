N = int(input())

for a in range(60):
    if a == 0:
        continue
    rem = N - pow(3, a)
    if rem < 0:
        break
    for b in range(60):
        if b == 0:
            continue
        if rem == pow(5, b):
            print(a, b)
            exit()
print(-1)