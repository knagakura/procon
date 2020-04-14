#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int N;
	cin>>N;
	vector<ll> A(N);
	rep(i,N)cin>>A[i];

	multiset<ll> s;
	rep(i,N){
		auto itr = s.lower_bound(A[i]);
		//自分以下の値がないとき
		if(itr == s.begin()){
			s.insert(A[i]);
		}
		//あるとき
		else{
			--itr;
			s.erase(itr);
			s.insert(A[i]);
		}
	}
	cout<<(int)s.size()<<endl;
}
/*
sの中からA[i]未満の最大値を探し、
それを除いて、A[i]を突っ込む
なかったら普通に突っ込む

2 1 4 5 3
[2]
[1,2]
[1,4]
[1,5]
[3,5]
*/