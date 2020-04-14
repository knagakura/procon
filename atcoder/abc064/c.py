import numpy as np
N = int(input())
a = list(map(int, input().split()))

d = np.arange(0, 3600, 400)
c = []

for i in range(N):
	for j in range(len(d)-1):
		if d[j] <= a[i] < d[j + 1]:
			c.append(j)
	if a[i] >= 3200:
		c.append(8)

import collections
c_dict=collections.Counter(c)

s_val, s_count=zip(*c_dict.most_common())
nana_ika = [x for x in s_val if x < 8]

if not 8 in s_val:
	print(len(nana_ika), len(nana_ika))

else:
	if len(nana_ika) == 0:
		print(1, c_dict[8])
	elif 8 - len(nana_ika) > c_dict[8]:
		print(len(nana_ika), len(nana_ika) + c_dict[8])
	elif 8 -len(nana_ika) <= c_dict[8]:
		print(len(nana_ika), 8)

