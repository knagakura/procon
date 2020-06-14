#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N)cin >> A[i];
    while(K--){
        vec<l_l> v;
        rep(i,N){
            ll l = max(0LL, i - A[i]);
            ll r = min(N-1, i + A[i]);
            v.emplace_back(l,r);
        }
        vec<ll> I(N+1, 0);
        rep(i,N){
            I[v[i].first]++;
            I[v[i].second+1]--;
        }
        rep(i,N){
            I[i+1]+=I[i];
        }
        I.pop_back();
        bool fin = true;
        rep(i,N){
            if(I[i] != N)fin = false;
        }
        if(fin){
            rep(i,N){
                cout << I[i] << " ";
            }
            cout << endl;
            return 0;
        }
        swap(A, I);
    }
    rep(i,N){
        cout << A[i] << " ";
    }
    cout << endl;
}