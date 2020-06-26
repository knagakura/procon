#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main() {
    const ll MAXX = 1000000000000001;
    ll N;
    cin >> N;
    vector<ll> v;
    v.push_back(26);
    while(v.back() <= MAXX)v.push_back(v.back() * 26);
    rep(i,v.size()-1)v[i+1] += v[i];
    ll len = 0;
    rep(i,v.size()){
        if(N<=v[i]){
            len = i+1;
            if(i >= 1)N -= v[i-1];
            break;
        }
    }
    string ans = "";
    N--;//0-indexed;
    while(len--){
        ans.push_back(char('a' + N%26));
        N /= 26;
    }
    reverse(all(ans));
    cout << ans << endl;
}