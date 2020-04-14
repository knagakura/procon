parseInt(x) = parse(Int, x)
n,k = parseInt.(split(readline()))
num = 1
cnt = 0
while num <= n
    global num = num *  k
    global cnt+=1
end
println(cnt)