parseInt(x) = parse(Int, x)
MOD = 10^9+7
function F(x)
    factorial(big(x))
end
function Comb(n, k)
    return div(F(n),F(k)*F(n-k)) % MOD
end
function main()
    x, y = parseInt.(split(readline()))
    z = min(x, y)
    ans = 0
    if (x + y) % 3 == 0
        n = div(x+y,3)
        l = z - n
        if l >= 0
            ans = Comb(n,l)
        end
    end
    println(ans)
end
main()