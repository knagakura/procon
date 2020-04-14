N = int(input())
A = []
for i in range(N):
    a = int(input())
    A.append(a)

B = sorted(A)
maxA = B[-1]
maxA2 = B[-2]


for i in range(N):
    if A[i] == maxA:
        print(maxA2)
    else:
        print(maxA)