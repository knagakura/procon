parseInt(x) = parse(Int, x)
n = parseInt(readline())
s = chomp(readline())

if n % 2 == 1
    println("No")
else
    cnt = 0
    for i in 1:Int(n/2)
        if s[i] == s[Int(n/2)+i]
            global cnt += 1
        end
    end
    if cnt == Int(n/2)
        println("Yes")
    else
        println("No")
    end
end

