#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int main() {
    string s,t;
    cin>>s>>t;
    map<char, ll> maps,mapt;
    for(int i = 0; i < int(s.size()); ++i){
        maps[s[i]]++;
    }
    for(int i = 0; i < int(t.size()); ++i){
        mapt[t[i]]++;
    }
    for(auto x:mapt){
        auto charr = x.first;
        auto cntt = x.second;
        if(maps[charr] == 0){
            cout<<-1<<endl;
            return 0;
        }
    }
    //愚直にシミュレーションは無理らしい（32bit整数に収まらなくなるので）
    //うまい方法
    //最小共通部分列LCSみたいなやつは？
    //
    vector<vector<int>> vv(40);
    for(int i = 0; i < int(s.size()); ++i){
        vv[int(s[i]-'a')].push_back(i);
    }
    for(int i = 0; i < 40; ++i){
        if((int)vv[i].size()>0){
        vv[i].push_back(INF);
        }
    }
    for(int i = 0; i < 40; ++i){
        if((int)vv[i].size()>0){
            cerr<<char(i+'a')<<": ";
            for(auto vvi:vv[i]){
                cerr<<vvi<<" ";
            }
            cerr<<endl;
        }
    }
    ll ans = 0;
    int preidx = -1;
    for(int i = 0; i < int(t.size()); ++i){
        char now = t[i];
        auto nowv = vv[int(now-'a')];
        //iter: preidxよりも大きい最初の値
        auto iter = upper_bound(all(nowv),preidx);
        cerr<<i<<" "<<now<<" "<<*iter<<endl;
        while(*iter!=INF){
            if(i == int(t.size())){
                i = INF;
                break;
            }
            i++;
            now = t[i];
            preidx = *iter;
            nowv = vv[int(now-'a')];
            cerr<<preidx<<endl;
            auto iter = upper_bound(all(nowv),preidx);
            cerr<<i<<" "<<now<<" "<<*iter<<endl;
            ans += iter - nowv.begin() - preidx;
        }
        ans += int(t.size())-preidx;
    }
    cout<<ans<<endl;

}