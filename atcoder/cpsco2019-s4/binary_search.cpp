#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define ALL(a)  (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
    //ソートする必要があるのじゃ…
    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};

    //イテレータを返す
    auto low1 = lower_bound(ALL(a), 4);
    auto up1 = upper_bound(ALL(a), 4);
    auto low2 = lower_bound(ALL(a), 5);
    auto up2 = upper_bound(ALL(a), 5);
    auto low3 = lower_bound(ALL(a), 11);
    auto up3 = upper_bound(ALL(a), 11);


    cout << "up1 - low1 = " << up1 - low1 << endl; //up1 - low1 = 2
    cout << "up2 - low2 = " << up2 - low2 << endl; //up2 - low2 = 0
    cout << "up3 - low3 = " << up3 - low3 << endl; //up3 - low3 = 1

    return 0;
}