s =input()
Q = int(input())
cnt = 0
for _ in range(Q):
    qs = input().split()
    if qs[0] == '1':
        cnt+=1
    else:
        f = int(qs[1])
        c = qs[2]
        if f == 1:
            if cnt % 2 == 0:
                s = s + c
            else:
                s = c + s
        else:
            if cnt % 2 == 0:
                s = c + s
            else:
                s = s + c
if cnt % 2 == 0:
    print(s[::-1])
else:
    print(s)