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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<bool> vis(n + 1, false);
    vector<int> prev(n + 1);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()) {
        int cur = q.front();
        if(cur == n) break;
        q.pop();
        for(int x : G[cur]) {
            if(vis[x]) continue;
            
            vis[x] = true;
            prev[x] = cur;
            q.push(x);
        }
    }

    if(!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    stack<int> path;
    int cur = n;
    while(cur != 1) {
        path.push(cur);
        cur = prev[cur];
    }
    path.push(1);
    cout << path.size() << "\n";
    while(!path.empty()) {
        cout << path.top() << " ";
        path.pop();
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

