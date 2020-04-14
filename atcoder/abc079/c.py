abcd = list(input())
l = list(map(int,abcd))
ans_list = []
ans_list.append(l[0]+l[1]+l[2]+l[3])
ans_list.append(l[0]+l[1]+l[2]-l[3])
ans_list.append(l[0]+l[1]-l[2]+l[3])
ans_list.append(l[0]+l[1]-l[2]-l[3])
ans_list.append(l[0]-l[1]+l[2]+l[3])
ans_list.append(l[0]-l[1]+l[2]-l[3])
ans_list.append(l[0]-l[1]-l[2]+l[3])
ans_list.append(l[0]-l[1]-l[2]-l[3])

for i in range(7):
	if ans_list[i] == 7:
		if i == 0:
			print(str(l[0])+'+'+str(l[1])+'+'+str(l[2])+'+'+str(l[3])+'=7')
			break
		elif i == 1:
			print(str(l[0])+'+'+str(l[1])+'+'+str(l[2])+'-'+str(l[3])+'=7')
			break
		elif i == 2:
			print(str(l[0])+'+'+str(l[1])+'-'+str(l[2])+'+'+str(l[3])+'=7')
			break
		elif i == 3:
			print(str(l[0])+'+'+str(l[1])+'-'+str(l[2])+'-'+str(l[3])+'=7')
			break
		elif i == 4:
			print(str(l[0])+'-'+str(l[1])+'+'+str(l[2])+'+'+str(l[3])+'=7')
			break
		elif i == 5:
			print(str(l[0])+'-'+str(l[1])+'+'+str(l[2])+'-'+str(l[3])+'=7')
			break
		elif i == 6:
			print(str(l[0])+'-'+str(l[1])+'-'+str(l[2])+'+'+str(l[3])+'=7')
			break
		elif i == 7:
			print(str(l[0])+'-'+str(l[1])+'-'+str(l[2])+'-'+str(l[3])+'=7')
			break