parseInt(x) = parse(Int, x)
n,r = parseInt.(split(readline()))
if n < 10
    r += 100 * (10 - n)
end
println(r)