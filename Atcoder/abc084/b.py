A,B = map(int, input().split( ))
S = list(input())
ans = 'No'
if S[A] == '-' and S.count('-') == 1:
	ans = 'Yes'
print(ans)