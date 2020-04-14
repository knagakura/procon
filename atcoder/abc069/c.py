import collections

def per4_2(x):
	if x % 4 == 0:
		return 4
	elif x % 2 == 0 and x % 4 != 0:
		return 2
	else:
		return 1


N = int(input())
a = list(map(int, input().split( )))

a = list(map(per4_2,a))


a_c=collections.Counter(a)

if a_c[4] >=2:
	if a_c[4] >= a_c[1]:
		print('Yes')
	else:
		print('No')
elif a_c[4] == 1 and a_c[2] == 0:
	if a_c[1] <=2:
		print('Yes')
	else:
		print('No')
elif a_c[4] == 1 and a_c[2] > 0:
	if a_c[1] <=1:
		print('Yes')
	else:
		print('No')
elif a_c[4] ==0:
	if a_c[1] ==0:
		print('Yes')
	else:
		print('No')
