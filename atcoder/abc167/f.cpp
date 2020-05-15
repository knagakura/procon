#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
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

vector<pair<char,long long>> RunLengthEncoder_ForString(string v){
    vector<pair<char,long long>> RLE;
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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vec<string> S(N);
    auto henkan = [&](const string &t) -> i_i{
        string res = "";
        int sz = t.size();
        int cnt = 0;
        rep(i,sz){
            if(t[i] == '(')cnt++;
            if(t[i] == ')'){
                if(cnt == 0){
                    res.push_back(')');
                }
                else{
                    cnt--;
                }
            }
        }
        rep(i,cnt)res.push_back('(');
        if(res.size() == 0){
            return {0, 0};
        }
        auto v = RunLengthEncoder_ForString(res);
        if(v.size() == 1){
            if(v[0].first == ')')return {v[0].second, 0};
            else return {0, v[0].second};
        }
        //assert(v.size() > 2);
        return {v[0].second, v[1].second};
    };
    vector<i_i> T;
    rep(i,N){
        cin >> S[i];
        T.push_back(henkan(S[i]));
        if(T.back() == make_pair(0,0))T.pop_back();
    }
    int sz = T.size();
    ll ans[] = {0,0};
    bool ok[] = {false, false};
    rep(i,sz){
        if(T[i].first == 0)ok[0] = true;
        if(T[i].second == 0)ok[1] = true;
        ans[0] += T[i].first;
        ans[1] += T[i].second;
    }
    if(ans[0] == ans[1]&&ok[0]&&ok[1]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}