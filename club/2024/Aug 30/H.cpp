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
    ll n;
    cin >> n;
    vector<ll> factors;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            factors.pb(i);
            if(i != n / i) {
                factors.pb(n / i);
            }
        }
    }

    sort(factors.rbegin(), factors.rend());
    for(ll x : factors) {
        bool div = false;
        for(ll i = 2; i * i <= x; i++) {
            if(x % (i * i) == 0) {
                // debug(x, i * i);
                div = true;
            }
        }
        if(!div) {
            cout << x << "\n";
            return 0;
        }
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

