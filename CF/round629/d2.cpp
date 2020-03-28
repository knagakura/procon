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
void Cout(vector<int>& a){
    rep(i,a.size()){
        cout << a[i];
        if(i == (int)a.size()-1)cout << endl;
        else cout << " ";
    }
    return;
}
void solve(){
    int N;
    cin >> N;
    vector<ll> t(N);
    rep(i,N)cin>>t[i];
    auto v = RunLengthEncoder(t);
    int M = v.size();
    if(M == 1){
        cout << 1 << endl;
        rep(i,N){
            cout << 1;
            if(i == N-1)cout << endl;
            else cout << " ";
        }
        return;
    }
    vector<int> ans;
    rep(i,int(v.size())){
        rep(j, v[i].second){
            ans.push_back((i%2+1));
        }
    }
    if(M % 2 == 0){
        cout << 2 << endl;
        Cout(ans);
        return;
    }
    //3以上の奇数の場合
    if(v.front().first == v.back().first){
        cout << 2 << endl;
        Cout(ans);
        return;
    }
    //3以上の奇数かつ、最後と最初が異なる場合
    bool ok = false;
    int idx = -1;
    rep(i,M){
        if(v[i].second > 1){
            ok = true;
            idx = i;
            break;
        }
    }
    if(!ok){
        ans[N-1] = 3;
        cout << 3 << endl;
        Cout(ans);
        return;
    }
    //2以上のところがある
    vector<int> ans2;
    bool modd = false;
    rep(i,M){
        int mod = i % 2 + 1;
        int nxt = ((mod == 1) ? 2: 1);
        if(i == idx){
            ans2.push_back(mod);
            rep(j, v[i].second-1){
                ans2.push_back(nxt);
            }
            modd = true;
            continue;
        }
        rep(j,v[i].second){
            if(modd)mod = nxt;
            ans2.push_back(mod);
        }
    }
    cout << 2 << endl;
    Cout(ans2);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;
    cin >> q;
    while(q--){
        solve();
    }
}