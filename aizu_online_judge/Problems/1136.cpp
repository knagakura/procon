#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vp;
typedef vector<vp> vvp;

void rotate(vp &a){
    for(int i = 0; i < (int)a.size();i++){
        auto tmp = a[i];
        a[i].first = -tmp.second;
        a[i].second = tmp.first;
       }
}

bool check(vp a, vp b){
    if(a == b)return true;
    reverse(all(b));
    if(a == b)return true;
    return false;
}

bool issame(vp a,vp b){
    rep(i,4){
        if(check(a,b))return true;
        rotate(b);
    }
    for(int i = 0; i < (int)b.size();i++){
        b[i].first -= b.back().first;
        b[i].second -= b.back().second;
    }
    rep(i,4){
        if(check(a,b))return true;
        rotate(b);
    }
    return false;
}
int N,m,x,y,a,b;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    while(1){
        cin>>N;
        if(N == 0){
            //cout<<"+++++"<<endl;
            break;
        }
        vvp oresen(N+1);
        for(int i = 0;i <= N;i++){
            cin>>m;
            cin>>a>>b;
            oresen[i].push_back({0,0});
            for(int j = 1;j < m;j++){
                cin>>x>>y;
                x -= a;
                y -= b;
                oresen[i].push_back({x,y});
            }
        }
        for(int i = 1;i <= N;i++){
            if(issame(oresen[0],oresen[i])){
                cout<<i<<endl;
            }
        }
        cout<<"+++++"<<endl;
    }
}