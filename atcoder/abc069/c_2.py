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

ans = 'No'

if a_c[2] == 0:
	if a_c[4]>=a_c[1]-1:
		ans = 'Yes'
else:
	if a_c[4] >=a_c[1]:
		ans = 'Yes'
print(ans)
	

