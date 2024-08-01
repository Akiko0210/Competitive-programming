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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), cnt(n, 0), pre(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = a[i];
        if(i > 0) pre[i] += pre[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        ll num = (i == 0 ? 0 : pre[i - 1]) + x;
        int ind = upper_bound(pre.begin() + i, pre.end(), num) - pre.begin();
        if(ind < n) {
            cnt[i] += (ind < n - 1 ? cnt[ind + 1] : 0) + 1;
        }
    }
    ll ans = n * (n + 1) / 2;
    for(int i = 0; i < n; i++) 
        ans -= cnt[i];
    
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

