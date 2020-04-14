#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


struct PalindromicTree {
    //
    // private:
    struct node {
        map<char, int> link;
        int suffix_link;
        int len;
        int count;
    };

    vector<node> c;
    string s;
    int active_idx;

    node* create_node() {
        c.emplace_back();
        node* ret = &c.back();
        ret->count = 0;
        return ret;
    }

    // this->s の状態に依存する
    int find_prev_palindrome_idx(int node_id) {
        const int pos = int(s.size()) - 1;
        while (true) {
            const int opposite_side_idx = pos - 1 - c[node_id].len;
            if (opposite_side_idx >= 0 && s[opposite_side_idx] == s.back()) break;
            node_id = c[node_id].suffix_link; // 次の回文に移動
        }
        return node_id;
    }

    bool debug_id2string_dfs(int v, int id, vector<char>& charas) {
        if (v == id) return true;
        for (auto kv : c[v].link) {
            if (debug_id2string_dfs(kv.second, id, charas)) {
                charas.push_back(kv.first);
                return true;
            }
        }
        return false;
    }

public:
    PalindromicTree() {
        node* size_m1 = create_node(); // 長さ-1のノードを作成
        size_m1->suffix_link = 0; // -1 の親suffixは自分自身
        size_m1->len = -1;
        node* size_0 = create_node(); // 長さ0のノードを作成
        size_0->suffix_link = 0; // 親は長さ-1のノード
        size_0->len = 0;

        active_idx = 0;
    }

    int get_active_idx() const {
        return active_idx;
    }
    node* get_node(int id) {
        return &c[id];
    }

    void add(char ch) {
        s.push_back(ch);

        // ch + [A] + ch が回文となるものを探す
        const int a = find_prev_palindrome_idx(active_idx);

        //新しいノードへのリンクが発生するか試す
        const auto inserted_result = c[a].link.insert(make_pair(ch, int(c.size())));
        active_idx = inserted_result.first->second; // insertの成否に関わらず、iteratorが指す先は新しい回文のindex
        if (!inserted_result.second) {
            c[active_idx].count++; // その回文が現れた回数が増加
            return; // 既にリンクが存在したので、新しいノードを作る必要がない
        }

        // 実際に新しいノードを作成
        node* nnode = create_node();
        nnode->count = 1;
        nnode->len = c[a].len + 2; // ch + [A] + ch だから、長さは len(A) + 2

                                   // suffix_linkの設定
        if (nnode->len == 1) {
            // この時だけsuffix_linkはsize 0に伸ばす
            nnode->suffix_link = 1;
        } else {
            // ch + [B] + ch が回文になるものを探す。ただし長さはaより小さいもの
            const int b = find_prev_palindrome_idx(c[a].suffix_link);
            nnode->suffix_link = c[b].link[ch];
        }
    }

    //各文字列が何回現れるか計算する
    // O(n)
    vector<int> build_frequency() {
        vector<int> frequency(c.size());
        //常に親ノードのid < 子ノードのidが成り立つので、idを大きい順から回せばよい
        for (int i = int(c.size()) - 1; i > 0; i--) {
            frequency[i] += c[i].count;
            frequency[c[i].suffix_link] += frequency[i];
        }
        return frequency;
    }

    // debug用
    // idがどのような回文を表しているのかを返す
    // O(n)
    string debug_id2string(int id) {
        if (id == 0) {
            return "(-1)";
        } else if (id == 1) {
            return "(0)";
        }

        vector<char> charas;
        debug_id2string_dfs(0, id, charas);
        debug_id2string_dfs(1, id, charas);

        string ret(charas.begin(),charas.end());
        int start = int(charas.size()) - 1;
        if (c[id].len % 2 == 1) start--;
        for (int i = start; i >= 0; i--) ret.push_back(charas[i]);

        return ret;
    }

    void display_frequencies() {
        auto freq = build_frequency();
        printf("frequencies of each palindrome...\n");
        for (int i = 0; i < int(c.size()); i++) {
            const string palindrome = debug_id2string(i);
            printf("  %s : %d\n", palindrome.c_str(), freq[i]);
        }
    }
    map<string, int> construct(){
        auto freq = build_frequency();
        map<string, int> res;
        for (int i = 0; i < int(c.size()); i++) {
            const string palindrome = debug_id2string(i);
            res[palindrome.c_str()] += freq[i];
        }
        return res;
    }
};


bool dp[5005][5005];
void debug(int n){
    rep(i,n){
        rep(j,n){
            cerr << dp[i][j] <<" ";
        }
        cerr << endl;
    }
    cerr << endl;
}
void solve(){
    string s;
    cin >> s;
    int N = s.size();
    //
    if(N == 1){
        cout << s << endl;
        return;
    }
    //
    PalindromicTree pt;
    for (auto c : s) {
        pt.add(c); // 1文字ずつ登録していく
    }
    auto mp1 = pt.construct();
    if(mp1[s] > 0){
        cout << s << endl;
        return;
    }
    //pt.display_frequencies();
    string ls = "";
    int l = 0;
    int r = N-1;
    rep(i,N){
        l = i;
        r = N - 1 - i;
        if(l > r)break;
        if(s[l] == s[r])ls.push_back(s[i]);
        else break;
    }

    string la = "";
    string lans = "";
    for(int i = l; i <= r;i++){
        la.push_back(s[i]);
        if(mp1[la] > 0){
            if(lans.size() < la.size()){
                lans = la;
            }
        }
    }

    string ra = "";
    string rans = "";
    for(int i = r; i >= l;i--){
        ra.push_back(s[i]);
        if(mp1[ra] > 0){
            if(rans.size() < ra.size()){
                rans = ra;
            }
        }
    }

    string midans = rans;
    if(rans.size() < lans.size())midans = lans;
    string ans = "";
    dump(ls);dump(midans);
    ans += ls;
    ans += midans;
    reverse(all(ls));
    ans += ls;
    cout << ans << endl;
    //printf("%s \n", ans.c_str());
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int Q;
    cin >> Q;
    while(Q--){
        solve();
    }
}