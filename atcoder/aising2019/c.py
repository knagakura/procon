H, W = map(int,input().split( ))
S = []
for i in range(H):
	s = list(input())
	S.append(s)

d_list = [[-1,0],[0,-1],[1,0],[0,1]]
"""
print(S)

for i in range(H):
	for j in range(W):
		print(S[i][j])
"""
S_changed = S
group_list = []
#y行x列（座標表記）
for y in range(H):
	for x in range(W):
		#今いる場所の黒白
		s = S[y][x]
		#今いる場所の文字列ver
		str_xy = str(x) + str(y)
		"""
		#上右下左
		if i - 1 > 0:
			up = S[i-1][j] 
		if j + 1 < W:
			right = S[i][j+1]
		if i + 1 < H:
			down = S[i+1][j]
		if j - 1 > 0:
			left = S[i][j-1]
		"""
		#上下左右ループ
		for d in d_list:
			dx = d[0]
			dy = d[1]
			nx = x + dx
			ny = y + dy
			#上下左右の黒白
			s_udrl = S[ny][nx]
			#盤面内だったら確認していく
			if 0<=nx<W and 0<=ny<H:
				#今いる場所と異なったら、変えていい
				if  s_udrl != s and S_changed[ny][nx] in [".", "#"]:
					if not str_xy in group_list:
						group_list.append(str_xy)
						S_changed[y][x] = str_xy
						S_changed[ny][nx] = str_xy
				elif s_udrl





