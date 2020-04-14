parseInt(x) = parse(Int, x)
n,k,m = parseInt.(split(readline()))
A = parseInt.(split(readline()))
x = 0
for i in 1:n-1
    x += A[i]
end


d = n * m - x
if d > k
    println(-1)
else
    println(max(d,0))
end
