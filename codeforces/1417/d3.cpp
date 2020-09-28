#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) dump_func(__VA_ARGS__)
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

void solve(){
    int N;
    scanf("%d", &N);
    vector<int> A(N+1);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
    int S = accumulate(A.begin(), A.end(), 0);
    if(S%N){
        printf("-1\n");
        return;
    }
    int M = S/N;
    vector<tuple<int, int, int>> ans;
    vector<int> B(N+1);
    B[0] = S;
    for(int i=2; i<=N; i++){
        ans.emplace_back(1, i, M);
    }
    for(int i=N; i>=2; i--){
        int d = (A[i]-1)/i + 1;
        ans.emplace_back(i, 1, d);
        B[i] += d*i;
        B[1] -= d*i;
        int d2 = B[i]-A[i];
        ans.emplace_back(1, i, d2);
        B[i] -= d2;
        B[1] += d2;
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", int(ans.size()));
    for(auto [i, j, x] : ans){
        printf("%d %d %d\n", i, j, x);
        A[i] -= i*x;
        A[j] += i*x;
        dump(A);
    }
    for(int i=1; i<=N; i++) assert(A[i] == A[1]);
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}
