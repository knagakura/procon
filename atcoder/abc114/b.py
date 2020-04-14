S = list(input())
l = []
for i in range(len(S)-2):
	x = S[i] + S[i+1] + S[i+2]
	x = int(x)
	ans = abs(753 - x)
	l.append(ans)
print(min(l))