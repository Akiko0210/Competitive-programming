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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    auto calc = [&](int x) -> pair<ll, int> {
        int u = x - a[0], d = a[n - 1] - x;
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            int dif = abs(x - a[i]);
            if(a[i] < x) {
                ans += abs(dif - (u - d));
            }
            if(a[i] > x) {
                ans += abs(dif - (d - u));
            }
            if(a[i] == x) {
                ans += abs(dif - (d - u));
            }
        }
        return {ans, u + d};
    };

    int l = a[0], r = a[n - 1];
    while(l < r) {
        int m = l + (r - l) / 2;
        pair<ll, int> mval = calc(m), lval = calc(m - 1), rval = calc(m + 1);
        if(lval > mval && mval > rval) {
            l = m + 1;
            continue;
        }

        if(lval < mval && mval < rval) {
            r = m - 1;
            continue;
        }
        debug(m);
        cout << mval.ff << " " << mval.ss << "\n";
        return;
    }
    
    debug(l);
    pair<ll, int> ans = calc(l);
    cout << ans.ff << " " << ans.ss << "\n";


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

