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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > G(n);
    vector<set<int> > blocks(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<int> ans(n, 0);
    vector<bool> inque(n, false);
    
    auto bfs = [&](int start) {
        priority_queue<pii> q;
        q.push({G[start].size(), start});
        inque[start] = true;
        while(!q.empty()) {
            pii cur = q.top();
            int i = cur.ss;
            q.pop();
            int j = 1;
            while(blocks[i].find(j) != blocks[i].end())
                j++;
            ans[i] = j;
            for(int x : G[i]) {
                blocks[x].insert(ans[i]);
                if(!inque[x]) {
                    q.push({G[x].size(), x});
                    inque[x] = true;
                }
            }
        }
    };

    vector<int> inds(n);
    iota(inds.begin(), inds.end(), 0);
    sort(inds.begin(), inds.end(), [&](int i, int j) {
        return G[i].size() > G[j].size();
    });

    for(int i = 0; i < n; i++) {
        if(!inque[inds[i]]) bfs(inds[i]);
    }


    for(int x : ans) {
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

