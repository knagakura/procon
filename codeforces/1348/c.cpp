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
void solve(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    sort(all(S));
    map<char,int> map;
    rep(i,N){
        map[S[i]]++;
    }
    //1種類なら、均等に分けて、余りが最大
    if(map.size() == 1){
        rep(i,(N+K-1)/K){
            cout << S[0];
        }
        cout << endl;
        return;
    }
    //2種類以上が確定
    char s = S[0];
    char s2;
    rep(i,N-1)if(S[i]!=S[i+1]){
        s2 = S[i+1];
        break;
    }
    //最初の文字で先頭が埋まるなら、色々考えないとあかん
    if(map[s] == K){
        //2種類しかないなら、均等に置くのがよい
        if(map.size() == 2){
                cout << s;
                rep(i,(map[s2]+K-1)/K){
                    cout << s2;
                }
                cout << endl;
        }
        //3種類目以降があるなら、貪欲
        else{
            cout << s;
            for(int i = K; i < N;i++){
                cout << S[i];
            }
            cout << endl;          
        }
    }
    else if(map[s] > K){
        cout << s;
        for(int i = K; i < N;i++){
            cout << S[i];
        }
        cout << endl;
    }
    //先頭に二つ目を置けるなら、そいつ
    else{
        cout << S[K-1] << endl;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}
