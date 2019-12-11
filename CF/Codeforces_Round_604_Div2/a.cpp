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
vector<pair<T,int>> RunLengthEncoder(vector<T> &v){
    vector<pair<T,int>> RLE;
    int cnt = 1;
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

vector<pair<char,int>> RunLengthEncoder_ForString(string v){
    vector<pair<char,int>> RLE;
    int cnt = 1;
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
/*------------------------------------*/
void solve(){
    string S;
    cin>>S;
    int N = S.size();
    vector<char> ans(N);
    rep(i,N){
        if(S[i] != '?')ans[i] = S[i];
    }
    auto v = RunLengthEncoder_ForString(S);
    int M = v.size();
    rep(i,M){
        if(v[i].first != '?'&&v[i].second >1){
            cout<<-1<<endl;
            return;
        }
    }
    int idx = 0;
    S.push_back('?');
    S.push_back('?');
    rep(k,M){
        if(v[k].first != '?'){
            idx += v[k].second;
            continue;
        }
        int l = idx;
        int r = idx + v[k].second-1;
        //cerr<<l<<" "<<r<<endl;
        for(int i = l;i <= r;i++){
            if(i == 0){
                if(S[1] == '?')ans[0] = 'a';
                else{
                    if(S[1] == 'a')ans[0] = 'b';
                    if(S[1] == 'b')ans[0] = 'c';
                    if(S[1] == 'c')ans[0] = 'a';
                }
                continue;
            }
            if(S[i+1] =='?'){
                if(ans[i-1] == 'c'){
                    ans[i] = 'a';
                }
                else ans[i] = ans[i-1]+1;
            }
            else{
                if(ans[i-1] == 'a'&&ans[i+1] == 'a')ans[i] = 'b';
                if(ans[i-1] == 'a'&&ans[i+1] == 'b')ans[i] = 'c';
                if(ans[i-1] == 'a'&&ans[i+1] == 'c')ans[i] = 'b';
                if(ans[i-1] == 'b'&&ans[i+1] == 'a')ans[i] = 'c';
                if(ans[i-1] == 'b'&&ans[i+1] == 'b')ans[i] = 'c';
                if(ans[i-1] == 'b'&&ans[i+1] == 'c')ans[i] = 'a';
                if(ans[i-1] == 'c'&&ans[i+1] == 'a')ans[i] = 'b';
                if(ans[i-1] == 'c'&&ans[i+1] == 'b')ans[i] = 'a';
                if(ans[i-1] == 'c'&&ans[i+1] == 'c')ans[i] = 'a';
            }
            //cerr<<ans[i]<<endl;
        }
        idx += v[k].second;
    }
    rep(i,N){
        cout<<ans[i];
    }
    cout<<endl;
    //print(ans);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;cin>>t;
    while(t--){
        solve();
    }
}
