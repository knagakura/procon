 
[Educational Codeforces Round 82 (Rated for Div. 2)](https://codeforces.com/contest/1303)にVirtual参加しました。


[:contents]

### [A - Erasing Zeroes](https://codeforces.com/contest/1303/problem/A)
#### 問題概要
0,1のみで構成された文字列が与えられる。連続する1が一区間になるように削除するために必要な0の数の最小値を求めよ。

#### 解説
両端についている0を除き、1に挟まれた0の数を数えればよい。
C++ではRun Length Encoderを使えば実装が楽になる

Pythonでは、stringのstripをするとすごく楽に実装できるようである
#### 提出
- C++
```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)


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
void solve(){
    string s;
    cin>>s;
    auto v = RunLengthEncoder_ForString(s);
    int cnt = 0;
    for(auto p:v){
        if(p.first == '1')cnt++;
    }
    if(cnt < 2){
        cout<< 0 <<endl;
        return;
    }
    int ans = 0;
    bool ok = false;
    rep(i, v.size() - 1){
        if(!ok && v[i].first == '1')ok = true;
        if(ok && v[i].first == '0')ans += v[i].second;
    }
    cout<< ans <<endl;
}
int main() {

    int q;
    cin>>q;
    while(q--){
        solve();
    }
}
```

- Python
```python
for t in range(int(input())):
    print(input().strip('0').count('0'))
```

### [B - National Project](https://codeforces.com/contest/1303/problem/B)

#### 問題概要
長さN mの道路を一日1 m ずつ舗装する。N日かければ道路を完成させられるが、条件として、半分の長さ(`(N+1)/2`)はよい状態で舗装したい。よい状態の舗装は晴れのときに行われる。今後、g日晴れ、b日雨が周期的に訪れるので、工事が終わるのに必要な日数の最小値を求めよ。

#### 解説
まずNの中に何周期分あるか考える。`(N / (g + b)) + N % (g + b)`という構成になる。
`(N+1) / 2`回gが訪れるのは何周期たったときなのかを考えればよい。

#### [提出](https://codeforces.com/contest/1303/submission/72893325)

```cpp
void solve(){
    ll n,g,b;
    cin>>n>>g>>b;
    ll need = (n + 1) / 2;
    ll cnt = need / g;
    ll addi = need % g;
    
    ll ans = 0;
    
    //ぴったりで終わるなら
    if(addi == 0){
        ans = cnt * (g + b) - b;
    }
    else{
        ans = cnt * (g + b) + addi;
    }
    chmax(ans, n);
    cout<<ans<<endl;
}

```

### [C - Perfect Keyboard](https://codeforces.com/contest/1303/problem/C)
#### 問題概要

パスワードSが与えられる。このパスワードを隣り合うキーボードのみを使って打てる一列の英字キーボードを構成してください。

#### 考えたこと
パスワードの隣り合う文字でグラフを構成し、ループや3つ以上の文字と繋がる文字があったら構成できない。
一列になった場合のみ構成できるので、その一列をDFSで決めて出力したい。

実装がうまくいかなかった。

#### 解説
実はグラフに落とさなくても貪欲で構成できる。
文字を前から見ていき、自分の前後にある文字との関係を保存していき、三つ以上の関係を持った時点で作れなくなる
二つ以下の関係なら、前から貪欲につなげていくだけで構成できる。

#### [提出](https://codeforces.com/contest/1303/submission/72904945)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
int N;
string s;
bool used[26];
void solve(){
    cin>>s;
    N = s.size();
    if(N == 1){
        cout<<YES<<endl;
        rep(i,26){
            cout<<char(i + 'a');
        }
        cout<<endl;
        return;
    }
    rep(i,26)used[i] = false;
    map<char, set<char>> rel; 
    deque<char> ans;
    //実際に構築しながら可否を確認していく
    ans.push_back(s[0]);
    ans.push_back(s[1]);
    used[s[0] - 'a'] = used[s[1] - 'a'] = true;
    rel[s[0]].insert(s[1]);
    rel[s[1]].insert(s[0]);
    bool ok = true;
    rep1(i,N-1){
        //使っていたら、一個前と繋がっていたかどうかを確認する
        if(used[s[i+1] - 'a']){
            if(rel[s[i]].find(s[i+1]) != rel[s[i]].end()){
                continue;
            }
            else{
                ok = false;
                break;
            }
        }
        else{
            //使っていないのに、一個前が埋まっていたら
            if(rel[s[i]].size() == 2){
                ok = false;
                break;
            }
            //埋まってない場合、必ず一個だけである
            else{
                rel[s[i]].insert(s[i+1]);
                rel[s[i+1]].insert(s[i]);
                ans.push_back(s[i+1]);
                used[s[i+1]-'a'] = true;
            }
        }
    }

    if(!ok){
        cout<<NO<<endl;
        return;
    }
    cout<<YES<<endl;
    for(auto x: ans){
        cout<<x;
    }
    rep(i,26){
        if(!used[i]){
            cout<<char(i + 'a');
        }
    }
    cout<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
}
```


### [D - Fill The Bag](https://codeforces.com/contest/1303/problem/D)

#### 解説
桁を下から見ていき貪欲に構成できる。発想として、aの冪をまとめて置くということができなかったので意識したい。
#### [提出](https://codeforces.com/contest/1303/submission/72937504)


```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

ll N,M;
vector<ll> a;
vector<ll> beki;
vector<ll> Nbeki;

int log_2(ll X){
    int res = 0;
    while(X > 1){
        res++;
        X /= 2;
    }
    return res;
}

void solve(){
    cin >> N >> M;
    Nbeki.assign(70, 0);
    rep(i,60){
        if(N & bit(i))Nbeki[i] = 1;
    }
    a.assign(M, 0);
    beki.assign(70, 0);
    ll suma = 0;
    rep(i,M){
        cin>>a[i];
        suma += a[i];
        beki[log_2(a[i])]++;
    }
    if(suma < N){
        cout<< -1 << endl;
        return;
    }
    //print(Nbeki);print(beki);
    ll ans = 0;
    int i = 0;
    while(i <= 60){
        //箱が必要な場合
        if(Nbeki[i] == 1){
            //すでに箱があるなら
            if(beki[i] > 0){
                beki[i]--;
                Nbeki[i]--;
            }
            //ないなら上に探しにく
            //一個上に行くごとに分割が増える
            //上に到達したとき、戻る必要がない
            //なぜなら、それ以下の箱は到達した場所から分割された過程で
            //全て一個以上用意されているからである
            else{
                while(i <= 60){
                    Nbeki[i] = 0;
                    i++;
                    ans++;
                    if(beki[i] > 0)break;
                }
                //上の桁から取る
                beki[i]--;
                //到達したところから次のループを始めるため
                continue;
            }
        }
        beki[i+1] += beki[i] / 2;
        i++;
    }
    cout<<ans<<endl;
    return;
}
int main() {

    int Q;
    cin>>Q;
    while(Q--){
        solve();
    }
}
```
### 参考

- [公式editorial](https://codeforces.com/blog/entry/73872)