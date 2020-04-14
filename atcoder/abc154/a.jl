parseInt(x) = parse(Int, x)
s,t = chomp.(split(readline()))
a,b = parseInt.(split(readline()))
u = chomp(readline())

if u == s
    global a-=1
else
    global b-=1
end


println(a, " ",b)
