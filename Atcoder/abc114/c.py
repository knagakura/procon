import math
import numpy as np
import itertools
import sys
N = int(input())

#Nをリストにした（int）
Nl = list(map(int, list(str(N))))

#Nの桁数
size = int(math.log10(N) + 1)

#答え
ans = 0

#3〜m-1桁まで
size_l = list(np.arange(3, size))
for m in size_l:
	c = 3**m - 3 * 2**m + 3 * 1**m
	ans += c
#ここまででm-1桁目まで数え上げてる

A = ['3','5','7']
l = list(itertools.product(A, repeat=size))
def tyo(x):
	if '3' in x and '5' in x and '7' in x:
		return x
	else:
		return ''
def aaa(x):
	ans = ''.join(x)
	if not ans == '':
		return ans
l = list(map(tyo, l))
l = list(map(aaa, l))
l = [item for item in l if item]
l = list(map(int, l))
l.sort()
l = [item for item in l if item <= N]
ans += len(l)
print(ans)

