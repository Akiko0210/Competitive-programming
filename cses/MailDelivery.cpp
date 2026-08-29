// Eulerian tour

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

ll H(pii x) {
    ll mult = 1e9;
    return mult * x.ff + x.ss;
}

int main() {
    FAST
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int> > G(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }

    for(int i = 1; i <= n; i++) {
        if(G[i].size() % 2 == 1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // just dfs
    vector<int> path;

    stack<int> s;
    s.push(1);

    while(!s.empty()) {
        int cur = s.top();
        if(G[cur].empty()) {
            path.pb(cur);
            s.pop();
            continue;
        }
        int nxt = *G[cur].begin();
        G[cur].erase(nxt);
        G[nxt].erase(cur);
        s.push(nxt);
    }

    if(path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }


    for(int x : path) {
        cout << x << " ";
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

