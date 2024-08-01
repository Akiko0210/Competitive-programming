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
    ll n, b, x, mx = 0;
    cin >> n >> b >> x;
    vector<ll> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        mx = max(mx, c[i]);
    }

    vector<ll> calc(mx + 1, 0), carry(mx + 1, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 2; j <= c[i]; j++) {
            ll a = c[i] / j;
            ll cur = (c[i] - a - 1) * (a + 1) * (c[i] % j);
            cur += (c[i] - a) * a * (j - c[i] % j);
            cur /= 2;
            // debug(cur, i, j, c[i]);
            calc[j] += cur;
            // divide i-th specy j times.
            /*
                a = c[i] / j
                c[i] % j udaa a + 1,
                j - c[i] % j udaa a
            */
            if(j == c[i])
                carry[c[i]] += cur;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= mx; i++) {
        carry[i] += carry[i - 1];
        ans = max(ans, (calc[i] + carry[i - 1]) * b - x * (i - 1));
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

