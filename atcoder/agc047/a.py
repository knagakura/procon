
def s2int(a):
    dot_idx = -1
    for j in range(len(a)):
        if a[j] == '.':
            dot_idx = j
            break
    # .がないので末尾につける
    if dot_idx == -1:
        a += ".000000000"
    # .の場所に応じて後ろにつける
    else:
        while len(a) < 10+dot_idx:
            a += "0"
    tmps = ""
    for j in range(len(a)):
        if a[j] == '.':continue
        tmps += a[j]
    return int(tmps)

def Count_two_five(x):
    c2 = 0
    c5 = 0
    while x > 0 and x % 2 == 0:
        x //= 2
        c2 += 1
    while x > 0 and x % 5 == 0:
        x //= 5
        c5 += 1
    c2 = min(c2, 18)
    c5 = min(c5, 18)
    return c2, c5

def main():
    N = int(input())

    C2 = [0] * N
    C5 = [0] * N

    for i in range(N):
        C2[i], C5[i] = Count_two_five(s2int(str(input())))

    Cc = [[0] * 19 for _ in range(19)]

    for i in range(N):
        Cc[C2[i]][C5[i]] += 1

    ans = 0
    for i in range(N):
        Cc[C2[i]][C5[i]] -= 1

        for j in range(19):
            for k in range(19):
                if C2[i] + j >= 18 and C5[i] + k >= 18:
                    ans += Cc[j][k]

        Cc[C2[i]][C5[i]] += 1

    print(ans//2)

main()