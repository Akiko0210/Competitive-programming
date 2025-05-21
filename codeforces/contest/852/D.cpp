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
    ll n;
    cin >> n;
    vector<int> p(n), q(n), a(n + 1), b(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        a[p[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> q[i];
        b[q[i]] = i;
    }

    ll total = n * (n + 1) / 2, l = n - 1, r = 0;
    for(int i = 1; i <= n; i++) {
        ll x = max(a[i], b[i]), y = min(a[i], b[i]);
        // for min
        total -= (min(l, y) + 1) * max(0LL, x - max(y, r));
        // cout << i << " " << total << "\n";
        total -= max(0LL, min(l, x) - y) * (n - max(x, r));
        // cout << i << " " << total << "\n";
        l = min(l, y);
        r = max(r, x);
    }
    cout << total << "\n";

}

int main() {
    int t = 1;
    // cin >> t;
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
