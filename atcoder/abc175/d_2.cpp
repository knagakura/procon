#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=9223372036854775807;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-10; //微調整用（EPSより小さいと0と判定など）

int ii() { int x; if (scanf("%d", &x)==1) return x; else return 0; }
long long il() { long long x; if (scanf("%lld", &x)==1) return x; else return 0; }
string is() { string x; cin >> x; return x; }
char ic() { char x; cin >> x; return x; }
void oi(int x) { printf("%d ", x); }
void ol(long long x) { printf("%lld ", x); }
void od_nosp(double x) { printf("%.15f", x); } // 古い問題用
void od(double x) { printf("%.15f ", x); }
// long doubleで受け取り、fをLfなどに変えて出力すると、変な数値が出る
// それをなんとかするには独自の出力を作らなければならなそう
void os(const string &s) { printf("%s ", s.c_str()); }
void oc(const char &c) { printf("%c ", c); }
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

// #define gcd __gcd //llは受け取らない C++17~のgcdと違うので注意
// int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll)(n) ; i++ )
#define DREP(i,m,n) for(ll i=(ll)(m) ; i > (ll)(n) ; i-- )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define p_b push_back
#define SZ(x) ((ll)(x).size()) //size()がunsignedなのでエラー避けに
#define endk '\n'


// coutによるpairの出力（空白区切り）
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << " " << p.second << ")";}
// coutによるvectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " "; //"\t"に変えるとTabで見やすく区切る
  }
  return s;
}
// coutによる多次元vectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}

//最大値、最小値の更新。更新したor等しければtrueを返す
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

// -------- template end - //


// - library ------------- //




// --------- library end - //


int main(){

  ll N, K;
  cin >> N >> K;

  vector<ll> ps;
  rep(i, N){
    ps.push_back(il() - 1);
  }

  vector<ll> cs;
  rep(i, N){
    cs.push_back(il());
  }

  // サイクルごとに分解する
  vector<vector<ll> > sccs;
  vector<ll> seen(N, 0);
  rep(i, N){
    if (seen[i]) continue;
    vector<ll> scc;

    ll f = i;
    while(!seen[ps[f]]){
      // 移動先のスコアを入れる
      scc.p_b(cs[ps[f]]);
      seen[ps[f]] = 1;
      f = ps[f];
    }
    sccs.p_b(scc);
  }

  ll ans = -INF; // ansの最低値は -10^9（Ciが全て-10^9だったとしても、1つしか取らなければいいのでこれが最低）
  for (vector<ll> scc : sccs){
    ll len = SZ(scc);
    ll sccsum = 0;
    rep(i, len) sccsum += scc[i];

    // 区間がループしているので、配列を2つにコピーして繋げ、条件に合う区間を全探索
    // d がつくものは、配列をコピーして繋げた（2倍化した）もの
    ll dlen = len * 2;
    vector<ll> dscc(dlen, 0);
    rep(i, len){
      dscc[i] = scc[i];
      dscc[len + i] = scc[i];
    }

    // 累積和を前計算
    // rangesum [l, r) -> cumsum[r] - cumsum[l]
    vector<ll> dcumsum(dlen+1, 0);
    rep(i, dlen) dcumsum[i+1] = dcumsum[i] + dscc[i];

    ll tmp = -INF;
    // K <= len のとき、幅1~K の区間の中で最も大きい部分
    if (K <= len){
      REP(width, 1, K+1){
        // 幅 : 1 ~ K
        // 各ループ、[0, width-1] ~ [len-1, len-1+width-1]
        rep(l, len){
          // [l : 0 ~ len-1
          // r] : l+width-1 -> r) : l+width
          // 開区間で区間和をとるので注意
          ll r = l+width;
          // 右端は、dlen-1 なので、dlen) が最大 
          if (r > dlen) break;
          chmax(tmp, dcumsum[r] - dcumsum[l]);
        }
      }
    }
    // len < K のとき、
    // (1) 全体の合計<=0 なら、幅1~len の区間の中で最も大きい部分
    // (2) 全体の合計>0 なら、(K/len)回×全体の合計 + (幅1~K%len の区間の中で最も大きい部分)
    else{
      if (sccsum <= 0){
        REP(width, 1, len+1){
          // 幅 : 1 ~ len
          // 各ループ、[0, width-1] ~ [len-1, len-1+width-1]
          rep(l, len){
            // [l : 0 ~ len-1
            // r] : l+width-1 -> r) : l+width
            // 開区間で区間和をとるので注意
            ll r = l+width;
            // 右端は、dlen-1 なので、dlen) が最大 
            if (r > dlen) break;
            chmax(tmp, dcumsum[r] - dcumsum[l]);
          }
        }
      }
      else{
        ll base = sccsum * (K / len);

        // まず、K/len周してから、残りを取る場合
        if (K/len != 0) tmp = base; // n周したあと1つも取れない場合（lenの倍数回だけコマを動かす場合）があるのでこれをする
        else tmp = 0; // 全体の合計>0 のとき、必ず+の区間を選べるので、これでいいはず
        REP(width, 1, K%len+1){
          // 幅 : 1 ~ K%len
          // 各ループ、[0, width-1] ~ [len-1, len-1+width-1]
          rep(l, len){
            // [l : 0 ~ len-1
            // r] : l+width-1 -> r) : l+width
            // 開区間で区間和をとるので注意
            ll r = l+width;
            // 右端は、dlen-1 なので、dlen) が最大 
            if (r > dlen) break;
            chmax(tmp, base + dcumsum[r] - dcumsum[l]);
          }
        }

        // K/len > 0 の場合は、このほか、K/len-1周して（つまり周回を1つ減らし）、1周のうちの最も大きな部分を取った方がいい場合がある
        if (K/len > 0){
          base = sccsum * (K/len - 1);
          REP(width, 1, len+1){
            // 幅 : 1 ~ len
            // 各ループ、[0, width-1] ~ [len-1, len-1+width-1]
            rep(l, len){
              // [l : 0 ~ len-1
              // r] : l+width-1 -> r) : l+width
              // 開区間で区間和をとるので注意
              ll r = l+width;
              // 右端は、dlen-1 なので、dlen) が最大 
              if (r > dlen) break;
              chmax(tmp, base + dcumsum[r] - dcumsum[l]);
            }
          }
        }
      }
    }

    chmax(ans, tmp);
  }

  cout << ans << endk;

  
}
