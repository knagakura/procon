A,R,N = map(int,input().split())

if(R == 1):
    print(A)
else:
    v = [A]
    for i in range(32):
        v.append(v[-1]*R)
        if(v[-1] > 1e9):
            break
    if N < len(v):
        print(v[N-1])
    else:
        print("large")
