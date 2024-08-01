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
    /*
        we have:
        p[i - 1]
        in order to find max range of segment starting with i, p[k] - p[i - 1] >= 0 must satisfy
        5 -6 3 -2 -1 0 0

        {1 5}, {3, 6}
    */
    ll n;
    cin >> n;
    vector<ll> a(n), p(n, 0), lim(n), mx(n, 0);
    vector<pair<ll, ll> > t(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = (i > 0 ? p[i - 1] : 0) + a[i];
        t[i] = {p[i], i};
    }

    sort(t.begin(), t.end());
    for(int i = n - 1; i >= 0; i--) {
        mx[i] = max((i == n - 1 ? 0 : mx[i + 1]), t[i].ss);
    }

    vector<pair<ll, ll> > ranges;

    for(int i = 0; i < n; i++) {
        pair<ll, ll> temp = {(i == 0 ? 0 : p[i - 1]), 0};
        ll ind = lower_bound(t.begin(), t.end(), temp) - t.begin();
        if(ind >= 0 && ind < n && t[ind].ff >= temp.ff && mx[ind] >= i) {
            lim[i] = mx[ind];
        } else {
            lim[i] = n;
        }
        ranges.pb({lim[i], i});
    }

    sort(ranges.begin(), ranges.end());
    vector<ll> dp(n, 0);
    ll ind = 0;
    for(int i = 0; i < n; i++) {
        if(i > 0) dp[i] = dp[i - 1];
        while(ind < n && ranges[ind].ff == i) {
            ll x = ranges[ind].ff, y = ranges[ind].ss;
            dp[i] = max(dp[i], x - y + 1 + (y > 0 ? dp[y - 1] : 0));
            ind++;
        }
    }

    cout << dp[n - 1] << "\n";
}

int main() {
    FAST
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}

/* stuff youi should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
