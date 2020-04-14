N = int(input())
A = list(map(int, input().split()))

import collections
A_c=collections.Counter(A)


keys = [k for k, v in A_c.items() if v >= 2]

keys.sort()

if len(keys) < 2:
	ans = 0
elif A_c.get(keys[len(keys)-1]) >= 4:
	ans = keys[len(keys)-1] * keys[len(keys)-1] 
else:
	ans = keys[len(keys)-1] * keys[len(keys)-2]

print(ans)
