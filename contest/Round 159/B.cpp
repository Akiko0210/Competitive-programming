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
    ll n, p, l, t;
    cin >> n >> p >> l >> t;
    ll tasks = (n - 1) / 7 + 1, d = tasks / 2;
    // debug(d);
    if(d * (l + 2 * t) >= p) {
        cout << n - ((p - 1) / (l + 2 * t) + 1)<< "\n";
        return;
    }

    p -= d * (l + 2 * t);
    if(tasks & 1) {
        d++;
        p -= (l + t);
    }
    if(p <= 0) {
        cout << n - d << "\n";
        return;
    }

    cout << n - (d + (p - 1) / l + 1) << "\n";
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

