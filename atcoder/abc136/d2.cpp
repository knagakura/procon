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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string S;
    cin>>S;
    int N = S.size();
    auto v = RunLengthEncoder_ForString(S);
    int M = v.size();
    vector<int> ans(N,0);
    int start = 0;
    int finish = M-1;
    int idx = 0;
    if(v[0].first == 'L'){
        ans[0] =  v[0].second;
        start = 1;
        idx = v[0].second-1;
    }
    if(v[M-1].first=='R'){
        ans[N-1] = v[M-1].second;
        finish = M-2;
    }
    for(int i = start; i+1 <= finish; i+=2){
        int sum = v[i].second + v[i+1].second;
        idx += v[i].second-1;
        if(sum % 2 == 0){
            ans[idx] = sum/2;
            ans[idx+1] = sum/2;
        }
        else{
            if(v[i+1].second % 2 ==0){
                ans[idx] = sum-sum/2;
                ans[idx+1] =  sum/2;
            }
            else{
                ans[idx] = sum/2;
                ans[idx+1] =  sum - sum/2;
                
            }
        }
        idx += v[i+1].second+1;
    }
    rep(i,N){
        cout<<ans[i]<<endl;
    }
}