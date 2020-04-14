parseInt(x) = parse(Int, x)
n = parseInt(readline())
s,t = chomp.(split(readline()))

for i in 1:n
    print(s[i], t[i])
end

println("")