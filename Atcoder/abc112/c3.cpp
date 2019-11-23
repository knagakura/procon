#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
    int N,x0,y0,h0;
    cin>>N;
    vector<int> x(N),y(N),h(N);
    rep(i,N){
        cin>>x[i]>>y[i]>>h[i];
        if(h[i] > 0){
            x0 = x[i];
            y0 = y[i];
            h0 = h[i];
        }
    }
    rep(Cx,101)rep(Cy,101){
        int H0 = h0 + abs(x0 - Cx) + abs(y0 - Cy);
        bool f = true;
        rep(i,N){
            if(H0-abs(x[i]-Cx)-abs(y[i]-Cy) < 0){
                if(h[i] !=0){
                    f = false;
                }
            }
            else if(H0 != h[i] + abs(x[i]-Cx) + abs(y[i]-Cy)){
                f = false;
            }
        }
        if(f){
            cout<<Cx<<" "<<Cy<<" "<<H0<<endl;
            return 0;
        }
    }
}
