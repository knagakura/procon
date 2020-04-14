s = chomp(readline())
cnt = 0
for i in 1:length(s)
    #println(s[i], " ", s[length(s)-i+1])
    if s[i] != s[length(s)-i+1]
        global cnt+=1
    end
end
println(Int(cnt/2))
