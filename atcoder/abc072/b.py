s = list(input())
ans_l = s[::2]
ans = ''
for i in range(len(ans_l)):
	ans += ans_l[i]

print(ans)
