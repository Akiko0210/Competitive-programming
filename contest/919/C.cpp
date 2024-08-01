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
    /*
        look at the divisors of n.
    */
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> divs;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divs.pb(i);
            if(n / i != i) {
                divs.pb(n / i);
            }
        }
    }
    // sort(divs.begin(), divs.end());
    int ans = 0;
    for(int x : divs) {
        int g = 0;
        for(int i = 0; i < x; i++) {
            for(int j = i + x; j < n; j += x) {
                g = gcd(g, abs(a[j] - a[j - x]));
            }
        }
        if(g != 1) {
            debug(x);
            ans++;
        }
    }
    cout << ans << "\n";

}

int main() {
    FAST
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

