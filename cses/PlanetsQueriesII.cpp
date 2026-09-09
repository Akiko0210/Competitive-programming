#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
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
const int N = 2e5 + 1;
vector<int> p, vis, inloopid, componentid, level, loopsize;
vector<vector<int> > G, par;


void discoverLoop(int cur, int component) {
    int temp = p[cur], id = 0;
    inloopid[cur] = id++;
    componentid[cur] = component;
    while(temp != cur) {
        componentid[temp] = component;
        inloopid[temp] = id++;
        temp = p[temp];
    }
    loopsize[component] = id;
    // debug(cur, loopsize[component]);
}

void dfs(int cur, int& component) {
    if(vis[cur] == 1) {
        // already visited node.
        return;
    }
    if(vis[cur] == 0) {
        discoverLoop(cur, component);
        component++;
        return; // found loop here
    }

    vis[cur] = 0;
    dfs(p[cur], component);
    componentid[cur] = componentid[p[cur]];
    vis[cur] = 1;
}

void dfs1(int cur, vector<vector<int> >& G) {
    for(int x : G[cur]) {
        if(inloopid[x] == -1) {
            level[x] = level[cur] + 1;
            par[0][x] = cur;
            dfs1(x, G);
        }
    }
}

int inloopdis(int a, int b) {
    int size = loopsize[componentid[a]];
    return (inloopid[b] + size - inloopid[a]) % size;
}

int main() {
    FAST
    int n, q;
    cin >> n >> q;
    p.resize(N);
    vis.assign(N, -1);
    inloopid.assign(N, -1);
    componentid.assign(N, -1);
    level.assign(N, 0);
    loopsize.assign(N, -1);
    G.resize(N);
    par.resize(20, vector<int> (N));


    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        G[p[i]].pb(i);
    }
    int component = 1;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 1) continue;
        dfs(i, component);
    }

    for(int j = 0; j < 20; j++) {
        for(int i = 1; i <= n; i++) {
            if(inloopid[i] != -1) {
                par[j][i] = i;
            }
        }
    }

    // discovered all the in loop nodes. 
    // dfs out in the reversed graph. 

    for(int i = 1; i <= n; i++) {
        if(inloopid[i] != -1)
            dfs1(i, G);
    }

    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        // they're not in a same component;
        // debug(componentid[a], componentid[b]);
        if(componentid[a] != componentid[b]) {
            cout << "-1\n";
            continue;
        }

        // they're in a same component;

        // if either one is in loop, it's guarenteed they can meet.
        if(inloopid[a] != -1 && inloopid[b] != -1) {
            cout << inloopdis(a, b) << "\n";
            continue;
        }        

        // both not in loop
        if(inloopid[a] == -1 && inloopid[b] == -1) {
            // a can't walk backward
            if(level[a] < level[b]) {
                cout << "-1\n";
                continue;
            }
            
            // walk a till their level match
            int dif = level[a] - level[b];
            for(int i = 19; i >= 0; i--) {
                if(dif & (1 << i)) {
                    a = par[i][a];
                }
            }

            if(a == b) {
                cout << dif << "\n";
                continue;
            }
            cout << "-1\n";
            continue;
        }
        // if a is in the loop and b is not in the loop, a can't reach b
        if(inloopid[a] != -1) {
            cout << "-1\n";
            continue;
        }

        cout << level[a] + inloopdis(par[19][a], b) << "\n";
        // continue;
    }



    return 0;
}
