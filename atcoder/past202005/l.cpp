#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define rep1(i, N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = (ll) 1e9;
const ll INFLL = (ll) 1e18 + 1;
const ll MOD = (ll) 1e9 + 7;
const double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int main() {

    int N;
    cin >> N;
    vec<deque<int>> v(N);
    priority_queue<i_i> pq[2];
    rep(i, N) {
        int K;
        cin >> K;
        rep(j, K) {
            int t;
            cin >> t;
            if (j == 0){
                pq[0].push({t, i});
                pq[1].push({t, i});
            }
            if (j == 1) {
                pq[1].push({t, i});
            }
            v[i].push_back(t);
        }
    }
    auto tmp = pq[0];
    int M;
    cin >> M;
    vec<int> a(M), ans(M);
    rep(i, M)cin >> a[i];
    map<int, int> used;
    //rep(i, N) print(v[i]);
    //print(a);
    rep(k, M) {
        //dump(k);
        //dump(a[k]);
        if (a[k] == 1) {
            while(not pq[0].empty()){
                int t, idx;
                tie(t, idx) = pq[0].top();
                //cerr << t << " " <<idx << endl;
                pq[0].pop();
                if(used[t] > 0)continue;
                if(v[idx].empty())continue;
                ans[k] = t;
                used[t]++;
                v[idx].pop_front();
                if(v[idx].size() > 0)pq[0].push({v[idx][0], idx});
                if(v[idx].size() > 1)pq[1].push({v[idx][1], idx});
                break;
            }
        }
        if (a[k] == 2) {
            while(not pq[1].empty()){
                int t, idx;
                tie(t,idx) = pq[1].top();
                pq[1].pop();
                if(used[t] > 0)continue;
                if(v[idx].empty())continue;
                //cerr << t << " " <<idx << endl;
                ans[k] = t;
                used[t]++;
                if(v[idx].front() == t){
                    v[idx].pop_front();
                    if(v[idx].size() > 0)pq[0].push({v[idx][0],idx});
                    if(v[idx].size() > 1)pq[1].push({v[idx][1],idx});
                }
                else{
                    int tmp_top = v[idx].front();
                    v[idx].pop_front();
                    v[idx].pop_front();
                    v[idx].push_front(tmp_top);
                    if(v[idx].size() > 1)pq[1].push({v[idx][1], idx});
                }
                break;
            }
        }
        //rep(i, N) print(v[i]);
    }
    rep(i,M){
        cout << ans[i] << endl;
    }
}