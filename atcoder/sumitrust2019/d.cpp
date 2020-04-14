#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

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

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    string S;
    cin>>N>>S;
    set<string> set1pre,set2pre,set3;
    string y = "";
    y.push_back(S[0]);
    set1pre.insert(y);
    rep1(i,N){
        set<string> set1,set2;
        string xx = "";
        xx.push_back(S[i]);
        set1.insert(xx);
        for(auto x1:set1pre){
            set1.insert(x1);
            x1.push_back(S[i]);
            set2.insert(x1);
        }
        for(auto x2:set2pre){
            set2.insert(x2);
            x2.push_back(S[i]);
            set3.insert(x2);
        }
        swap(set1pre,set1);
        swap(set2pre,set2);
    }
    cout<<set3.size()<<endl;

}