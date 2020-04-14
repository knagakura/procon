parseInt(x) = parse(Int, x)
MOD = 10^9 + 7
n,a,b = parseInt.(split(readline()))

function inv(x)
    return powermod(x, MOD-2,MOD)
end

function choose(p,q)
    x = 1
    y = 1
    for i in 1:q
        x = x * (p-i+1) % MOD
        y = y * i % MOD
    end
    return x * inv(y) % MOD
end
struct 
    
end
ans = powermod(2,n,MOD) - 1
ans = (ans - choose(n,a) + MOD)%MOD
ans = (ans - choose(n,b) + MOD)%MOD
println(ans%MOD)