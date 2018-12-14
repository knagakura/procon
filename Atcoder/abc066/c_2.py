N =  int(input())
a = list(map(int,input().split( )))

#if N % 2 == 0:
a_1 = a[0::2]
a_2 = a[1::2]
if N % 2 == 0:
	ans_list = a_2[::-1] + a_1
else:
	ans_list = a_1[::-1] + a_2

ans = ''
for i in range(N):
	if i == N-1:
		ans += str(ans_list[i])
	else:
		ans += str(ans_list[i]) + ' '
print(ans)