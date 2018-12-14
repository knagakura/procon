n, k = map(int,input().split( ))
a = list(map(int,input().split( )))

import collections
s_c=collections.Counter(a)

#それを値とカウントで分ける
key, value=zip(*s_c.most_common())
value.sort()
ans = 0
if len(key) - k >0:
	ans = sum(value[:(len(key)-k)])
print(ans)