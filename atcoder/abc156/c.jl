parseInt(x) = parse(Int, x)
n = parseInt(readline())

x = parseInt.(split(readline()))

ans = 100000000000000000000

for i in 1:100
    sum = 0
    for j in 1:n
        sum += (x[j] - i)^2
    end
    if sum < ans
        ans = sum
    end
end
println(ans)