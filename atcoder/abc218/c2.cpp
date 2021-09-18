#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
using pi=pair<int,int>;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]"; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) { dump_func(__VA_ARGS__) }
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

bool comp(const pi &l,const pi &r){
	double atl=atan2((double)l.second,(double)l.first);
	double atr=atan2((double)r.second,(double)r.first);
	return (atl!=atr)?(atl<atr):((l.first*l.first+l.second*l.second)<(r.first*r.first+r.second*r.second));
}

void z_algorithm(vector<int> &s,vector<int> &arr){
  int i,j,k,l;
	l=s.size();
  arr[0]=l;
  i=1;j=0;
  while(i<l){
    while((i+j)<l){
      if(s[j]!=s[i+j]){break;}
      j++;
    }
    arr[i]=j;
    if(j==0){i++;continue;}
    k=1;
    while((i+k)<l){
      if(k+arr[k]>=arr[i]){break;}
      arr[i+k]=arr[k];
      k++;
    }
    j=arr[i]-k;
    i+=k;
  }
}

vector<int> pts_to_str(vector<pi> pts){
	vector<int> res;
	int gx=0,gy=0;
	for(auto &nx : pts){gx+=nx.first;gy+=nx.second;}
	gx/=((int)pts.size());
	gy/=((int)pts.size());
	vector<pi> vcs;
	for(auto &nx : pts){
		int vx=nx.first-gx;
		int vy=nx.second-gy;
		if(vx==0 && vy==0){continue;}
		vcs.push_back({vx,vy});
	}
	sort(vcs.begin(),vcs.end(),comp);
	int sz=vcs.size();
	for(int i=0;i<sz;i++){
		res.push_back(vcs[i].first*vcs[i].first+vcs[i].second*vcs[i].second);
		res.push_back(vcs[i].first*vcs[(i+1)%sz].first+vcs[i].second*vcs[(i+1)%sz].second);
		res.push_back(vcs[i].first*vcs[(i+1)%sz].second-vcs[i].second*vcs[(i+1)%sz].first);
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<pi> a, b;
    rep(i,n){
        rep(j,n){
            char c;
            cin >> c;
            if(c == '#'){
                a.push_back({i, j});
            }
        }
    }
    rep(i,n){
        rep(j,n){
            char c;
            cin >> c;
            if(c == '#'){
                b.push_back({i, j});
            }
        }
    }
    dump(a);
    dump(b);
	// for(auto &nx : a){
	// 	cin >> nx.first >> nx.second;
	// 	nx.first*=n;nx.second*=n;
	// }
	// for(auto &nx : b){
	// 	cin >> nx.first >> nx.second;
	// 	nx.first*=n;nx.second*=n;
	// }
	if(n==1){cout << "Yes\n";return 0;}
	vector<int> as=pts_to_str(a);
	vector<int> bs=pts_to_str(b);
	if(as.size()!=bs.size()){cout << "No\n";return 0;}
	int sz=as.size();
	vector<int> zs;
	zs.insert(zs.end(),as.begin(),as.end());
	zs.insert(zs.end(),bs.begin(),bs.end());
	zs.insert(zs.end(),bs.begin(),bs.end());
	vector<int> zr(sz*3);
	z_algorithm(zs,zr);
	for(int j=sz;j<2*sz;j+=3){
		if(zr[j]>=sz){cout << "Yes\n";return 0;}
	}
	cout << "No\n";
  return 0;
}
