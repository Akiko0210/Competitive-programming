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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    // track the last number.
    // how to deal with cycle? if we find cycle its yes
    vector<bool> vis(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cur = n - 1;
    while(k--) {
        // debug(cur);
        if(vis[cur]) {
            cout << "Yes\n";
            return;
        }
        vis[cur] = 1;
        if(a[cur] > n) {
            cout << "No\n";
            return;
        }
        cur = (cur - a[cur] + n) % n;
    }
    // debug(cur);
    cout << "Yes\n";
    return;
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

