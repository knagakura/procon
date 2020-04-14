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

/*------------------------------------*/
int cnt[4];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin>>cnt[0]>>cnt[1]>>cnt[2]>>cnt[3];

    vector<int> vv;
    rep(i,4)rep(_,cnt[i])vv.push_back(i);
    print(vv);


    bool f[2] = {true,true};
    //最初に1を入れないver.
    auto v = RunLengthEncoder(vv);
    printpair(v);
    vector<int>ans1;
    rep(i,3){
        if(v[i].second <= v[i+1].second){
            rep(i,v[i].second){
                if(ans1.empty()){
                    ans1.push_back(0);
                    ans1.push_back(1);
                }
                else{
                    if(ans1.back()==1&&i == 0){
                        ans1.push_back(0);
                        ans1.push_back(1);
                    }
                    if(ans1.back()==1&&i == 1){
                        ans1.push_back(2);
                        ans1.push_back(1);
                    }
                    if(ans1.back()==2&&i == 2){
                        ans1.push_back(3);
                        ans1.push_back(2);
                    }
                }
                
            }
            v[i+1].second -= v[i].second;
            v[i].second = 0;
            if(i == 0){
                v[i+2].second--;
            }
        }
        else{
            f[0] =  false;
            break;
        }
    }
    if(v[3].second !=0)f[0] = false;
    //printpair(v);
    //最初に1を入れるver
    auto v2 = RunLengthEncoder(vv);
    v2[1].second--;
    vector<int>ans2;
    ans2.push_back(1);
    printpair(v2);
    rep(i,3){
        if(v2[i].second <= v2[i+1].second){
            rep(i,v2[i].second){
                    if(ans2.back()==1&&i == 0){
                        ans2.push_back(0);
                        ans2.push_back(1);
                    }
                    if(ans2.back()==1&&i == 1){
                        ans2.push_back(2);
                        ans2.push_back(1);
                    }
                    if(ans2.back()==2&&i == 2){
                        ans2.push_back(3);
                        ans2.push_back(2);
                    }
                }
            v2[i+1].second -= v2[i].second;
            v2[i].second = 0;
            if(i == 0){
                v2[i+2].second--;
            }
        }

        else{
            f[1] = false;
            break;
        }
    }
    //printpair(v2);
    if(v2[3].second !=0)f[1] = false;
    if(f[0]){
        cout<<
        rep(i,(int)ans1.size()){
            cout<<ans1[i];
            if(i ==  (int)ans1.size()-1)cout<<endl;
            else cout<<" ";
        }
        //cerr<<"最初に1入れないやつOK"<<endl;
        return 0;
    }
    if(f[1]){
        rep(i,(int)ans2.size()){
            cout<<ans2[i];
            if(i ==  (int)ans2.size()-1)cout<<endl;
            else cout<<" ";
        }
        //cerr<<"最初に1入れるやつOK"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}