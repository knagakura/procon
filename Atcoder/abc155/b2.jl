readline()
f = 1
for a = split(readline())
    n = parse(Int, a)
    if n % 2 == 0 && n % 3 != 0 && n % 5 != 0
        global f = 0
    end
end

println((f == 1) ? "APPROVED" : "DENIED")
