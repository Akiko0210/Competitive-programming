// Strongly Connected Components.

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

struct SCC {
    int n, components;
    vector<int> lowlink, id;
    vector<bool> instack;
    vector<vector<int> > G;
    stack<int> s;
    SCC(int n, vector<vector<int> >& G) {
        this->n = n;
        this->G = G;
        components = 0;
        lowlink.resize(n);
        id.resize(n, -1);
        instack.resize(n, false);
    }

    void findComponents() {
        int counter = 0;
        for(int i = 0; i < n; i++) {
            dfs(i, counter);
        }
    }

    void dfs(int cur, int &counter) {
        if(id[cur] != -1) {
            return;
        }

        id[cur] = lowlink[cur] = counter++;
        instack[cur] = true;
        s.push(cur);

        for(int x : G[cur]) {
            dfs(x, counter);
            if(instack[x]) {
                lowlink[cur] = min(lowlink[cur], lowlink[x]);
            }
        }

        if(lowlink[cur] == id[cur]) {
            while(!s.empty() && s.top() != cur) {
                // cout << s.top() << " ";
                instack[s.top()] = false;
                lowlink[s.top()] = lowlink[cur];
                s.pop();
            }
            // cout << cur << "\n";
            s.pop();
            instack[cur] = false;
            components++;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
    }

    SCC scc(n, G);
    scc.findComponents();
    if(scc.components == 1) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";

    vector<bool> vis(n, false);
    stack<int> s;
    s.push(0);
    vis[0] = true;
    while(!s.empty()) {
        int cur = s.top();
        s.pop();

        for(int x : G[cur]) {
            if(!vis[x]) {
                vis[x] = true;
                s.push(x);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cout << 1 << " " << i + 1 << "\n";
            return 0;
        }

        if(scc.lowlink[i] != scc.lowlink[0]) {
            cout << i + 1 << " " << 1 << "\n";
            return 0;
        }
    }

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

