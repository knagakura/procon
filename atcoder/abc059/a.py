s = list(map(str, input().split()))
for i in range(len(s)):
	s[i] = s[i].title()

ans = s[0][0] + s[1][0] + s[2][0]
print(ans)

