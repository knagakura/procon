S = list(input())
ans = 'yes'
for i in range(len(S)):
	if S[i] in S[i+1:]:
		ans = 'no'
		break
print(ans)