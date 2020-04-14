N,A,B = map(int,input().split( ))
ans1 = min(A,B)
ans2 = max(0, A+B-N)
print(ans1,ans2)