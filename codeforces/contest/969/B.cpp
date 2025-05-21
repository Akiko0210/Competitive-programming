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
    int n, m, mx = 0;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }

    while(m--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if(mx <= r && mx >= l)
            mx += c == '+' ? 1 : -1;
        cout << mx << " ";
    }
    cout << "\n";

    /*
    for all i such that l <= a[i] <= r
    
    */ 

    // while(m--) {
    //     char c;
    //     int l, r;
    //     cin >> c >> l >> r;
    //     if(l > n) continue;
    //     l--, r--;
    //     r = min(n - 1, r) + 1;

    //     cnt[l] += c == '+' ? 1 : -1;
    //     cnt[r] += c == '+' ? -1 : 1;
    // }
    // int ans = 0;
    // for(int i = 0; i <= n; i++) {
    //     if(i > 0)
    //         cnt[i] += cnt[i - 1];
    //     ans = max(ans, cnt[i] + a[i]);
    // }
    // cout << ans << "\n";
    
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

