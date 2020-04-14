#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)


int main() {
	int N,ansX,ansY,ansH,xt,yt,ht,Ht;
	cin>>N;
	vector<int> x(N),y(N),h(N);
	rep(i,N){
		cin>>x[i]>>y[i]>>h[i];
		if(h[i]!=0){
			xt=x[i],yt=y[i],ht=h[i];
		}
	}
	rep(X,101)rep(Y,101){
		Ht = ht+abs(xt-X)+abs(yt-Y);
		int cnt = 0;
		rep(i,N){
			if(h[i]==max(0,Ht-abs(X-x[i])-abs(Y-y[i]))){
				cnt++;
			}
		}
		if(cnt==N){
		ansX=X,ansY=Y,ansH=Ht;
		break;		
		}
	}
	cout<<ansX<<' '<<ansY<<' '<<ansH<<endl;
}
