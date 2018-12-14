S = list(input())
N = len(S)
for i in range(N):
	n = N - i - 1	#i+1文字消したときの長さ
	if n % 2 == 0:	#それが偶数のとき処理する
		h = n // 2	#半分のところ
		if S[:h]==S[h:n]:
			ans = S[:h]+S[h:n]
			break

print(len(ans))