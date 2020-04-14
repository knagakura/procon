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
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N,K;
    cin>>N>>K;
    vector<pair<ll,ll>> dt(N);
    //種類数を固定する
    //種類が同じ中では美味しさが大きいものを優先するとしてよい
    rep(i,N){
        ll t,d;
        cin>>t>>d;
        dt[i] = {d, t};
    }
    sort(all(dt));
    reverse(all(dt));
    map<ll, ll> map;
    ll ans = 0;
    ll sum = 0;
    ll l = 0;
    rep(i,N){
        //大きいK個
        if(i < K){
            map[dt[i].second]++;
            sum += dt[i].first;
            if(i == K-1){
                ll syu = map.size();
                ans = sum + syu * syu;
                l = K-1;
            }
        }
        else{
            //まだ選んでいない種類のものを考えていく
            if(map[dt[i].second] == 0){
                //左端を戻す
                //一個のやつは除いたらダメ
                //除くと種類数を増やすことができないから
                while(0 <= l && map[dt[l].second] == 1){
                    l--;
                }
                if(l == -1)break;
                sum += dt[i].first;
                sum -= dt[l].first;
                map[dt[i].second]++;
                map[dt[l].second]--;
                l--;
                ll syu = map.size();
                chmax(ans, sum + syu * syu);
            }
        }
    }
    cout<<ans<<endl;
}