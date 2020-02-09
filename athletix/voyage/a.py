
def is_prime(x):
    if x == 1:
        return False
    for i in range(2,x+1):
        if i * i > x:
            break
        if x % i == 0:
            #print(i)
            return False
    return True
def main():
    s = input()
    aml = s.split()
    m = 0
    A = []
    S = []
    AS_pair = []
    for s in aml:
        if(len(s.split(':')) == 1):
            m = int(s)
            continue
        _a,_s= s.split(':')
        _a = int(_a)
        AS_pair.append([_a, _s])
        A.append(_a)
        S.append(_s)
    N = len(A)
    f = []

    breaked = False
    for a in A:
        if m % a == 0:
            breaked = True
            f.append(True)
        else:
            f.append(False)

    
    #print(A)
    #print(S)
    #print(AS_pair)
    #print(f)
    if not breaked:
        if(is_prime(m)):
            print("prime")
        else:
            print(m)
        return
    ans_pair = []
    for i in range(N):
        if f[i]:
            ans_pair.append(AS_pair[i])
    
    ans_pair = sorted(ans_pair)
    #print(ans_pair)
    ans = ""
    for x in ans_pair:
        ans += x[1]
    print(ans)

main()