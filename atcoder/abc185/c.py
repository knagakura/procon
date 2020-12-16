def f(n, k):
    res = 1
    for i in range(k):
        res *= (n - i)
    for i in range(k):
        res = res // (i+1)
    return res

l = int(input())
print(f(l-1, 11))