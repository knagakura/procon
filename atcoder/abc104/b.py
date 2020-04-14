s=list(input())
n=len(s)
s_in_not = [a for a in s[1:] if 'C' not in a]
s_not = ''.join(s_in_not)
s_not.islower()
if not s[0]=='A':
    print("WA")
elif not s[2:n-1].count("C")==1:
    print("WA")
elif not s_not.islower()==True:
    print("WA")
else:
    print("AC")
