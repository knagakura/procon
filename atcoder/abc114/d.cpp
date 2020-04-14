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
map<T,int> factorize(T x){
    map<T,int> mp;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0) {
            x /= i;
            mp[i]++;
        }
        if (x == 1) break;
    }
    if (x != 1) mp[x]++;
    return mp;
}


/*------------------------------------*/
//N!の素因数分解
map<int, int> mapn;
int filter(int i){
    int cnt = 0;
    for(auto x: mapn){
        if(x.second >= i-1){
            cnt++;
        }
    }
    return cnt;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin>>N;


    for(int i = 1; i <= N;i++){
        auto m = factorize(i);
        for(auto x:m){
            mapn[x.first] += x.second;
        }
    }
    for(auto x:mapn){
        cerr<<x.first<<": "<< x.second<<endl;
    }
    ll ans = filter(75) + 
    (filter(3)-1) * filter(25) +
    (filter(5)-1) * filter(15) +
    (filter(3)-2) * filter(5) * (filter(5) - 1) / 2;
    /*
    cerr<<"75: "<<filter(75)<<endl;

    cerr<<"3 * 25: "<<filter(3) * filter(25)<<endl;
    cerr<<"5 * 15: "<<filter(5) * filter(15)<<endl;
    cerr<<"3 * 5 * 5: "<<(filter(3)-2) * filter(5) * (filter(5) - 1) / 2<<endl;
    cerr<<"3: "<<filter(3)<<endl;
    cerr<<"5: "<<filter(5)<<endl;
    */
    cout<<ans<<endl;
}