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

const ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), pos;
    vector<vector<int> > G(n); 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) pos.pb(i);
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    for(int x : pos) {
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        vector<bool> vis(n, 0);
        pq.push({a[x], x});
        int power = 0;
        while(!pq.empty() && pq.top().ff <= power) {
            int cur = pq.top().ss;
            pq.pop();

            if(vis[cur]) continue;
            vis[cur] = 1;
            power++;
            
            for(int x : G[cur]) {
                pq.push({a[x], x});
            }
        }
        if(power == n) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";



}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
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
