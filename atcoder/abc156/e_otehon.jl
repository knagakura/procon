parseInt(x) = parse(Int, x)
parseMap(x::Array{SubString{String},1}) = map(parseInt, x)



function binarr(n,mod)
    z=1
    for i in 1:n
        z=z*i%mod
    end
    fac=Array{Int}(n+1)
    inv=Array{Int}(n+1)
    inv[n+1]=powermod(z,mod-2,mod)
    for i in 0:n-1
        inv[n-i]=(inv[n+1-i]*(n-i))%mod
    end
    for i in 0:n
        fac[i+1]=(((z*inv[i+1])%mod)*inv[n+1-i])%mod
    end
    return fac
end

function main()
	mod = 10^9+7
	n,k = readline() |> split |> parseMap
	ba = binarr(n,mod)
	bb = binarr(n-1,mod)
	ans = 0
	for i in 1:min(k+1,n)
			ans = (ans+ba[i]*bb[i]%mod)%mod
		end
		println(ans)
end

main()
