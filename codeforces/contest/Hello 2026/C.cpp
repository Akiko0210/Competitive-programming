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
    int l = k - 1, r = n - k;
    if(l > r) swap(l, r);

    if(l == 0) {
        cout << min(n, (m + 1) / 2 + 1) << "\n";
        return;
    }

    if(r - 1 + (l + r) <= m) {
        cout << n << "\n";
        return;
    }


    if(l - 1 + l * 2 <= m) {
        m -= l * 3 - 1;
        cout << l * 2 + 1 + m / 2 << "\n";
        return;
    }
    int ans = 1 + (m + 1) / 3 * 2;
    if((m + 1) % 3 == 2) {
        ans ++;
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

