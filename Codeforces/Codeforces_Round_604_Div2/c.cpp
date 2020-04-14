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
    int N;cin>>N;
    vector<ll> p(N);
    rep(i,N)cin>>p[i];
    /*
    if(N < 5){
        cout<<0<<" "<<0<<" "<<0<<endl;
        return;
    }*/
    auto v = RunLengthEncoder(p);
    //printpair(v);
    vector<pair<ll,ll>> anss;
    ll sum = 0;
    rep(i,(int)v.size()){
        if(sum + v[i].second > N/2){
            break;
        }
        sum += v[i].second;
        anss.push_back(v[i]);
    }
    //cerr<<anss.size()<<endl;
    /*
    if((int)anss.size() < 3){
        cout<<0<<" "<<0<<" "<<0<<" "<<endl;
        return;
    }
    */
    ll g = anss[0].second;
    /*
    if(3 * g >= sum){
        cout<<0<<" "<<0<<" "<<0<<" "<<endl;
        return;
    }*/
    
    sum -= g;
    ll s = 0,b = sum;
    //どこまでsilverにするか全探索
    for(int i = 1;i < (int)anss.size();i++){
        s += anss[i].second;
        b -= anss[i].second;
        if(g < s && g < b){
            cout<<g<<" "<<s<<" "<<b<<endl;
            return;
        }
    }
    cout<<0<<" "<<0<<" "<<0<<" "<<endl;
    //cerr<<"だめ"<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}