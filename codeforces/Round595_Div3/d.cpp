#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int,int> P;

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
const int maxx = 216000;
vector<int> imos(maxx+5, 0);
vector<P> choten[maxx+5];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,K;
    cin>>N>>K;
    priority_queue<P> pq;
    vector<int> ans;
    rep(i,N){
        int l,r;
        cin>>l>>r;
        r++;
        imos[l]++;
        imos[r]--;
        choten[l].push_back({r,i+1});
    }
    rep1(i,maxx){
        imos[i] += imos[i-1];
        for(auto p:choten[i]){
            pq.push(p);
        }
        while(K < imos[i]){
            auto most_r_p = pq.top();
            pq.pop();
            int most_r =  most_r_p.first;
            int idx =  most_r_p.second;
            imos[i]--;
            imos[most_r]++;
            ans.push_back(idx);
        }
    }
    sort(all(ans));
    cout<<ans.size()<<endl;
    rep(i,(int)ans.size()){
        cout<<ans[i];
        if(i == (int)ans.size()-1)cout<<endl;
        else cout<<" ";
    }
}