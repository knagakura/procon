def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
def lcm(a, b):
	return (a * b // gcd(a, b))

N = int(input())
t = int(input())
for i in range(N-1):
	T = int(input())
	t = lcm(t,T)
print(t)