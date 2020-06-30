#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

int main() {
	int N;
	cin>>N;
    string ans;
    ans.push_back('1');
    rep(i,N-1){
        ans.push_back('0');
    }
    cout << ans << endl;
}