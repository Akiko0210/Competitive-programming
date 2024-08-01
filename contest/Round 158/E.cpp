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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int> > G(n);
    vector<int> sizes(n, 0);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        v--, u--;
        G[v].pb(u);
        G[u].pb(v);
        sizes[v]++;
        sizes[u]++;
    }

    vector<bool> del(n, false);

    auto par = [&] (int x) {
        for(int el : G[x]) {
            if(!del[el]) {
                return el;
            }
        }
        return -1;
    };

    for(int i = 0; i < n; i++) {
        if(sizes[i] == 1) {
            int prev = i, nxt = G[i][0], mx = v[i];
            while(sizes[nxt] == 2) {
                mx = max(mx, v[nxt]);
                sizes[nxt]--;
                del[prev] = true;
                for(int x : G[nxt]) {
                    if(x != prev) {
                        prev = nxt;
                        nxt = x;
                        break;
                    }
                }
            }
            v[nxt] = mx;
        }
    }

    vector<vector<int> > child(n);
    vector<bool> parented(n, false);
    
    auto calc = [&] (int x) {
        
    };

    for(int i = 0; i < n; i++) {

    }






}

int main() {
    int t = 1;
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

