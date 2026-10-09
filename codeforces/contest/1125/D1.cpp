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
    ll n, k;
    cin >> n >> k;
    vector<array<ll, 3> > arr(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    auto ask = [&](ll x) -> bool {
        // can we make everything at least x?

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            auto [a, b, c] = arr[i];
            ll sum = a + b + c;
            if(sum >= x) continue;

            if(a > b || a > c || b > c) {
                ans += x - sum;
            } else {
                // a <= b <= c
                ll enable = 1LL << 60;
                if(a != c) enable = min(enable, b - a + 1);
                if(a != b) enable = min(enable, c - b + 1);

                ans += enable * 2 + x - sum;
            }

            if(ans > k) return false;
        }
        // cout << x << " " << ans << "\n";
        return true;
    };


    ll l = -(1LL << 60), r = 1LL << 61;
    while(l < r) {
        ll m = l + (r - l + 1) / 2;
        if(ask(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << l << "\n";
}

int main() {
    FAST
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

