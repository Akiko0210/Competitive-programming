// Eulerian tour.

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
    vector<int> indegree(n + 1, 0), outdegree(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        indegree[b]++;
        outdegree[a]++;
    }

    if((indegree[1] != outdegree[1] - 1) || 
    (indegree[n] - 1 != outdegree[n])) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(int i = 2; i < n; i++) {
        if(indegree[i] != outdegree[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<int> tour;
    function<void(int)> dfs = [&](int cur) {
        while(!G[cur].empty()) {
            int nxt = G[cur].back();
            G[cur].pop_back();
            dfs(nxt);
        }

        tour.pb(cur);
    };

    dfs(1);

    if(tour.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    // if(tour[0] != n || tour.size() != m + 1) {
    //     cout << "IMPOSSIBLE\n";
    //     return 0;
    // }

    for(int i = tour.size() - 1; i >= 0; i--) {
        cout << tour[i] << " ";
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

