N = int(input())
X = []
Y = []
for i in range(N):
    x, y = map(int, input().split())
    X.append(x);
    Y.append(y);

ans = 0
for k in range(N):
    for j in range(k):
        for i in range(j):
            a = X[j] - X[i]
            b = Y[j] - Y[i]

            c = X[k] - X[i]
            d = Y[k] - Y[i]
            if abs(a * d - b * c) > 0:
                ans += 1
print(ans)
