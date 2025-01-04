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
vector<int> prices(1e5 + 1);

int pivot = 0;
bool dfs(int cur, vector<bool>& vis, vector<bool>& curvis, vector<bool>& inloop, vector<vector<int> >& G, vector<int>& nums) {
    // debug(cur);
    if(curvis[cur]) {
        // in current iteration, visited twice.
        // debug(cur);
        pivot = cur;
        return 1;
    }

    if(vis[cur]) {
        // debug("here?");
        // leads to another cycle. Means no loop.
        return 0;
    }
    vis[cur] = 1;
    curvis[cur] = 1;

    for(int x : G[cur]) {
        // debug(x);
        bool pos = dfs(x, vis, curvis, inloop, G, nums);
        // debug(cur, x, pos, pivot);
        if(pivot > 0) {
            inloop[cur] = inloop[cur] | pos;
        }
    }


    if(inloop[cur]) {
        nums.pb(cur);
    }
    // debug(cur, pivot, inloop[cur], inloop[pivot]);
    if(cur == pivot) {
        pivot = -1;
    }
    curvis[cur] = 0;
    return inloop[cur];
}

int main() {
    /*
        number of DSU, mult of num of min in DSU
    */

    int n, m;
    cin >> n;
    vector<vector<int> > G(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> prices[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
    }

    vector<bool> vis(n + 1, 0), inloop(n + 1, 0), curvis(n + 1, 0);
    vector<int> nums, temp;
    ll ans = 1, val = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            int mnprice = INF, cnt = 0;
            dfs(i, vis, curvis, inloop, G, nums);

            if(nums.empty()) {
                continue;
            }

            for(int x : nums) {
                debug(x);
                if(prices[x] < mnprice) {
                    mnprice = prices[x];
                    cnt = 0;
                }

                if(prices[x] == mnprice) {
                    cnt++;
                }
            }

            nums = temp;
            val += mnprice;
            (ans *= cnt) %= MOD;
        }
    }
    cout << val << " " << ans << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

