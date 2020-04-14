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

void turn(string &S, int i){
    if(S[i] == 'W'){
        S[i] = 'B';
    }
    else{
        S[i] = 'W';
    }
    if(i + 1 < (int)
    S.size()){
        if(S[i+1] == 'W'){
            S[i+1] = 'B';
        }else{
            S[i+1] = 'W';
        }
    }
}
int N;
string S;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin>>N>>S;
    auto v = RunLengthEncoder_ForString(S);
    int M = v.size();
    //printpair(v);
    ll cnt[2] = {0,0};
    char col[2] = {'B','W'};
    vector<int> l[2];
    //co[i]に揃えたい
    rep(i,2){
        int pos = 0;
        string tmp = S;
        for(int k = 0;k < M;k++){
            //逆の色
            if(v[k].first == col[(i + 1) % 2]){
                //偶数
                if(v[k].second % 2 == 0){
                    for(int j = 0;j < v[k].second/2;j++){
                        cnt[i]++;
                        turn(tmp, pos + 2 * j);
                        l[i].push_back(pos + 2 * j);
                    }
                }
                //奇数の場合は、先の奇数の反対の色を探す
                //そこまで自分の奇数を持っていく
                else{
                    //手前の偶数個は全て偶数になった
                    //最後の一個を移動させていく
                    //先に同じ色の奇数が存在するか確認しにいく。
                    int r = k;
                    int posr = pos;
                    bool f = false;
                    cerr<<"posr"<<posr<<endl;
                    while(r < M){
                        if(v[r].first == col[(i + 1)%2] && v[r].second % 2 ==1){
                            f = true;
                        }
                        posr += v[r].second;
                        if(f)break;
                        r++;
                    }
                    if(!f){
                        cnt[i] = INF;
                        break;
                    }
                    //見るべきは[pos,posr)
                    cerr<<"posr"<<posr<<endl;
                    for(int p = pos;p <= posr;p++){
                        if(tmp[p] == v[k].first){
                            turn(tmp,p);
                            l[i].push_back(p);
                            cnt[i]++;
                            cerr<<p<<endl;
                            cerr<<tmp<<endl;
                        }
                    }
                    //更新
                    pos = posr;
                    k = r;
                }
            }
            pos += v[k].second;
        }
        cerr<<tmp<<endl;
    }
    //cerr<<cnt[0]<<" "<<cnt[1]<<endl;
    //print(l[0]);
    //print(l[1]);
    ll ans = min(cnt[0],cnt[1]);
    if(ans == INF){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    if(cnt[0] < cnt[1]){
        for(auto x:l[0]){
            cout<<x+1<<" ";
        }
    }
    else{
        for(auto x:l[1]){
            cout<<x+1<<" ";
        }
    }
    cout<<endl;
}