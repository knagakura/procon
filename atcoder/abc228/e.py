N, K, M = map(int, input().split())

MOD = 998244353



ans = pow(M, pow(K, N, MOD-1), MOD)

print(ans)