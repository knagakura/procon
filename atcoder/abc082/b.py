s = list(input())
t = list(input())
s.sort()
t.sort()
t.reverse()

ans = 'No'
n_con = min(len(s), len(t))
for i in range(n_con):
	if s[i] != t[i]:
		com_list = [s[i], t[i]]
		com_list.sort()
		if com_list[0] == s[i]:
			ans = 'Yes'
			break
if s[:n_con] == t[:n_con] and len(s) < len(t):
	ans = 'Yes'
print(ans)