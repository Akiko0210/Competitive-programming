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
    ll n, h, k, sum = 0;
    cin >> n >> h >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    /*
    int m = h / sum;
    ans = m * n + m * k + [extra]

    minimize extra.
    
    */

    ll m = (h - 1) / sum;
    ll ans = m * n + m * k;
    h -= m * sum;
    
    vector<ll> mx(n, 0), mn(n, 0), presum(n, 0);
    for(int i = n - 1; i >= 0; i--) {
        mx[i] = a[i];
        if(i < n - 1) {
            mx[i] = max(mx[i], mx[i + 1]);
        }
    }

    ll extra = n;
    for(int i = 0; i < n; i++) {
        mn[i] = a[i];
        presum[i] = a[i];
        if(i > 0) {
            mn[i] = min(mn[i], mn[i - 1]);
            presum[i] += presum[i - 1];
        }

        if(presum[i] >= h) {
            extra = i + 1;
            break;
        }

        if(i < n - 1 && presum[i] - mn[i] + mx[i + 1] >= h) {
            extra = i + 1;
            break;
        }
    }

    ans += extra;
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

