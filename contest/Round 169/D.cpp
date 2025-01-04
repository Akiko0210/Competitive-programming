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
    int n, q;
    cin >> n >> q;
    map<string, vector<int> > m;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]].pb(i);
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);

        bool direct = false;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(a[l][i] == a[r][j]) {
                    direct = true;
                }
            }
        }

        if(direct) {
            cout << r - l << "\n";
            continue;
        }
        int mid = n + 1, mx = 0, mn = n + 1;
        for(auto &[k, v] : m) {
            // l, r
            if(k == a[l] || k == a[r]) continue;
            
            auto it = upper_bound(v.begin(), v.end(), l);
            if(it != v.end()) 
                mid = min(mid, *it);
            

            if(it != v.begin()) 
                mx = max(mx, *prev(it));
            

            it = upper_bound(v.begin(), v.end(), r);
            if(it != v.end())
                mn = min(mn, *it);
            
        }

        if(mid <= r) {
            cout << r - l << "\n";
            continue;
        }
        // debug(mx, mn, mid);
        int ans = INF;
        if(mx > 0) {
            ans = min(l - mx + r - mx, ans);
        }

        if(mn < n + 1) {
            ans = min(ans, mn - r + mn - l);
        }
        if(ans == INF) ans = -1;

        cout << ans << "\n";
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

