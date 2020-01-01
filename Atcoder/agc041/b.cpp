#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/
template<typename T>
vector<pair<T,long long>> RunLengthEncoder(vector<T> &v){
    vector<pair<T,long long>> RLE;
    long long cnt = 1;
    for(int i = 0; i < (int)v.size(); ++i){
        if(i == (int)v.size()-1){
            RLE.push_back(make_pair(v[i], cnt));
            continue;
        }
        if(v[i] == v[i+1])cnt++;
        else{
            RLE.push_back(make_pair(v[i],cnt));
            cnt = 1;
        }
    }
    return RLE;
}

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N,M,V,P;
    cin>>N>>M>>V>>P;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A));
    reverse(all(A));
    auto rle = RunLengthEncoder(A);
    ll cnt = 0;
    for(auto p:rle){
        if(cnt+p.second> P)break;
        cnt += p.second;
    }
    //printpair(rle);
    reverse(all(A));
    //print(A);
    //cerr<<"cnt: "<<cnt<<endl;
    auto check = [&](ll x){
        int l = upper_bound(all(A), x) - A.begin();
        int r = max({0LL,min(cnt,V - l)});
        //cerr<<x<<" "<<l<<" "<<r<<endl;
        int lidx = l-1;
        int ridx = N - r;
        int cntt = V - (l + r);
        ll sum = 0;
        double len = 0;
        for(int i = l;i < ridx;i++){
            len++;
            sum += A[i];
        }
        sum += cntt * M;
        //cerr<<x + M<<" "<<sum<<" "<<len<<endl;
        return x + M >= ceil(sum / (len));
    };
    ll ng = -1;
    ll ok = 1e9;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)){
            ok = mid;
            //cerr<<"YES"<<endl;
        }
        else{
            ng = mid;
            //cerr<<"NO"<<endl;
        }
    }
    //cerr<<"ok: "<<ok<<endl;
    cout<<A.end() - lower_bound(all(A), ok)<<endl;
}