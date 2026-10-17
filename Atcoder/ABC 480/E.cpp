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
    ll n, ans = 0;
    cin >> n;
    for(ll start = 1; start < 1e6; start++) {
        ll total = 0;
        for(int len = 3; len < 20; len++) {
            int l = 1, r = 1e9;
            while(l < r) {
                ll m = (l + r) / 2;
                __int128 prod = 1;
                bool can = true;
                for(int i = 0; i < len; i++) {
                    prod *= start + (m * i);
                    if(prod > n) {
                        can = false;
                        break;
                    }
                }

                if(can) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            if(l > 1)
                total += (l - 1);
            else 
                break;
        }
        if(total == 0) {
            break;
        }
        
        ans += total;
        // debug(ans, start);
    }
    cout << ans << "\n";
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

