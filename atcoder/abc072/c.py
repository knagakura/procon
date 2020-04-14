N = int(input())
a = list(map(int, input().split()))
for i in range(N):
	a.append(a[i] - 1)
	a.append(a[i] + 1)

import collections
a_c=collections.Counter(a)


s_val, s_count=zip(*a_c.most_common())

print(max(s_count))