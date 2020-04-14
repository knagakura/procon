H,W,B,A = map(int, input().split())
for i in range(H):
    ans = ""
    for j in range(W):
        if i < A:
            if j < B:
                ans += '1'
            else:
                ans += '0'
        else:
            if j < B:
                ans += '0'
            else:
                ans += '1'
    print(ans)

      