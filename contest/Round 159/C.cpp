#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
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

int gcd(int a, int b) {
    if(a == 0) return b;

    return gcd(b % a, a);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll x = 0; // 
    for(int i = 1; i < n; i++) {
        x = gcd(x, a[i] - a[i - 1]);
        // debug(x);
    }
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += (a[n - 1] - a[i]) / x;
    }

    bool fnd = false;
    for(int i = 1; i < n; i++) {
        if(a[n - 1 - i] + i * x == a[n - 1]) {
            continue;
        }
        // debug(i);
        ans += i;
        fnd = true;
        break;
    }

    if(fnd)
        cout << ans << "\n";
    else 
        cout << ans + n << "\n";


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

