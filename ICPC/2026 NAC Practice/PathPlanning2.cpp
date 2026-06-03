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

void solve() {
    const int MX = 1e6;
    int n, m;
    cin >> n >> m;
    vector<vector<int> > mat(n, vector<int> (m));
    vector<vector<pii> > pos(MX);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] < MX) {
                pos[mat[i][j]].pb({i, j});
            }
        }
    }

    auto propagate = [&] (vector<int>& stones, vector<pii>& cursegs, vector<pii>& nxt) {
        int ind = 0;

    };


    for(int i = 0; i < MX; i++) {
        if(pos[i].empty()) {
            cout << i << "\n";
            return;
        }
        // intial segment.
        
        pii prev = pos[i][0];
        vector<int> stones;
        vector<pii> curflow, nxt;
        curflow.pb({0, 0});
        int ind = 0;
        for(pii p : pos[i]) {
            if(p.ff != prev.ff) {
                // entering new row.
                // [last, m - 1]
                if(p.ff >= prev.ff + 2) {
                    stones.clear();
                }
                propagate(stones, curflow, nxt);
                stones.clear();
            } 
            stones.pb(p.ss);
            
        }
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

