#!/usr/bin/ python3.8
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
import numpy as np

MOD = 998244353

N, S = map(int, input().split())
As = list(map(int, input().split()))

U = S+10
answer = 0
f = np.zeros(U, np.int64)
for A in As:
    f[0] += 1
    print(f[A:])
    print()
    f[A:] += f[:-A].copy()
    print(f)
    f %= MOD
    answer += f[S]

answer %= MOD
print(answer)
