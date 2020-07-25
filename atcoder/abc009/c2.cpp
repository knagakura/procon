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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, K;
    string S;
    cin >> N >> K >> S;
    string T = S;
    sort(all(T));
    string a,b;
    rep(i,N){
        if(S[i] == T[i])continue;
        a.push_back(S[i]);
        b.push_back(T[i]);
    }
    sort(all(b));
    int M = a.size();

    // ソート済の配列、これ以外に変更するのは無駄
    vector<pair<char, int>> v;
    rep(i,M)v.emplace_back(a[i],i);
    sort(all(v));
    // print(v);

    // indexの管理
    // vector<int> idxes[26];
    // rep(i,M){
    //     idxes[a[i]-'a'].push_back(i);
    // }
    // rep(i,26)print(idxes[i]);

    vector<bool> moved(M,false), used(M,true);
    // vector<char> unused;
    string ans = a;
    int cnt = 0;
    rep(i,M){
        char s = a[i];
        char t = v[i].first;
        int idxx = v[i].second;
        if(s == t)continue; //
        // 文字が異なるとき、操作をする
        int add = 0;
        if(not moved[i])add++;
        if(not moved[idxx])add++;
        if(cnt + add > K)continue;
        cnt += add;
        moved[i] = true;
        used[i] = false;
        ans[i] = t;

        if(not moved[idxx]){
            ans[idxx] = ' ';
            moved[idxx] = true;
        }
        else{
            used[idxx] = true;
        }
        // cerr << i << " " << idxx << endl;
        // dump(ans);
    }
    // print(used);
    rep(i,M){
        if(ans[i] == ' '){
            rep(j,M){
                if(not used[j]){
                    ans[i] = a[j];
                    used[j] = true;
                    break;
                }
            }
        }
    }
    int j = 0;
    string ott;
    rep(i,N){
        if(S[i] == T[i])ott.push_back(S[i]);
        else{
            ott.push_back(ans[j]);
            j++;
        }
    }
    cout << ott << endl;
    // dump(S);
    // dump(ott);
    // print(v);
    // int c = 0;
    // rep(i,N)c += S[i] != ott[i];
    // dump(c);
}

/* 
あるiが変更するべきなら変更する

*/
