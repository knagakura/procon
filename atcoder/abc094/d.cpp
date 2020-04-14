#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

const int INF = 1e9;

int main() {
	int N;
	cin>>N;
	vector<int> a(N);
	rep(i,N)cin>>a[i];
	sort(all(a));
	int maxa = a[N-1];
	int mid = maxa/2;
	int d =  INF;
	int xx = 0;
	rep(i,N){
		if(abs(mid - abs(maxa-a[i]))<d){
			xx = a[i];
			d = abs(mid-abs(maxa-a[i]));
		}
	}
	cout<<maxa<<" "<<xx<<endl;
}