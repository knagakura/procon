parseInt(x) = parse(Int, x)
n = parseInt(readline())
s = chomp(readline())
cnt = 0
for i = 1:n-3
    if s[i:i+2] == "ABC"
        global cnt+=1
    end
end

println(cnt)