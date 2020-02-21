parseInt(x) = parse(Int, x)
n = parseInt(readline())
s = chomp(readline())
for i in 1:length(s)
    a = Char((Int(s[i])-Int('A') + n)%26+Int('A'))
    print(a)
end
println()