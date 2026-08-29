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

bool findLoop(int cur, vector<int>& vis, vector<int>& pre, vector<vector<int> >& G) {
    if(vis[cur] == 1) {
        return false;
    }
    if(vis[cur] == 0) {
        // loop at cur
        int temp = pre[cur];
        vector<int> path = {cur};
        
        while(temp != cur) {
            path.pb(temp);
            temp = pre[temp];
        }

        path.pb(temp);
        cout << path.size() << "\n";
        for(int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << "\n";
        return true;
    }

    vis[cur] = 0;
    for(int x : G[cur]) {
        pre[x] = cur;
        if(findLoop(x, vis, pre, G)) {
            return true;
        }
    }
    vis[cur] = 1;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
    }

    vector<int> vis(n + 1, -1);
    vector<int> pre(n + 1, -1);

    for(int i = 1; i <= n; i++) {
        if(vis[i] == -1) {
            if(findLoop(i, vis, pre, G)) {
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    // -1 -> not visited
    // 0 -> visiting
    // 1 -> visited




    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

