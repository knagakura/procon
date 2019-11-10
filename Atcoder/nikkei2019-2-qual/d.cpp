#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);
int N,M;
vector<vector<pair<int,ll>>> Graph;

ll dp[123456];

template <typename T>
class SegmentTree{
  public:
    int n;
    T element;
    vector<T> dat;
    function<T(T,T)> operate;
    SegmentTree(){}
    SegmentTree(int n_,T element_,function<T(T,T)> operate_){
        element = element_;
        operate = operate_;
        n = 1;
        while(n < n_) n *= 2;
        dat = vector<T>(n*2,element);
    }
    void update(int k,T a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = operate(dat[k*2+1],dat[k*2+2]);
        }
    }
    T query(int a,int b,int k,int l,int r){
        if(r<=a || b<=l) return element;
        if(a<=l && r<=b) return dat[k];
        T vl = query(a,b,k*2+1,l,(l+r)/2);
        T vr = query(a,b,k*2+2,(l+r)/2,r);
        return operate(vl,vr);
    }
    T query(int a,int b) { return query(a,b,0,0,n); }
    T get(int k){ return query(k,k+1); }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N>>M;
    auto fn = [](ll a,ll b){ return min(a,b);};
    SegmentTree<ll> Seg(N,INFLL,fn);
    //Graph.resize(N);
    rep(i,M){
        int l,r;ll c;
        cin>>l>>r>>c;
        l--;r--;
        Seg.update(l,c);
        Seg.update(r,c);
    }

    ll ans = 0;
    rep(i,N){
        ans += Seg.get(i);
    }
    print(Seg.dat);
    cout<<ans<<endl;
    /*
    rep(i,N){
        dp[i] = INFLL;
    }
    dp[0] = 0;
    rep(i,N){
        for(auto x: Graph[i]){
            ll nx = x.first;
            ll d = x.second;
            chmin(dp[nx], dp[i]+d);
        }
    }
    ll ans = dp[N-1];
    if(ans == INFLL)ans = -1;
    cout<<ans<<endl;
    rep(i,N){
        cerr<<dp[i];
        if(i == N-1)cerr<<endl;
        else cerr<<" ";
    }
    */
}