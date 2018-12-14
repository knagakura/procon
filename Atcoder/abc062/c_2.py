H, W = map(int,input().split( ))

ans = H * W
for i in range(H):
	l_1 = [(i+1) * W, (H - i - 1) * (W//2), (H - i - 1) * (W-(W//2))]
	l_2 = [(i+1) * W, ((H - i - 1)//2) * W, (H-i-1 -((H - i - 1)//2)) * W]
	ans = min(ans, max(l_1) - min(l_1), max(l_2) - min(l_2))


H, W = W, H
for i in range(H):
	l_1 = [(i+1) * W, (H - i - 1) * (W//2), (H - i - 1) * (W-(W//2))]
	l_2 = [(i+1) * W, ((H - i - 1)//2) * W, (H-i-1 -((H - i - 1)//2)) * W]
	ans = min(ans, max(l_1) - min(l_1), max(l_2) - min(l_2))



print(ans)

