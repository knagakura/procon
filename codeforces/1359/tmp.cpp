#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

double calc(lli x,lli y,lli a){
    return (x*a+y*(a-1))/(double)(2*a-1);
}

void solve(){

    lli x,y,t;
    cin>>x>>y>>t;

    if(x<=t){
        cout<<1<<endl;
        return;
    }

    lli ave = (x+y)/2;
    if(ave >= t){
        cout<<2<<endl;
        return;
    }

    lli small = 1,large = 1e9;

    while(small+1<large){
        lli a = (small+large)/2;
        double nowT = calc(x,y,a);
        LOG4(small,a,large,nowT);
        if(nowT < t){
            large = a;
        }
        else{
            small = a;
        }
    }

    double smallT = calc(x,y,small);
    double largeT = calc(x,y,large);
    if(abs(ave-t)<=abs(smallT-t) && abs(ave-t) <= abs(largeT-t)){
        cout<<2<<endl;
        return;
    }

    if(abs(smallT-t)>abs(largeT-t)){
        cout<<2*large-1<<endl;
    }
    else{
        cout<<2*small-1<<endl;
    }

}


int main(){

    lli t;
    cin>>t;
    while(t--)solve();

    return 0;
}