parseInt(x) = parse(Int, x)
a,b,k = parseInt.(split(readline()))
if a + b <= k
    println(0, " ", 0)
else
    if a >= k
        println(a-k," ", b)
    else
        println(0," ", b - k + a)
    end
end