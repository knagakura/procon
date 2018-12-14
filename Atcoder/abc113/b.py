N = int(input())
T, A = map(int,input().split( ))
H = list(map(int,input().split( )))

l = []
for i in range(N):
	l.append(abs(A-(T - H[i] * 0.006)))

print(l.index(min(l)) + 1)