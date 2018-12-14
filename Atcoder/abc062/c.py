H, W = map(int,input().split( ))

ans = 0


if H % 2 == 0 or W % 2 == 0:
	ans = H * W
	if W % 2 == 0:
		H, W = W, H
	for i in range(W):
		aaa = abs(((H//2) * (i + 1)) - (W - (i + 1)) * H)
		ans = min(ans, aaa)

if H % 2 == 1 and W % 2 == 1:
	a_l = [((H+1)*(W+1))//4, ((H+1)*(W-1))//4, ((H-1)*W)//2]
	a_1 = max(a_l) - min(a_l)
	H, W = W, H
	a_l = [((H+1)*(W+1))//4, ((H+1)*(W-1))//4, ((H-1)*W)//2]
	a_2 = max(a_l) - min(a_l)
	ans = min(a_1,a_2)


if H % 3 == 0 or W % 3 == 0:
	ans = 0

print(ans)
