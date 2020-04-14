N = int(input())
h =  list(map(int,input().split( )))

def my_index_multi(l, x):
    return [i for i, _x in enumerate(l) if _x == x]
def main(h,ans):
	mini = min(h)
	ans += mini
	h_list = list(map(lambda x: x - mini, h))
	zero_list = my_index_multi(h_list, 0)
	r = len(h_list)-1
	if not 0 in zero_list:	
		zero_list.append(0)
	if not r in zero_list:
		zero_list.append(r)
	zero_list.sort()

	print(zero_list)
	print(ans)
	l = len(zero_list)-1

	for i in range(l):
		_l = zero_list[i]
		_r = zero_list[i+1]
		h_n = h_list[_l:_r]
		main(h_n,ans)

	return ans

ans = 0
main(h,ans)

"""
	for i in range(len(l)):
		if l[i] == 0:
			index_r = i
			l_l = l[index_l:index_r]
			l_r = l[index_r+1:]
			print(l_l)
			print(l_r)
			zero_split(l_l)
			zero_split(l_r)
	return 0
zero_split(h)
"""

"""
ans = 0
def func(h_list,ans):
	min_h_list = min(h_list)
	ans += min_h_list
	h_list = list(map(lambda x: x - min_h_list, h_list))
	print(ans)
	func(h_list,ans)
	return 0

func(h,ans)
"""
