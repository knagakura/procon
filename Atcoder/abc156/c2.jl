parseInt(x) = parse(Int, x)
n = parseInt(readline())
x = parseInt.(split(readline()))

ans = 100000000000000000000
tmp = 0
for i in 1:100
    tmp = 0
    for j in 1:n
        tmp += (x[j] - i)^2
    end
    if tmp < ans
        ans = tmp
    end
end
println(ans)
