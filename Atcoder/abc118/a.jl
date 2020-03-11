parseInt(x) = parse(Int, x)
A, B = parseInt.(split(readline()))
if B % A == 0
    println(A+B)
else
    println(B-A)
end