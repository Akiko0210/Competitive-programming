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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> pos(k);
    ll res = 0;
    map<int, vector<pii> > mat;

    for(int i = 0; i < k; i++) {
        cin >> pos[i].ff >> pos[i].ss;
        mat[pos[i].ss].pb({pos[i].ff, i});
    }

    vector<bool> ans(k, 0);

    int curmx = 0, prevcol = 1;
    for(auto &[col, v] : mat) {
        res += (ll)(n - curmx) * (col - prevcol);
        prevcol = col;
        int mx = 0, ind;
        for(pii x : v) {
            if(x.first > mx) {
                mx = x.first;
                ind = x.second;
            }
        }
        if(mx > curmx) {
            ans[ind] = 1;
            curmx = mx;
        }
    }
    res += (ll)(m - prevcol + 1) * (n - curmx);

    cout << res << "\n";
    for(bool x : ans) {
        cout << x << " ";
    }
    cout << "\n";
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

