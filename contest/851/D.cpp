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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> fact(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * 2 % MOD;
    } 
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int dis = a[j] - a[i];
            int mn_ind = lower_bound(a.begin(), a.end(), a[i] - dis) - a.begin();
            int mx_ind = lower_bound(a.begin(), a.end(), a[j] + dis) - a.begin();
            mx_ind = n - mx_ind;
            ll temp = fact[mn_ind] * fact[mx_ind] % MOD;
            // cout << i << " " << j << " " << temp << "\n";
            (ans += temp) %= MOD;
        }
    }
    cout << ans << "\n";

    /*
    in how many cases a[x] and a[y] attract to each other? 
    let dis be the distance.
    dis = a[y] - a[x];
    number of element less than (a[x] - dis) times number of element more or equal than (a[y] + dis);
    */

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
