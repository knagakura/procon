from math import log2

for t in range(int(input())):
    n, m = map(int, input().split())
    c = [0] * 61
    s = 0
    for x in map(int, input().split()):
        c[int(log2(x))] += 1
        s += x

    if s < n:
        print(-1)
        continue
    i, res = 0, 0
    while i < 60:
        print(c)
        #nのi桁目が立っていたら
        if (1<<i)&n != 0:
            print(i, "is on")
            #バッグの中にちょうどのやつがあるならそれを使う
            if c[i] > 0:
                c[i] -= 1
            #ちょうどのやつがないなら
            else:
                #上の桁に探しにいく
                #あったら、そこにいくまでにかかった距離を足す
                while i < 60 and c[i] == 0:
                    i += 1
                    res += 1
                #そこのを使う
                c[i] -= 1
                continue
        # 上の桁に向かうとき、下の桁を上に併合する
        print("c[i] is now ",c[i])
        tmp = c[i] // 2
        c[i + 1] += tmp
        c[i] -= tmp
        i += 1


    print(res)