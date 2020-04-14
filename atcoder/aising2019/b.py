N = int(input())
A, B = map(int,input().split( ))
P = list(map(int,input().split( )))

a = len([p for p in P if p <= A])
b = len([p for p in P if A+1 <= p <= B])
c = len([p for p in P if B+1 <= p])
print(min(a,b,c))
