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

int N,A,B,C;
int ans = INF;
vector<int> l;
vector<int> f;
int MPsum;


void calc(vector<int> f){				//fにどの竹をA,B,C,使わない という情報が入っている
	MPsum = 0;
	vector<int> cnt(4);					//A,B,C,使わないというのに使われた竹の本数をカウントしたベクトル
	for (int i = 0; i < N; ++i){
		if(f[i]==0){					//0がAに使うという意味
			A-=l[i];					//あとで絶対値を取るので、とりあえず引く方向を揃えてあとでプラスに転じさせる
			cnt[0]++;					//Aに使う本数をカウント
		}
		if(f[i]==1){
			B-=l[i];
			cnt[1]++;
		}
		if(f[i]==2){
			C-=l[i];
			cnt[2]++;
		}
		if(f[i]==3){
			cnt[3]++;
		}
	}
	if(cnt[0]>0&&cnt[1]>0&&cnt[2]>0){	//竹はA,B,Cいずれにも一本以上使われなければならないので、そのようなvのときだけMPを計算
		MPsum+=abs(A)+abs(B)+abs(C);	//これが+-だけで消費するMP
		rep(i,3)
			if(cnt[i]>=2){				//接着魔法を使わなければならないのは一つについて二本以上選択した場合
				MPsum+=10*cnt[i]-1;
			}
		ans = min(ans, MPsum);			//最小値に更新
	}
}

void dfs(int depth, vector<int> f){
	if(depth == N)calc(f);				//深さがNに行ったら
	for (int i = 0; i < 4; ++i){
		f[depth] = i;					//深さが竹の番号で、その竹をA,B,C,使わないでi=0,1,2,3とする
		depth++;						//次の深さにいくので++
		dfs(depth,f);					//次へ
	}
}



int main() {
	cin>>N>>A>>B>>C;
	l.resize(N);
	f.resize(N);
	rep(i,N)cin>>l[i];
	dfs(0,f);
	cout<<ans<<endl;
}