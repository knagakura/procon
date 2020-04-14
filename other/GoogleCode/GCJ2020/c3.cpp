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
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
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
void solve(){
    int N;
    cin >> N;
    vector<pair<int, pair<int, int>>> v;
    //vector<int> imos(24 * 60 + 5);
    rep(i,N){
        int a, b;
        cin >> a >> b;
        //imos[a]++;
        //imos[b]--;
        v.push_back({a, {1, i}});
        v.push_back({b, {0, i}});
    }

    /*
    //3つ以上重なっているかどうか確認
    rep(i,24*60+1)imos[i+1]+=imos[i];
    rep(i,24 * 60 + 1){
        if(imos[i] >= 3){
            cout << "IMPOSSIBLE" << endl;
            //return;
        }
    }*/

    //3つ以上重なっていない
    sort(all(v));
    //print(v);
    vector<char> ans(N);
    vector<int> now;
    int M = v.size();
    for(int i = 0; i < M;i++){
        int sz = now.size();
        int in = v[i].second.first;
        int id = v[i].second.second;
        if(sz == 0){
            if(in){
                now.push_back(id);
                ans[id] = 'C';
            }
            else{
                cerr << "壊れる" <<endl;
            }
        }
        if(sz == 1){
            if(in){
                ans[id] = (ans[now[0]]== 'C')?'J':'C';
                now.push_back(id);
            }
            else{
                now.pop_back();
            }
        }
        if(sz == 2){
            if(in){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
            else{
                if(now[0] == id){
                    int tmp = now[1];
                    now.pop_back();
                    now.pop_back();
                    now.push_back(tmp);
                }
                else{
                    now.pop_back();    
                }
            }
        }
    }
    rep(i,N)cout<<ans[i];
    cout<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    rep1(i, t+1){
        cout  << "Case #" << i << ": ";
        solve();
    }
}