l = map(int, input().split())
a=list(l)
x1=a[0]
y1=a[1]
x2=a[2]
y2=a[3]
x=x2-x1
y=y2-y1
x3=x2-y
y3=y2+x
x4=x1-y
y4=y1+x
c=[x3, y3, x4, y4]
print(c)
