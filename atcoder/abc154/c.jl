parseInt(x) = parse(Int, x)
readline()

A = parseInt.(split(readline()))
B = Set(A)

if length(B) == length(A)
    println("YES")
else
    println("NO")
end