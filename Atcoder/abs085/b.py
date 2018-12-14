N = int(input())
d_list = []
for i in range(N):
	d = int(input())
	d_list.append(d)

import collections
d_c=collections.Counter(d_list)
d_val, d_count=zip(*d_c.most_common())
print(len(d_val))