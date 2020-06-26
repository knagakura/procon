res = 0
s = input()
for init in range(100000):
    cur = init
    ok = True
    for i in range(len(s)):
        res = res + 1
        print(res)
        if s[i] == '+':
            cur = cur + 1
        else:
            cur = cur - 1
        if cur < 0:
            ok = False
            break
    if ok:
        break
print(res)