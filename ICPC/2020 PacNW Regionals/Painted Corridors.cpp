#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define tii tuple<int, int, int>
#define INF INT_MAX
using namespace std;
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef AKIKO_DEBUG
#define debug(...) cerr << "\033[1;31m(" << #__VA_ARGS__ << "):\033[0m", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1e9 + 7;

int n, m;

int to_hash(array<int, 3> pos) {
    return pos[0] * n * n + pos[1] * n + pos[2];
}

array<int, 3> to_pos(int h) {
    int a = h / (n * n);
    h %= n * n;
    int b = h / n;
    h %= n;
    int c = h; 
    return {a, b, c};
}

int main() {
    FAST
    cin >> n >> m;
    array<int, 3> initPos;
    for(int i = 0; i < 3; i++) {
        cin >> initPos[i];
        initPos[i]--;
    }

    string colors = "XRBPYOG";
    vector<vector<tii> > G(n + 1);
    string edgeColors = "";
    for(int i = 0; i < m; i++) {
        int a, b;
        char C;
        cin >> a >> b >> C;
        a--, b--;
        edgeColors += C;
        int w = colors.find(C);
        G[a].pb({b, w, i});
        G[b].pb({a, w, i});
    }

    vector<bool> visit(n * n * n, 0);
    vector<bool> edgeVisited(m, false);
    queue<int> q;
    q.push(to_hash(initPos));
    visit[to_hash(initPos)] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        array<int, 3> pos = to_pos(cur);
        unordered_map<int, int> pos_map; 
        for(int i = 0; i < 3; i++) {
            pos_map[pos[i]] |= (1 << i);
        }
        
        for(auto &[ind, candidates] : pos_map) {
            for(auto &[nxt, w, edge_ind] : G[ind]) {
                // first handle the edges that we can't pass
                // if w is not subset of candidates
                if((candidates & w) != w) {
                    // can't go this way.
                    continue;
                }
                
                edgeVisited[edge_ind] = true;
                array<int, 3> nxt_pos = pos;
                if(w == 0) {
                    // everyone can pass over this edge
                    // try letting them walk 1 by 1.
                    for(int i = 0; i < 3; i++) {
                        if(candidates & (1 << i)) {
                            int temp = nxt_pos[i];
                            nxt_pos[i] = nxt;
                            if(!visit[to_hash(nxt_pos)]) {
                                visit[to_hash(nxt_pos)] = true;
                                q.push(to_hash(nxt_pos));
                            }
                            nxt_pos[i] = temp;
                        }
                    }
                    continue;
                }

                for(int i = 0; i < 3; i++) {
                    if(w & (1 << i)) {
                        nxt_pos[i] = nxt;
                    }
                }
                if(!visit[to_hash(nxt_pos)]) {
                    visit[to_hash(nxt_pos)] = true;
                    q.push(to_hash(nxt_pos));
                }
            }
        }
    }

    for(int i = 0; i < m; i++) {
        if(edgeColors[i] != 'X' && !edgeVisited[i]) {
            cout << "0\n";
            return 0;
        }
    }
    cout << "1\n";




    return 0;
}