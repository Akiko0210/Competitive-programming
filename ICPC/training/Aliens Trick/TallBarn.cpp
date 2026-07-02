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

int main() {
    ifstream cin("tallbarn.in");
    ofstream cout("tallbarn.out");
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](double m) -> pair<double, ll> {
        ll rc = 0;
        double ans = 0;
        for(int i = 0; i < n; i++) {
            ll c = ((double)sqrt(1.0 + 4.0 * a[i] / m) - 1) / 2.0 + 1;
            ans += double(a[i]) / c + m * c;
            rc += c;
        }
        return {ans, rc};
    };

    double l = 0, r = 1e12;

    for(int i = 0; i < 70; i++) {
        double m = (l + r) / 2;
        auto [G, c] = check(m);
        if(c >= k) {
            // increase the range
            l = m;
        } else {
            r = m;
        }
    }
    auto [G, c] = check(l);
    cout << (ll)(G - l * k + 0.5) << "\n";
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

