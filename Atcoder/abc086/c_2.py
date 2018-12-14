N = int(input())
x_list = [0]
y_list = [0]
t_list = [0]

for i in range(N):
	t,x,y = map(int, input().split( ))
	t_list.append(t)
	x_list.append(x)
	y_list.append(y)

ans = 'Yes'

for i in range(N):
	t_d = t_list[i+1] - t_list[i]
	x_d = abs(x_list[i+1] - x_list[i])
	y_d = abs(y_list[i+1] - y_list[i])
	xy_d = x_d + y_d
	if xy_d > t_d:
		ans = 'No'
		break
	else:
		if xy_d % 2 != t_d % 2:
			ans = 'No'
			break
print(ans)
