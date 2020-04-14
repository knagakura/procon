#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


const int N = 1000, W = 8, K = 6, V = 8;
struct state{
    int num;
    int score[6];
    ll hash;
    state():num(0),hash(0){
        rep(i,6)score[i]=0;
    }
    state(ll hash):hash(hash){
        rep(i,6){
            score[i]=hash&63;
            hash>>=6;
        }
        num = hash;
    }
    int add(int color, int value){
        score[color] += value;
        hash += value * 1ll<<(6*color);
        hash += 1ll<<36;
        ++num;
        return *max_element(score,score+6);
    }
    void erase(int color, int value){
        score[color] -= value;
        hash -= value * 1ll<<(6*color);
        hash -= 1ll<<36;
        --num;
    }

};
struct Status{
    ll hash[8];
    Status(){
        rep(i,8)hash[i]=0;
    }
    Status(ll v1,ll v2,ll v3,ll v4,ll v5,ll v6,ll v7,ll v8){
        hash[0]=v1;
        hash[1]=v2;
        hash[2]=v3;
        hash[3]=v4;
        hash[4]=v5;
        hash[5]=v6;
        hash[6]=v7;
        hash[7]=v8;
    }
    const bool operator==(const Status rhs)const{
        rep(i,8)if(hash[i]!=rhs.hash[i])return false;
        return true;
    }
    const bool operator<(const Status rhs)const{
        rep(i,8){
            if(hash[i]<rhs.hash[i])return true;
            if(hash[i]>rhs.hash[i])return false;
        }
        return false;
    }
};

int main(){
    int _ ;
    cin>>_>>_>>_>>_;

    priority_queue<pair<ll,Status>> pq;
    pq.push({0,{0,0,0,0,0,0,0,0}});
    map<Status, Status> pre[N];
    map<Status,int> score[N];
    rep(turn,N){
        int new_color, new_value;
        cin>>new_color>>new_value;
        priority_queue<pair<ll,Status>> npq;
        int max_count = 350;
        set<Status> st;
        while(!pq.empty() && max_count){
            int cur = pq.top().first;
            Status status = pq.top().second;
            pq.pop();
            if(st.count(status))continue;
            st.insert(status);
            state s[8];
            rep(i,8)s[i]=state(status.hash[i]);
            cur -= *max_element(s[0].score,s[0].score+6);
            int ns = s[0].add(new_color, new_value);
          	Status new_status;
            if(s[0].num>=8){
                new_status = Status(s[1].hash, s[2].hash, s[3].hash, s[4].hash, s[5].hash, s[6].hash, s[7].hash, 0);
                if(score[turn][new_status]<cur+ns){
                    score[turn][new_status]=cur+ns;
                    pre[turn][new_status] = status;
                    npq.push({cur+ns, new_status});
                }
            }
            else {
                if(turn>990)ns=0;
                new_status = Status(s[0].hash,s[1].hash, s[2].hash, s[3].hash, s[4].hash, s[5].hash, s[6].hash, s[7].hash);
                if(score[turn][new_status]<cur+ns){
                    score[turn][new_status]=cur+ns;
                    pre[turn][new_status] = status;
                    npq.push({cur+ns, new_status});
                }
            }
            s[0].erase(new_color, new_value);
            cur += *max_element(s[0].score,s[0].score+6);
          	new_status = Status(s[0].hash,s[1].hash, s[2].hash, s[3].hash, s[4].hash, s[5].hash, s[6].hash, s[7].hash);
            rep(i,7){
                if(s[i].num <= s[i+1].num)continue;
                cur -= *max_element(s[i+1].score,s[i+1].score+6);
                int ns = s[i+1].add(new_color, new_value);
                if(turn>990)ns=0;
                new_status.hash[i+1]=s[i+1].hash;
                if(score[turn][new_status]<cur+ns){
                    score[turn][new_status]=cur+ns;
                    pre[turn][new_status] = status;
                    npq.push({cur+ns, new_status});
                }
                s[i+1].erase(new_color, new_value);
              	new_status.hash[i+1]=s[i+1].hash;
                cur += *max_element(s[i+1].score,s[i+1].score+6);
            }
            
            --max_count;
        }
        npq.swap(pq);
    }
    Status status = pq.top().second;
    vector<int> ans;
    for(int turn =N-1;turn>=0;--turn){
        Status pre_status = pre[turn][status];
        state s[8];
        rep(i,8)s[i]=state(status.hash[i]);

        state p[8];
        rep(i,8)p[i]=state(pre_status.hash[i]);

        int sum = s[0].num + s[1].num + s[2].num + s[3].num+s[4].num+s[5].num+s[6].num+s[7].num;
        int pre_sum = p[0].num + p[1].num + p[2].num + p[3].num+p[4].num+p[5].num+p[6].num+p[7].num;
        if(pre_sum + 1 == sum){
            rep(i,8){
                if(p[i].num + 1 == s[i].num)ans.push_back(p[i].num);
            }
        }
        else {
            ans.push_back(7);
        }
        status = pre_status;
    }
    reverse(ans.begin(),ans.end());
    vector<int> cnt(8);
    rep(i,N){
        if(cnt[ans[i]]==125){
            ans[i]=7;
            while(cnt[ans[i]]==125)--ans[i];
        }
        cout<<ans[i]<<endl;
        ++cnt[ans[i]];
    }
    return 0;
}

