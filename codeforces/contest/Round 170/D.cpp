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
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(m + 1), intcnt(m + 1), strcnt(m + 1);
    for(int i = 0; i <= m; i++) {
        dp[i].resize(i + 1, 0);
        intcnt[i].resize(i + 1, 0);
        strcnt[i].resize(i + 1, 0);
    }
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int r;
        cin >> r;
        if(r == 0) {
            cur ++;
            continue;
        }

        if(abs(r) > cur) {
            continue;
        }

        if(r < 0) {
            strcnt[cur][abs(r)]++;
        } else {
            intcnt[cur][abs(r)]++;
        }
    }

    for(int i = 0; i <= m; i++) {
        for(int j = 1; j <= i; j++) {
            intcnt[i][j] += intcnt[i][j - 1];
            strcnt[i][j] += strcnt[i][j - 1];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= i; j++) {
            int curadd = intcnt[i][j] + strcnt[i][i - j];
            dp[i][j] = max(j <= i - 1 ? dp[i - 1][j] : 0, j > 0 ? dp[i - 1][j - 1] : 0) + curadd;
        }
    }

    cout << *max_element(dp[m].begin(), dp[m].end()) << "\n";
    /*
    r = 0 -> add+
    r > 0 -> test if |r| <= intelligence
    r < 0 -> test if |r| <= strenght
    */
}

int main() {
    FAST
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

