S = list(input())

top = S[0]
ans = 0
for i in range(len(S)):
	if top >= S[i]:
		top = S[i]
		ans += 1
print(ans)