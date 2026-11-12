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
    string init;
    cin >> n >> m;
    vector<vector<int> > G(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    cin >> init;
    int curcost = 0;
    for(int i = 0; i < n; i++) {
        curcost += (init[i] == '1');
    }

    vector<bool> removed(n, false);
    
    auto get_cost = [&] () {
        vector<bool> inque(n, false);
        int cost = 0;

        for(int i = 0; i < n; i++) {
            if(removed[i] || inque[i]) continue;

            // get coloring of the component
            queue<pii> q;
            q.push({i, 0});
            inque[i] = true;
            int a = 0, b = 1;
            while(!q.empty()) {
                auto [cur, color] = q.front();
                q.pop();

                for(int x : G[cur]) {
                    if(removed[x] || inque[x]) continue;

                    inque[x] = true;
                    int ncolor = 1 - color;
                    if(ncolor == 1) a++;
                    else b++;

                    q.push({x, ncolor});
                }
            }

            cost += min(a, b);
        }

        return cost;
    };

    curcost = min(curcost, get_cost());
    int curremoved = 0;
    for(int i = 0; i < n; i++) {
        removed[i] = true;
        curremoved++;
        int cost = get_cost();
        if(cost + 2 * curremoved > curcost) {
            // not good enough to remove
            removed[i] = false;
            curremoved--;
        } else {
            curcost = cost + 2 * curremoved;
        }
    }

    cout << curcost << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

