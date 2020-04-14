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
void pushback(string& s, char c){
    s.push_back(c);
}
void pushtop(string& s, char c){
    string tmp = "";
    tmp.push_back(c);
    s = tmp + s;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin>>S;
    int Q;
    cin>>Q;
    int cnt = 0;
    deque<string> deq;
    deq.push_back(S);
    while(Q--){
        int q;
        cin>>q;
        if(q == 1){
            cnt++;
        }
        else{
            int f;char c;
            cin>>f>>c;
            if(cnt % 2 == 0){
                if(f == 1){
                    string tmp = "";
                    tmp.push_back(c);
                    deq.push_front(tmp);
                }
                else{
                    //pushback(S, c);
                    string tmp = "";
                    tmp.push_back(c);
                    deq.push_back(tmp);
                }
            }
            else{
                if(f == 1){
                    //pushback(S, c);
                    string tmp = "";
                    tmp.push_back(c);
                    deq.push_back(tmp);
                }
                else{
                    //pushtop(S, c);
                    string tmp = "";
                    tmp.push_back(c);
                    deq.push_front(tmp);
                }
            }
        }
        /*
        for_each(deq.begin(), deq.end(), [](string x) {
            cerr << x;
        });
        cerr<<endl;
        */
    }
    if(cnt % 2 == 1){
        for_each(deq.rbegin(), deq.rend(), [](string& x) {
            if(x.size() > 1){
                reverse(all(x));
            }
            cout << x;
        });
        cout<<endl;
    }
    else{
        for_each(deq.begin(), deq.end(), [](string& x) {

            cout << x;
        });
        cout<<endl;
    }
}