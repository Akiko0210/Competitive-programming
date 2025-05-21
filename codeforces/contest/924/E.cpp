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
    ll n, x, y, s;
    cin >> n >> x >> y >> s;
    ll basesum = (x + (n - 1) * (x % y));
    // debug(basesum, s);
    // solution exist but said no.
    if(basesum > s || (s - basesum) % y != 0) {
        cout << "NO\n";
        return;
    }
    ll cnt = (s - basesum) / y, cur = x / y;
    vector<ll> ans(n);
    ans[0] = x;
    for(int i = 1; i < n; i++) {
        cur++;
        if(cnt >= cur) {
            ans[i] = x % y + y * cur;
            cnt -= cur;
        } else {
            cur = 0;
            ans[i] = x % y;
        }
    }
    if(cnt > 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(ll x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    /*
    8 + (1-8) = 44
    8 + 9 + 10 + 11 + 1 + 2 + 3
    */

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

