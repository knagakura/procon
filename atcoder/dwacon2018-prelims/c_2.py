
s = list(map(int,list(input())))

ans = 0
c2 = 0
c5 = 0

c_2_c = 0
c_5_c = 0

for i in range(len(s)):
	if s[i] == 2:
		c2 += 1
		c_2_c += 1
	else:
		c5 += 1
		c_5_c += 1
		if c2 == c5 and i % 2 == 1:
			ans += 1
			c2 = 0
			c5 = 0

if ans == 0 or c_2_c != c_5_c:
	ans = -1

print(ans)

