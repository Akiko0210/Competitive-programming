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
    int n, a, b;
    cin >> n >> a >> b;
    if(n < a + b || (a + b > 0 && (a == 0 || b == 0))) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        if(i <= n - a - b) {
            cout << i << " ";
        } else {
            cout << n - (i - (n - a - b)) + 1 << " ";
        }
    }
    cout << "\n";
    
    for(int i = 1; i <= n; i++) {
        if(i <= n - a - b) {
            cout << i << " ";
        } else if(i <= n - b) {
            cout << n - b - (i - (n - a - b)) + 1 << " ";
        } else {
            cout << n - (i - (n - b)) + 1 << " ";
        }
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

