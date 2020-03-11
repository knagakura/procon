N,A,B = map(int, input().split())
if A == 0 or A + B == 0:
    print(0)
else:
    ans = (N // (A + B)) * A  + min(A, (N % (A+B)))
    #print(N // (A+B))
    #print(min(B, (N%(A+B))))
    print(ans)

