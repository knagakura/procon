parseInt(x) = parse(Int, x)
a,b = chomp.(split(readline()))
n = parseInt(a)
m = parseInt(b)

x = a^m
y = b^n

println(min(x, y))