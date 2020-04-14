parseInt(x) = parse(Int, x)
input() = parseInt(readline())
inputs() = parseInt.(split(readline()))

a,b,c = inputs()

if a == b && b == c
    println("No")
elseif a == b || b == c || c == a
    println("Yes")
else
    println("No")
end