n = int(input())

robots_finish = []
robots_index = []
for i in range(n):
    x,d = map(int, input().split())
    y = x + d
    robots_finish.append((y,x))
    robots_index.append((x,y))

robots_finish.sort(reverse = True)
robots_index.sort()

reach
for i in range(n-1, 0, -1):
    