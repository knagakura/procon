import math
from functools import reduce


def gcd_list(numbers):
    return reduce(math.gcd, numbers)


N, X=map(int,input().split( ))
x=list(map(int,input().split( )))
def minus_d(x):
	x = abs(x-X)
	return x

def percent_d(x):
	x = x % d
	return x

dis = list(map(minus_d, x))
ans = gcd_list(dis)
print(ans)

