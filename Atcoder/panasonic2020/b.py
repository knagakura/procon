H ,W = map(int, input().split())

if W == 1 or H == 1:
    print(1)
elif H * W % 2 == 0:
    print(H * W //2)
else:
    print((H * W + 1) // 2)