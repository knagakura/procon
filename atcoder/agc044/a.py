t = int(input())

for _ in range(t):
    ans = 1000000000000000
    N,A,B,C,D = map(int, input().split())
    for i in range(64):
        for j in range(38):
            for k in range(27):
                #calc
                tmp = A*i + B*j + C*k + D
                calc = pow(2,i) * pow(3,j) * pow(5,k)
                tmp += abs(N - calc) * D
                if tmp < ans:
                    ans = tmp
    print(ans)
