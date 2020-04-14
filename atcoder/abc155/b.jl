parseInt(x) = parse(Int, x)

function main()
    N = parseInt(readline())
    A = parseInt.(split(readline()))
    for i in 1:N
        if A[i] % 2 == 0 && A[i] % 3 != 0 && A[i] % 5 != 0
            println("DENIED")
            return
        end
    end
    println("APPROVED")
end

main()