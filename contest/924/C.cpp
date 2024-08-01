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
    int n, x;
    cin >> n >> x;
    /*
    position and number
    for k:
        position and number relation:
        if pos = n,
        num is t = n % (2k - 2) + 1
        and if t > k, 2k - t
        and if t <= k, k

    so if the x is considered in the first k, 
    n % (2k - 2) = x;
    rem = x;
    n - x | 2k - 2

    if the x is in the second k - 2,
    2k - (n % (2k - 2)) = x
    2k - n % (2k - 2) = x;
    2k - x = n % (2k - 2)
    n - 2k + x | 2k - 2
    n - (2k - 2) + x - 2 | 2k - 2
    n + x + 2 | 2k - 2

    and for both statement, k >= x
    */

    int t = n - x;
    set<int> ans;
    for(ll i = 1; i * i <= t; i++) {
        if(t % i == 0) {
            if(i % 2 == 0 && (i / 2 + 1) >= x)
                ans.insert(i / 2 + 1);

            if((t / i) % 2 == 0 && (t / i / 2 + 1) >= x) {
                ans.insert(t / i / 2 + 1);
            }
        }
    }
    t = n + x - 2;
    for(ll i = 1; i * i <= t; i++) {
        if(t % i == 0) {
            if(i % 2 == 0 && (i / 2 + 1) >= x)
                ans.insert(i / 2 + 1);

            if((t / i) % 2 == 0 && (t / i / 2 + 1) >= x) {
                ans.insert(t / i / 2 + 1);
            }
        }
    }
    // for(int x : ans) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    cout << ans.size() << "\n";

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

