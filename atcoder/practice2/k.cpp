#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

#include <atcoder/lazysegtree>
#include <atcoder/modint>
using mint = atcoder::modint998244353;
typedef pair<mint, mint> P;

struct S{
    mint x;
    ll size;
    S(mint x_ = 0, ll size_ = 0): x(x_), size(size_){};
};
S op(S a, S b){
    return S(a.x + b.x, a.size + b.size);
}
S e(){
    return S();
}
S mapping(P x, S a){
    auto [c, d] = x;
    return S(a.x*c + a.size*d, a.size);
}
P composision(P f, P g){
    auto [a, b] = g;
    auto [c, d] = f;
    return make_pair(a * c, b * c + d);
}
P id(){
    return make_pair(mint(1), mint(0));
}

int main() {
    int N, Q;
    cin >> N >> Q;
    atcoder::lazy_segtree<S, op, e, P, mapping, composision, id> T(N);
    rep(i,N){
        ll a;
        cin >> a;
        T.set(i, S(a, 1));
    }
    while(Q--){
        int type;
        cin >> type;
        if(type == 0){
            int l, r;
            ll b, c;
            cin >> l >> r >> b >> c;
            T.apply(l, r, make_pair(b, c));
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << T.prod(l, r).x.val() << endl;
        }
    }
}
