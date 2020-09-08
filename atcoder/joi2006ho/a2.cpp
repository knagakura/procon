#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> cnt(m);
	rep(i,n) rep(j,m) {
		int a; scanf("%d",&a);
		cnt[j]+=a;
	}

	vector<int> p(m);
	iota(p.begin(),p.end(),0);
	stable_sort(p.begin(),p.end(),[&](int i,int j){
		return cnt[i]>cnt[j];
	});
	rep(j,m) printf("%d%c",p[j]+1,j<m-1?' ':'\n');

	return 0;
}
