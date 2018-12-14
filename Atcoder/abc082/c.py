N = int(input())
a_list = list(map(int, input().split( )))
import collections
a_c=collections.Counter(a_list)

#それを値とカウントで分ける
a_val, a_count=zip(*a_c.most_common())

ans =0
for i in range(len(a_val)):
	if a_val[i] > a_count[i]:
		ans += a_count[i]
	elif a_val[i] < a_count[i]:
		ans += a_count[i] - a_val[i]

print(ans)
