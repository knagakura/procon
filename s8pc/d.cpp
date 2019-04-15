#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int N;
vector<double> X(100005),R(100005);
vector<pair<double,double>> XR;


int main() {
	cin>>N;
	double ans = 0;
	rep(i,N){
		cin>>X[i]>>R[i];
		XR.push_back({X[i],R[i]});
		ans = max(ans,R[i]);
	}
	sort(all(XR));
	if(N==2){
		double X0 = XR[0].first;
		double X1 = XR[1].first;
		double R0 = XR[0].second;
		double R1 = XR[1].second;
		
		if(X1-X0<=R0){
			double nR1 = pow(pow((R0-(X1-X0)),3)+pow(R1,3),1.0/3.0);
			ans = max(ans,nR1);
			double nR2 = pow(pow((R1-(X1-X0)),3)+pow(R0,3),1.0/3.0);
			ans = max(ans,nR2);
		}
	else if (N<=15){
		
	}
	}
	cout<<ans<<endl;
}