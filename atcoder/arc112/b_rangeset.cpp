#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) { dump_func(__VA_ARGS__) }
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
// 閉区間の範囲を管理
template<typename T>
struct RangeSet{
    set<pair<T,T>> st;
    T TINF;
 
    RangeSet(){
        TINF=numeric_limits<T>::max()/2;
        st.emplace(TINF,TINF);
        st.emplace(-TINF,-TINF);
    }
    // [l,r] covered?
    bool contains(T l,T r){
        assert(l<=r);
        auto ite=prev(st.lower_bound({l+1,l+1}));
        return ite->first<=l and r<=ite->second;
    }
    bool contains(T x){
        return contains(x,x);
    }
    // [l, r]がカバーされているなら，その区間を返す. されていないなら[-TINF,-TINF]を返す
    pair<T,T> covered_by(T l,T r){
        assert(l<=r);
        auto ite=prev(st.lower_bound({l+1,l+1}));
        if(ite->first<=l and r<=ite->second) return *ite;
        return make_pair(-TINF,-TINF);
    }
    pair<T,T> covered_by(T x){
        return covered_by(x,x);
    }
    // insert[l,r], 増加量を返す
    T insert(T l,T r){
        assert(l<=r);
        auto ite=prev(st.lower_bound({l+1,l+1}));
        if(ite->first<=l and r<=ite->second) return T(0);
        T sum_erased=T(0);
        if(ite->first<=l and l<=ite->second+1){
            l=ite->first;
            sum_erased+=ite->second-ite->first+1;
            ite=st.erase(ite);
        }else ite=next(ite);
        while(r>ite->second){
            sum_erased+=ite->second-ite->first+1;
            ite=st.erase(ite);
        }
        if(ite->first-1<=r and r<=ite->second){
            sum_erased+=ite->second-ite->first+1;
            r=ite->second;
            st.erase(ite);
        }
        st.emplace(l,r);
        return r-l+1-sum_erased;
    }
    T insert(T x){
        return insert(x,x);
    }
    // erase [l,r], 減少量を返す
    T erase(T l,T r){
        assert(l<=r);
        auto ite=prev(st.lower_bound({l+1,l+1}));
        if(ite->first<=l and r<=ite->second){
            // 完全に1つの区間に包含されている
            if(ite->first<l)  st.emplace(ite->first,l-1);
            if(r<ite->second) st.emplace(r+1,ite->second);
            st.erase(ite);
            return r-l+1;
        }
 
        T ret=T(0);
        if(ite->first<=l and l<=ite->second){
            ret+=ite->second-l+1;// 消えた
            if(ite->first<l) st.emplace(ite->first,l-1);
            ite=st.erase(ite);// 次へ
        }else ite=next(ite);
        while(ite->second<=r){
            ret+=ite->second-ite->first+1;
            ite=st.erase(ite);
        }
        // 右端が区間の間にあるか
        if(ite->first<=r and r<=ite->second){
            ret+=r-ite->first+1;
            if(r<ite->second) st.emplace(r+1,ite->second);
            st.erase(ite);
        }
        return ret;
    }
    T erase(T x){
        return erase(x,x);
    }
    // number of range
    int size(){
        return (int)st.size()-2;
    }
    // mex [x,~)
    int mex(T x=0){
        auto ite=prev(st.lower_bound({x+1,x+1}));
        if(ite->first<=x and x<=ite->second) return ite->second+1;
        else return x;
    }
    void output(){
        cout<<"RangeSet : ";
        for(auto &p:st){
            if(p.first==-TINF or p.second==TINF) continue;
            cout<<"["<<p.first<<", "<<p.second<<"] ";
        }
        cout<<"\n";
    }
};
int main() {
    
}
