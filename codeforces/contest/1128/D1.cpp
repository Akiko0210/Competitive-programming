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
    // m = 0 in this problem.
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
    }

    if(n == 1) {
        cout << "0\n";
        return;
    }

    if(n == 2) {
        cout << "1\n";
        cout << "1 1\n";
        return;
    }

    // if(n == 3) {
    //     cout << "2\n";
    //     cout << "1 2\n";
    //     cout << "2 3\n";
    //     return;
    // }

    int ans = (n - 3) / 2 + 2;
    cout << ans << "\n";
    cout << "1 2\n";
    for(int i = 2; i < ans; i++) {
        cout << (i - 1) * 2 << " " << i * 2 << "\n";
    }

    cout << ans * 2 - 2 << " " << ans * 2 - 1 << "\n";
   
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

