#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin>>N;
    vector<vector<int>> a(N, vector<int>(N-1, 0));
    rep(i,N) {
        rep(j,N-1){
        cin>>a[i][j];
        a[i][j]--;
        }
        reverse(all(a[i]));
    }
    vector<pair<int,int>> q;
    auto check = [&](int i){
        if(a[i].size() == 0)return;
        int j = a[i].back();
        if(a[j].size() == 0)return;
        if(a[j].back() == i){
            if(i < j)swap(i,j);
            q.push_back({i,j});
        }
    };
    rep(i,N){
        check(i);
    }
    int day = 0;
    while(!q.empty()){
        day++;
        
        sort(all(q));
        q.erase(unique(q.begin(),q.end()), q.end());
        vector<pair<int,int>> prevQ;
        swap(prevQ,q);
        for(auto p : prevQ){
            int i = p.first;
            int j = p.second;
            a[i].pop_back();
            a[j].pop_back();
        }
        for(auto p : prevQ){
            int i = p.first;
            int j = p.second;
            check(i);
            check(j);
        }
    }
    rep(i,N){
        if(a[i].size() != 0){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<day<<endl;
    return 0;
}