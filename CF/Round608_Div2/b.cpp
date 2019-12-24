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
/*------------------------------------*/
int N;
string S;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin>>N>>S;
    auto v = RunLengthEncoder_ForString(S);
    int M = v.size();
    printpair(v);
    ll cnt[2] = {0,0};
    char col[2] = {'B','W'};
    vector<int> l[2];
    rep(i,2){
        int pos = 0;
        for(int k = 0;k < M;k++){
            auto p = v[k];
            if(p.first == col[i]){
                if(p.second % 2 == 0){
                    cnt[i] += p.second/2;
                    for(int j = 0;j < p.second/2;j++){
                        l[i].push_back(pos+1 + 2 * j);
                    }
                }
                else{
                    if(0 <= k-1 && k+1 < M && v[k-1].second % 2 == 1 && v[k+1].second % 2 == 1){
                        //cerr<<pos+1<<endl;
                        for(int j = pos + 1 - v[k-1].second;j <= pos+1+v[k+1].second;j++){
                            if(j  < pos+1 && j % 2 == 1){
                                l[i].push_back(j);
                                cnt[i]++;
                            }
                            else if(pos+1<=j && j%2 == 0){
                                l[i].push_back(j);
                                cnt[i]++;
                            }
                        }
                    }
                    else{
                        cnt[i] = INF;
                        break;
                    }
                }
            }
            pos += p.second;
        }
    }
    cerr<<cnt[0]<<" "<<cnt[1]<<endl;
    print(l[0]);
    print(l[1]);
    ll ans = min(cnt[0],cnt[1]);

    if(ans == INF){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    if(cnt[0] < cnt[1]){
        for(auto x:l[0]){
            cout<<x<<" ";
        }
    }
    else{
        for(auto x:l[1]){
            cout<<x<<" ";
        }
    }
    cout<<endl;
}