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

vector<vector<int> > cap;
vector<vector<int> > G;
int n, m;

int get_flow() {
    // find a risidual path.
    // from 1 to n
    vector<int> pre(n + 1, -1);
    pre[1] = 0;

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == n) break;

        for(int x : G[cur]) {
            if(pre[x] != -1 || cap[cur][x] <= 0) continue;

            pre[x] = cur;
            q.push(x);
        }
    }

    if(pre[n] == -1) {
        // no path found
        return 0;
    }
    
    int cur = n;
    while(cur != 1) {
        // cout << cur << " ";
        cap[pre[cur]][cur] -= 1;
        cap[cur][pre[cur]] += 1;
        cur = pre[cur];
    }
    // cout << "1\n";
    return 1;
}

int maxflow() {
    int flow = get_flow(), ans = 0;
    while(flow) {
        // debug(flow);
        ans += flow;
        flow = get_flow();
    }
    return ans;
}

int main() {
    cin >> n >> m;
    cap.assign(n + 1, vector<int> (n + 1, 0));
    G.resize(n + 1);
    vector<vector<int> > OG(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cap[a][b] = 1;
        G[a].pb(b);
        OG[a].pb(b);
        G[b].pb(a);
    }

    int flow = maxflow();
    cout << flow << "\n";
    // find the actual paths using what's given.
    while(flow--) {
        // find path
        // 
        vector<int> pre(n + 1, -1);
        pre[1] = 0;

        queue<int> q;
        q.push(1);

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            if(cur == n) break;

            for(int x : OG[cur]) {
                if(pre[x] != -1 || cap[cur][x] != 0) continue;

                pre[x] = cur;
                q.push(x);
            }
        }

        int cur = n;
        vector<int> vis;
        while(cur != 1) {
            vis.pb(cur);
            cap[pre[cur]][cur] = 1;
            cur = pre[cur];
        }
        vis.pb(1);
        reverse(vis.begin(), vis.end());
        cout << vis.size() << "\n";
        for(int x : vis) {
            cout << x << " ";
        }
        cout << "\n";
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

