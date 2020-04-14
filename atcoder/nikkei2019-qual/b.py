from collections import Counter
N = int(input())
A = input()
B = input()
C = input()
ans = 0
for i in range(N):
	l = [A[i],B[i],C[i]]
	c = Counter(l)
	mode = c.most_common(1)[0][1]
	if mode == 1:
		ans += 2
	if mode == 2:
		ans += 1
print(ans)