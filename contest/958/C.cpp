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
    ll n;
    cin >> n;
    // bitwise OR
    /*
    14 = 1110 
    4
    4 10 12 14

    23 = 10111 -> 10110 -> 10101 -> 10011 -> 00111
    7 18 21 22 23
    */

    vector<ll> ans;
    ll last = n;
    while(last > 0) {
        ans.pb(last);
        // debug(last);
        ll k = n ^ last;
        if(k > last) break;

        // debug(last, n, k);
        for(int i = 60; i >= 0; i--) {
            if((k | (1LL << i)) < last && (n & (1LL << i))) {
                k = k | (1LL << i);
            }
        }
        last = k;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(ll x : ans) {
        cout << x << " ";
    }
    cout << "\n";
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

