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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 1, r = 1e9;
    while(l < r) {
        ll m = (l + r) / 2;
        // is m possible?
        ll last1 = 0, last2 = 1;
        for(int i = 1; i < n; i++) {
            ll dif = a[i] - a[i - 1];
            ll curbest;
            if(dif <= m) {
                curbest = min(last1, last2);
            } else if (dif <= 2 * m) {
                curbest = min(last1 + 1, last2 + 1);
            } else {
                curbest = min(last1 + 2, last2 + 1);
            }
            last1 = last2;
            last2 = curbest;
        }
        if(last2 > k) {
            // can't need larger m.
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l << "\n";
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

