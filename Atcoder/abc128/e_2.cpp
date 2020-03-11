#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
void debug(set<int>& s){
    cerr<<"set: ";
    for(auto x:s){
        cerr<<x<<" ";
    }
    cerr<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,Q;
    cin>>N>>Q;
    vector<pair<int, pair<int, int>>> stx(N);
    rep(i,N){
        cin>>stx[i].second.first>>stx[i].second.second>>stx[i].first;
    }
    //xでソート
    sort(all(stx));
    vector<int> S(N), T(N), X(N);
    rep(i,N){
        S[i] = stx[i].second.first;
        T[i] = stx[i].second.second;
        X[i] = stx[i].first;
    }
    vector<int> D(Q), ans(Q, -1);
    set<int> set;
    map<int, int> idx;
    rep(i,Q){
        cin>>D[i];
        idx[D[i]] = i;
        set.insert(D[i]);
    }

    rep(i,N){

        auto l_itr = set.lower_bound(S[i] - X[i]);
        auto r_itr = set.lower_bound(T[i] - X[i]);
        
        while(l_itr != r_itr){
            ans[idx[*l_itr]] = X[i];
            l_itr = set.erase(l_itr);
        }/*
        while(l_itr != set.end()){
            if(*l_itr >= T[i] - X[i])break;
            ans[idx[*l_itr]] = X[i];
            set.erase(l_itr++);
        }*/
    }
    rep(i,Q){
        cout<<ans[i]<<endl;
    }
}
