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
    string s, l, r;
    int m, n;
    cin >> s >> m >> l >> r;
    n = s.size();
    vector<vector<int> > pos(10);
    for(int i = 0; i < n; i++) {
        pos[s[i] - '0'].pb(i);
    }
    for(int i = 0; i < 10; i++) {
        pos[i].pb(n);
    }

    int latest = -1;
    for(int i = 0; i < m && latest < n; i++) {
        int mx = 0;
        for(char c = l[i]; c <= r[i]; c++) {
            int ind = *upper_bound(pos[c - '0'].begin(), pos[c - '0'].end(), latest);
            mx = max(mx, ind);
        }

        latest = mx;
        // debug(n, i, latest);
    }
    cout << (latest == n ? "YES\n" : "NO\n");
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

