T = int(input())
for z in range(T):
    x, y = map(int, input().split())
    ans = []
    flag = 1

    rev_x, rev_y = False, False
    if x < 0:
        rev_x = True
        x = -x

    if y < 0:
        rev_y = True
        y = -y

    n = x + y
    move = [2**i for i in range(n.bit_length())]
    if n == 0:
        minus = 0
    else:
        minus = int("1"*(n.bit_length()), 2) - n

    if minus % 2 == 0:
        minus //= 2
    else:
        flag = 0

    minus = format(minus, "b")
    minus = minus[::-1]
    for i in range(len(minus)):
        if minus[i] == "1":
            move[i] *= -1

    for i in range(len(move)):
        if x % 2 ^ y % 2:
            if x % 2 == 1:
                x -= move[i]//2**i
                if move[i] > 0:
                    ans.append("E")
                else:
                    ans.append("W")
            else:
                y -= move[i]//2**i
                if move[i] > 0:
                    ans.append("N")
                else:
                    ans.append("S")
            x //= 2
            y //= 2

        else:
            flag = 0
            break

    if rev_x:
        for i in range(len(ans)):
            if ans[i] == "E":
                ans[i] = "W"
            elif ans[i] == "W":
                ans[i] = "E"
    if rev_y:
        for i in range(len(ans)):
            if ans[i] == "N":
                ans[i] = "S"
            elif ans[i] == "S":
                ans[i] = "N"


    ans = "".join(ans)
    if flag == 0:
        ans = "IMPOSSIBLE"

    print("Case #" + str(z+1)+":", ans)
