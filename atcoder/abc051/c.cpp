#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	int sx,sy,tx,ty,dx,dy;
	cin>>sx>>sy>>tx>>ty;
	string ans="";
	dx=abs(tx-sx);
	dy=abs(ty-sy);

	//root1
	rep(i,dy)ans+='U';
	rep(i,dx)ans+='R';

	//root2
	rep(i,dy)ans+='D';
	rep(i,dx)ans+='L';

	//root3
	ans+='L';
	rep(i,dy+1)ans+='U';
	rep(i,dx+1)ans+='R';
	ans+='D';

	//root4
	ans+='R';
	rep(i,dy+1)ans+='D';
	rep(i,dx+1)ans+='L';
	ans+='U';

	cout<<ans<<endl;
}