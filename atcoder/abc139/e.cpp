#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int A[1080][1080];
int main() {
    int N;
    cin>>N;
    map<P,P>  map;
    rep(i,N)rep(j,N-1){
        cin>>A[i][j];
        A[i][j]--;
        //試合{i,A[i][j]}は座標{i,j}にある
        map[{i,A[i][j]}] = {i,j};
    }
    /*rep(i,N)rep(j,N-1){
        cerr<<A[i][j];
        if(j == N-2)cout<<endl;
        else cout<<" ";
    }*/

    //1日でできる試合数は最大でN/2だけ。
    //まだ試合していない2チームができる
    //どのチームを対戦させるかは難しい
    //一気に複数の行を進められる試合をしたいですね普通に
    //i日にする試合を決定していく
    //その前に前計算として、試合{i,j}がどの座標にあるのか情報をほしいので、前計算しておく
    //map[試合] = 座標
    //A（座標）= 試合
    //i行目（選手i）がどこまで進んでいるのか情報を配列でもつかー
    //idx[i]でi行目が何列目まで進んだか
    vector<int> idx(N,0);
    ll ans = 0;
    ll cnt = 0;
    while(true){
        ans++;
        vector<bool> game_ended(N,false);
        cnt = 0;
        ll dekita = 0;
        rep(i,N){
            //i行j列
            int me = i;
            if(idx[me] == N-1){
                cnt++;
                continue;
            }
            int idx_me = idx[i];
            int rival = A[me][idx_me];
            if(game_ended[me]||game_ended[rival]){
                continue;
            }
            P swapGame = {rival,me};
            int idx_swap = map[swapGame].second;
            if(idx_swap == idx[rival]){
                idx[me]++;
                idx[rival]++;
                game_ended[me] = game_ended[rival] = true;
                dekita++;
            }
            else{
                continue;
            }
        }
        //print(idx);
        //cerr<<cnt<<endl;
        //cerr<<dekita<<endl;
        if(cnt == N){
            cout<<ans-1<<endl;
            return 0;
        }
        else if(dekita == 0||ans>N){
            cout<<-1<<endl;
            return 0;
        }
    }
    //cout<<ans-1<<endl;
}