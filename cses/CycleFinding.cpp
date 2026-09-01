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



int main() {
    int n, m;
    cin >> n >> m;
    vector<tii> edges(m);
    vector<vector<int> > G(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    vector<ll> cost(n + 1, 0);
    vector<int> pre(n + 1, -1);

    int changedNode = -1;
    for(int i = 0; i < n; i++) {
        changedNode = -1;
        for(auto [a, b, c] : edges) {
            if(cost[a] + c < cost[b]) {
                cost[b] = cost[a] + c;
                pre[b] = a;
                changedNode = b;
            }
        }
        if(changedNode == -1) {
            cout << "NO\n";
            return 0;
        }
        if(i == n - 1) {
            /*
            there's a negative cycle.
            find a cycle from changedNode.
            not every cycle from changedNode is a negative cycle.
            */
            cout << "YES\n";
            for(int j = 0; j < n; j++) {
                changedNode = pre[changedNode];
            }
            // now changedNode is in the loop
            int start = changedNode, temp = pre[changedNode];
            vector<int> path = {start};
            while(temp != start) {
                path.pb(temp);
                temp = pre[temp];
            }
            path.pb(temp);
            for(int j = path.size() - 1; j >= 0; j--) {
                cout << path[j] << " ";
            }
            cout << "\n";
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

