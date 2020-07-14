#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

using P = pair<int, ll>;
int N;

ll calc(vector<P> &v){
    sort(all(v));
    int sz = v.size();
    ll res = 0;
    priority_queue<ll> pq;
    int idx = sz-1;
    for(int i = N - 1; i >= 0; i--){
        while(idx >= 0 && v[idx].first == i){
            pq.push(v[idx].second);
            idx--;
        }
        if(pq.empty())continue;
        res += pq.top();
        pq.pop();
    }
    return res;
}

void solve(){
    cin >> N;
    vector<P> lefts, rights;
    ll base = 0; // 必ずもらえる点数
    rep(i,N){
        int K;
        ll L, R;
        cin >> K >> L >> R;
        K--;
        ll minn = min(L, R);
        base += minn;
        L -= minn;
        R -= minn;
        // {0,0}
        if(L == R)continue;
        // {X,0}
        if(L > R)lefts.emplace_back(K, L);
        // {0,X}
        if(L < R){
            K++;
            // 同じcalc functionで計算するためにidxを逆順に入れかえる
            rights.emplace_back(N-1-K, R);
        }
    }
    cout << base + calc(lefts) + calc(rights) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)solve();
}
