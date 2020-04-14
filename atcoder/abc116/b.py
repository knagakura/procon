s = int(input())
S = [s]
#print(S)
N = 1000000
for i in range(N):
	if s%2 == 0:
		s = s//2

		#print(s)

		if s in S:
			ans = i+2
			break
		S.append(s)
	else:
		s = 3*s+1

		#print(s)

		if s in S:
			ans = i+2
			break
		S.append(s)
#print(S)
print(ans)

