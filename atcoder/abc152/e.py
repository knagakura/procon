def gcd(a: int, b: int) -> int:
    """a, bの最大公約数(greatest common divisor:GCD)を求める
    計算量: O(log(min(a, b)))
    """
    if b == 0:
        return a
    return gcd(b, a%b)
def lcm(x, y):
    return (x * y) // gcd(x, y)

MOD = int(1e9 + 7)

N = int(input())
A = list(map(int, input().split()))

LCM = 1

for i in range(N):
    LCM = lcm(LCM, A[i])
ans = 0
for i in range(N):
    ans += LCM * pow(A[i], MOD - 2, MOD)
print(ans%MOD)