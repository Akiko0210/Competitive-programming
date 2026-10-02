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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<pii> p(n);
    set<pii> cnt;
    for(int i = 0; i < n; i++) {
        cin >> p[i].ff >> p[i].ss;
        p[i].ff -= x;
        p[i].ss -= y;

        int g = gcd(p[i].ff, p[i].ss);
        cnt.insert({p[i].ff / g, p[i].ss / g});
    }

    cout << cnt.size() << "\n";

}

int main() {
    int t = 1;
    // cin >> t;
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


