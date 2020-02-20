parseInt(x) = parse(Int, x)
h, n = parseInt.(split(readline()))
A = parseInt.(split(readline()))
if sum(A) >= h
    println("Yes")
else
    println("No")
end