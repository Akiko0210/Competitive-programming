#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF INT64_MAX
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
    ll n, c, d, base = 0, ans = INF;
    cin >> n >> c >> d;

    set<int> s;
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s.insert(x);
    }
    base = (n - (ll)s.size()) * c;

    n = s.size();
    vector<ll> a;
    for(int x : s) {
        a.pb(x);
    }
    sort(a.begin(), a.end());
    for(ll i = n - 1; i >= 0; i--) {
        ll cost = (a[i] - (i + 1)) * d + base;
        ans = min(cost, ans);
        a.pop_back();
        base += c;
    }
    ans = min(base + d, ans);
    cout << ans << "\n";
}

int main() {
    FAST
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
