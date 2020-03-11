#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
int N,M;
int matchn[] = {-1,2,5,5,4,5,6,3,7,6};
vector<bool> in(10, false);
int main() {
	cin>>N>>M;
	vector<int> A(M), B(M);
	rep(i,M){
		cin>>A[i];
		B[i] = matchn[A[i]];
		in[A[i]] = true;
	}
	print(A);
	print(B);
	//1が入ってる場合
	if(in[1]){
		if(N % 2 == 0){
			rep(_,N/2){
				cout<<1;
			}
			cout<<endl;
			return 0;
		}
		else{
			int tmp[] = {7, 5, 2, 3, 8};
			map<int, int> map;
			map[7] = 1;
			map[5] = map[2] = map[3] = 2;
			map[8] = 3;
			rep(j, 5){
				if(in[tmp[j]]){
					cout<<tmp[j];
					rep(i,N/2 - map[tmp[j]]){
						cout<<1;
					}
					cout<<endl;
					return 0;
				}
			}
		}
	}
	//1が入っていない場合


}
//同じコストなら、大きいものを使う
//2,3,5はコストが全て5であるから、5を優先する
//6,9はコストが両方6なので、9を優先する
//1がある場合は、全て1にすることで桁数を最大化できる
//Nが奇数の場合は、7,5,2,3,8のいずれかを使い、辻褄を合わせる