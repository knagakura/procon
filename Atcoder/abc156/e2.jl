parseInt(x) = parse(Int, x);

N_MAX = 2 * 10^5;fac = Array{Int}(N_MAX+1);inv = Array{Int}(N_MAX+1);MOD = 10^9 + 7;
#初期化
function COMINIT();fac[1] = 1;for i in 1:N_MAX-1;fac[i+1] = fac[i] * (i+1) % MOD;end;for i in 1:N_MAX;inv[i] = powermod(fac[i], MOD-2, MOD);end;end;
#nCk
function Comb(n, k);if n <= 0 || k < 0;return 0;end;if k > n;return 0;end;if k == 0 || n == k;return 1;end;return ((fac[n] * inv[k]) % MOD * inv[n-k])%MOD;end;
function H(n, m);return Comb(n + m, m);end;
function main();COMINIT();n,k = parseInt.(split(readline()));m = min(k, n-1);ans = 0;for i in 0:m;ans += (Comb(n,i) * H(n-1-i,i)) % MOD;ans %= MOD;end;println(ans);end;
main();

