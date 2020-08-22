X, K, D = map(int, input().split())
deka = pow(10,20)
X = abs(X)

if K * D < X:
    print(abs(X - K * D))
else:
    cnt1 = X // D
    ans1 = deka
    if cnt1 <= K:
        rem = K - cnt1
        if rem % 2 == 0:
            ans1 = X - cnt1 * D
        else:
            ans1 = abs(X - cnt1 * D - D)
    
    cnt2 = (X+D-1) // D
    ans2 = deka
    if cnt2 <= K:
        rem = K - cnt2
        if rem%2 == 0:
            ans2 = cnt2 * D - X
        else:
            ans2 = abs(cnt2 * D - X - D)
    
    print(min(ans1, ans2))