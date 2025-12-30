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
    ll n, m, k;
    cin >> n >> m >> k;
    multiset<int> a;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }

    vector<pii> up(n);
    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        k -= y;
        up[i] = {z - y, x};
    }

    int ans = 0;
    vector<ll> rem;
    sort(up.rbegin(), up.rend());
    for(auto &[u, x] : up) {
        auto it = a.lower_bound(x);
        if(it != a.end()) {
            // can remove.
            a.erase(it);
            ans++;
        } else {
            rem.pb(u);
        }
    }

    while(!rem.empty() && k >= rem.back()) {
        k -= rem.back();
        rem.pop_back();
        ans++;
    }

    cout << ans << "\n";
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

