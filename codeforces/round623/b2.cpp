#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define F first
#define S second

//#define ONLINE_JUDGE 1

using namespace std;

const int mod = 1e9+7;


int main(){
	#ifndef ONLINE_JUDGE	
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n),p[n+1];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			p[a[i]].push_back(i);
		}
		bool ok = false;
		for(int i = 1; i <= n; i++){
			int sz = p[i].size();
			if(sz==0) continue;
			if(p[i][sz-1] - p[i][0] > 1) ok = true;
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";	
	}	
	return 0;
}