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
    int N;
    string S;
    cin >> N >> S;
    int cnt_f = 0;
    int cnt = 0;
    string t = "abacaba";
    vector<int> idxes;
    rep(i,N - 6){
        string tmp = S.substr(i, 7);
        if(t == tmp){
            cnt_f++;
        }
        else{
            // ?があって、それら以外が一致している
            bool ok = true;
            rep(i,7){
                if(tmp[i] == '?')continue;
                if(tmp[i] != t[i])ok = false;
            }
            if(ok){
                cnt++;
                idxes.push_back(i);
            }
        }
    }
    vector<bool> OK(N, true);
    //print(idxes);
    auto check = [&](int idx){
        //print(OK);
        if(not OK[idx])return false;
        string tmp = S.substr(idx, 11);
        for(int i = 1; i < bit(3); i++){
            string a = "abac";
            string b = "aba";
            rep(j,3){
                if(i & bit(j))a.push_back('?');
                else a.push_back(b[j]);
            }
            a.push_back('c');
            a += b;
            //dump(a);
            if(tmp == a)return false;
        }
        return true;
    };
    //cerr << cnt_f << " " << cnt << endl;
    if(cnt_f == 1){
        cout << "Yes" << endl;
        rep(i,N){
            if(S[i] == '?')cout << 'd';
            else cout << S[i];
        }
        cout << endl;
    }
    else if(cnt_f == 0 && cnt > 0){
        bool ok = false;
        int start;
        rep(j,idxes.size()){
            if(check(idxes[j])){
                ok = true;
                start = idxes[j];
                break;
            }
            else{
                OK[idxes[j]+4] = false;
            }
        }
        if(ok){
            cout << "Yes" << endl;
            rep(j,7){
                S[start+j] = t[j];
            }
            rep(i,N){
                if(S[i] == '?')cout << 'd';
                else cout << S[i];
            }
            cout << endl;
        }
        else{
            cout << "No" << endl;
        }

    }
    else{
        cout << "No" << endl;
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
/*

abacaba
*/