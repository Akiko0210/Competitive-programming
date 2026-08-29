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

struct Trojan {
    int n;
    vector<vector<int> > G;
    vector<int> low, id;
    vector<bool> instack;
    vector<vector<int> > components;
    stack<int> s;

    Trojan(int n, vector<vector<int> >& G) {
        this->n = n;
        this->G = G;
        id.resize(n + 1, -1);
        low.resize(n + 1);
        instack.resize(n + 1, false);
    }

    void findComponents() {
        int counter = 1;
        for(int i = 1; i <= n; i++) {
            dfs(i, counter);
        }
    }

    void dfs(int cur, int& counter) {
        if(id[cur] != -1) {
            return;
        }

        id[cur] = low[cur] = counter++;
        instack[cur] = true;
        s.push(cur);

        for(int x : G[cur]) {
            dfs(x, counter);
            if(instack[x]) {
                low[cur] = min(low[cur], low[x]);
            }
        }

        if(low[cur] == id[cur]) {
            vector<int> component;
            while(s.top() != cur) {
                // cout << s.top() << " ";
                low[s.top()] = low[cur];
                instack[s.top()] = false;
                component.pb(s.top());
                s.pop();
            }
            // cout << cur << "\n";
            component.pb(cur);
            components.pb(component);
            instack[cur] = false;
            s.pop();
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
    }

    Trojan scc(n, G);
    scc.findComponents();
    vector<int> ans(n + 1);
    for(int i = 0; i < scc.components.size(); i++) {
        for(int x : scc.components[i]) {
            ans[x] = i + 1;
        }
    }
    cout << scc.components.size() << "\n";
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

