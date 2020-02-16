#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

const int N = 50;
const int M = 500;

vec<char> D = {'U','R','D','L'};
vec<int> dx = {-1,0,1,0},dy = {0,1,0,-1};
unordered_map<char,int> mp;



int id(char c){
   return mp[c];
}

bool chmax(int &a,int b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

bool in(int x,int y){
    return 0<=x && x<N && 0<=y && y<N; 
}


struct OP{
    int r,c;
    char d;
};

struct P{
    int x,y;
    bool operator<(const P &r)const{
        return (x!=r.x? x<r.x:y<r.y);
    }
};

int dist(P a,P b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}

struct state{
    vvec<int> A;
    vvec<int> B;
    int score;
    vec<OP> ans;
    int ti;
    vec<set<P>> num_ps;
    vvec<int> num;
    vec<set<int>> nums;
    vec<int> ne_num;
    vec<P> ne_p;
    bool ok;

    state(vvec<int> A,vvec<int> B,vvec<int> num,vec<set<P>> s,vec<set<int>> n):A(A),B(B),num(num),num_ps(s),nums(n),ti(0){
        ok = false;
        ans = vec<OP>();
        if(nums[0].count(num[0][0])) nums[0].erase(num[0][0]);
        if(nums[1].count(num[0][N-1])) nums[1].erase(num[0][N-1]);
        if(nums[2].count(num[N-1][0])) nums[2].erase(num[N-1][0]);
        if(nums[3].count(num[N-1][N-1])) nums[3].erase(num[N-1][N-1]);
        ne_num = vec<int>(4,-1);
        ne_p = {{0,0},{0,N-1},{N-1,0},{N-1,N-1}};
        for(int k=0;k<4;k++){
            search_next_goal(k);
        }
    }

    bool operator<(const state& r)const{
        return score>r.score;
    }

    void search_next_goal(int k){
        if(!nums[k].empty()){
            P best = {-1,-1};
            for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(nums[k].count(num[i][j])){
                if(best.x==-1 || dist(ne_p[k],{i,j})<dist(ne_p[k],best)){
                    best = {i,j};
                } 
            }
            ne_p[k] = best;
        }else ne_p[k] = {-1,-1};
    }

    OP to_goal(int col){
        P best = {-1,-1};
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(B[i][j]==col){
            if(best.x==-1 || dist(ne_p[col],{i,j})<dist(ne_p[col],best)){
                best = {i,j};
            }
        }
        OP res = {};
        int b_dist = 1e9;
        auto best_search = [&](int x,int y){
            int sx = x,sy = y;
            int d = 1e9;
            for(int i=0;i<4;i++){
                int d2 = 1e9;
                x = sx,y = sy;
                for(int k=0;k<5;k++){
                    x += dx[i],y += dy[i];
                    if(!in(x,y)) continue;
                    if(d2>dist(ne_p[col],{x,y})){
                        d2 = dist(ne_p[col],{x,y});
                    }
                }
                if(d2<d){
                    res = {sx,sy,D[i]};
                    d = d2;
                }
            }
            b_dist = d;
        };
        best_search(best.x,best.y);
        update(res);
        if(b_dist==0){
            nums[col].erase(num[ne_p[col].x][ne_p[col].y]);
            search_next_goal(col);
        }
    }

    void decide_col(int col){
        if(!ok){
            bool is_ok = true;
            for(int k=0;k<4;k++) is_ok &= ne_p[k].x==-1;
            ok |= is_ok;
        }
        if(ne_p[col].x!=-1) to_goal(col);
        else{
            OP res = search(col);
            update(res);
        }
    }

    int calc_gain(int col,int x,int y,char d){
        int g = 0;
        for(int k=0;k<5;k++){
            x += dx[id(d)],y += dy[id(d)];
            if(!in(x,y)) break;
            g += gain(B[x][y],col,A[x][y]);
        }
        return g;
    }

    OP search(int col){
        OP best;
        int bg = 0;
        for(int x=0;x<N;x++) for(int y=0;y<N;y++) if(B[x][y]==col){
            for(int k=0;k<4;k++){
                int g = calc_gain(col,x,y,D[k]);
                if(chmax(bg,g)){
                    best = {x,y,D[k]};
                }
            }
        }
        if(bg==0) return (OP){-1,-1,'B'};
        return best;
    }

    void update(OP res){
        if(res.r==-1){
            ti++;
            ans.push_back(res);
            return ;
        }
        score += paint(ti%4,res.r,res.c,res.d);
        ans.push_back(res);
        ti++;
    };

    int gain(int now,int ne,int goal){
        if(now==-1) return (ne==goal? 1:0);
//        if(!ok) return -1e5;
        if(now==goal) return (ne==goal? 0:-1);
        return (ne==goal? 1:0);
    }

    int paint(int col,int x,int y,char d){
        assert(col==B[x][y]);
        int g = 0;
        for(int k=0;k<5;k++){
            x += dx[id(d)],y += dy[id(d)];
            if(!in(x,y)) break;
            B[x][y] = col;
            g += gain(B[x][y],col,A[x][y]);
        }
//        if(ti==0) for(int i=0;i<N;i++) for(int j=0;j<N;j++) cerr << B[i][j] << (j!=N-1? " ":"\n");
        return g;
    }

    void run(){
        for(int t=0;t<M;t++) decide_col(t%4);
    }

    void print(){
        assert(ans.size()==M);
        for(auto x:ans){
            if(x.r==-1) cout << -1 << "\n";
            else cout << x.r << " " << x.c << " " << x.d << "\n";
        }
    }

};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    mp['U'] = 0;
    mp['R'] = 1;
    mp['D'] = 2;
    mp['L'] = 3;
    int n,m;
    cin >> n >> m;
    vvec<int> A(N,vec<int>(N,0));
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> A[i][j];
    vvec<int> num(N,vec<int>(N,-1));

    auto bfs = [&](int id,int sx,int sy,int col,set<P> s,int &cnt){
        queue<P> Q;
        Q.push({sx,sy});
        num[sx][sy] = id;
        s.insert({sx,sy});
        while(!Q.empty()){
            cnt++;
            P p = Q.front(); Q.pop();
            for(int k=0;k<4;k++){
                int nx = p.x+dx[k],ny = p.y+dy[k];
                if(!in(nx,ny)) continue;
                if(A[nx][ny]!=col) continue;
                if(num[nx][ny]==-1){
                    num[nx][ny] = id;
                    Q.push({nx,ny});
                    s.insert({nx,ny});
                }
            }
        }
    };

    vec<set<P>> num_ps;
    vec<set<int>> nums(4);
    int c = 0;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(num[i][j]==-1){
        set<P> s;
        int cnt = 0;
        bfs(c,i,j,A[i][j],s,cnt);
        if(cnt<=20) continue;
        nums[A[i][j]].insert(c);
        num_ps.push_back(s);
        c++;
    }
    assert(c==num_ps.size());
    vec<OP> ans(M);
    vvec<int> now(N,vec<int>(N,-1));
    now[0][0] = 0,now[0][N-1] = 1,now[N-1][0] = 2,now[N-1][N-1] = 3;
    state init(A,now,num,num_ps,nums);
    init.run();
    init.print();
}
