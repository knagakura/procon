#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin>>S;
    int N = S.size()+1;
    vector<ll> al(N),ar(N);
    vector<bool> ch(N,false);
    int cnt = 1;
    rep(i,N){
        if(S[i] == S[i+1]){
            if(S[i] == '<')al[i] = cnt-1;
            cnt++;
        }
        else if(S[i] == '<'&&S[i+1] == '>'){
            al[i] = cnt-1;
            al[i+1] = cnt;
            ch[i+1] = true;
            cnt = 1;
        }
        else{
            cnt = 1;
        }
    }
    cnt = 1;
    for (int i = N-2; i >= 1; --i){
        if(S[i] == S[i-1]){
            if(S[i] == '>')ar[i+1] = cnt-1;
            cnt++;
        }
        else if(S[i-1] == '<'&&S[i] == '>'){
            ar[i+1] = cnt-1;
            ar[i] = cnt;
            ch[i] = true;
            cnt = 1;
        }
        else{
            cnt = 1;
        }
    }
    if(S[N-2] == '<'){
        ar[N-1] =  ar[N-2] + 1;
        al[N-1] = al[N-2] + 1;
    }
    else{
        ar[N-1] =  ar[N-2] - 1;
        al[N-1] = al[N-2] - 1;
    }
    
    print(ar);print(al);print(ch);
    cerr<<"   ";
    print(S);
    
    ll ans = 0;
    rep(i,N){
        if(ch[i])ans+=max(ar[i],al[i]);
        else{
            ans += max(ar[i],al[i]);
        }
    }

    cout<<ans<<endl;
}