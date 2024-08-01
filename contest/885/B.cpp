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
    vector<vector<int> > c(k + 1);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c[x].pb(i + 1);
    }

    int ans = INF;

    for(int i = 1; i <= k; i++) {
        int cur = 0;
        vector<int> temp;
        for(int x : c[i]) {
            temp.pb(x - cur - 1);
            cur = x;
        }
        temp.pb(n - cur);

        sort(temp.rbegin(), temp.rend());
        int mx = temp[0] / 2;
        if(temp.size() > 1) {
            mx = max(mx, temp[1]);
        }
        ans = min(ans, mx);
    }
    cout << ans << "\n";
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
