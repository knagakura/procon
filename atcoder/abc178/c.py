N = int(input())
mod = 10**9 + 7
ans = pow(10,N,mod)
ans -= pow(9,N,mod)
ans -= pow(9,N,mod)
ans += pow(8,N,mod)
ans %= mod
print(ans)