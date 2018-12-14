
#########################################################
#一つのときのみ
n = int(input())

#一行で複数の数字を受けてリストへ
c = list(map(int,input().split( )))

#一行の複数の数字を違う文字へ代入
n,m,X,Y = map(int,input().split( ))


#########################################################






#########################################################
#文字列を一文字ずつ分けてリストへ
#例：apple　→　['a', 'p', 'p', 'l', 'e']
s=list(input())

#何が何文字あるかをdictで返す
import collections
s_c=collections.Counter(s)

#それを値とカウントで分ける
s_val, s_count=zip(*s_c.most_common())

#こっちの方が実用的かもしれない
#aというリストがあり、その中の要素とその数をdicで返す
#要素（key）とその数（value）のリストをとるitems methodで、
#それをkとvに代入
b = {}

for i in a:
    if i in b:
        b[i] += 1
    else:
        b[i] = 1
ans = 0

for k,v in b.items():
####

####
#defaultdictの設定の仕方
from collections import defaultdict
d = defaultdict(int)


####
#複数行の文字列をリストへ
w=[]
for i in range(n):
    w.append(input())

#文字列を辞書順に並び替える
s = input()
t = input()
s_sorted = ''.join(sorted(s))
t_sorted = ''.join(sorted(t, reverse = True))


#########################################################
### 	最大公約数、最小公倍数		###
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
def lcm(a, b):
	return (a * b // gcd(a, b))


#########################################################
