#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

#define bit(k) (1LL<<(k))
typedef long long ll;

const ll INF = bit(31)-1;
int N,q;
vector<ll> value;

//i番目の葉:i + N - 1
//i番目のノードの子: 2 * i + 1, 2 * i + 2
//i番目のノードの親: (i - 1)/2

void update(int i, int x){
    //葉ノードの番号
    i += N - 1;
    //更新
    value[i] +=x;
    //親へ登りながら更新
    while(i > 0){
        i = (i-1)/2;
        //親ノードを更新する
        value[i] = value[i * 2 + 1]+value[i * 2 + 2];
    }
}
ll query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l)return 0;
    if(a <= l && r <= b)return value[k];
    else{
        ll vl = query(a,b,k*2+1,l,(l+r)/2);
        ll vr = query(a,b,k*2+2,(l+r)/2,r);
        return vl+vr;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin>>n>>q;
    N = 1;
    while(n > N)N<<=1;
    value.assign(2 * N - 1,0);
    while(q--){
        int com;
        cin>>com;
        if(com == 0){
            ll i,x;
            cin>>i>>x;
            update(i-1,x);
            //print(value);
        }
        else{
            int s,t;
            cin>>s>>t;
            cout<<query(s-1,t,0,0,N)<<endl;;
        }
    }
}