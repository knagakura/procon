n = int(input())
a = list(map(int, input().split()))

ansl = [0, 0]
s = [0, 0]

for i in range(2):
	for j in range(n):
		s[i] += a[j]
		if (i+j) % 2 == 0:
			if s[i] >=0:
				ansl[i] += abs(s[i]) + 1
				s[i] = -1
		else:
			if s[i] <=0:
				ansl[i] += abs(s[i]) + 1
				s[i] = 1

print(min(ansl))

