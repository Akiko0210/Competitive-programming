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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int> > dp(n, vector<int> (m, 0));
    vector<vector<pii> > prev(n, vector<pii> (m, {-1, -1}));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i > 0) {
                // dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(dp[i][j] < dp[i - 1][j]) {
                    prev[i][j] = {i - 1, j};
                    dp[i][j] = dp[i - 1][j];
                }
            }

            if(j > 0) {
                // dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                if(dp[i][j] < dp[i][j - 1]) {
                    prev[i][j] = {i, j - 1};
                    dp[i][j] = dp[i][j - 1];
                }
            }

            if(a[i] == b[j]) {
                int come = (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
                // dp[i][j] = max(dp[i][j], come + 1);
                if(come + 1 > dp[i][j]) {
                    dp[i][j] = come + 1;
                    prev[i][j] = {i - 1, j - 1};
                }
            }
        }
    }

    int curx = n - 1, cury = m - 1;
    vector<int> ans;
    while(curx >= 0 && cury >= 0) {
        auto [x, y] = prev[curx][cury];
        int prevcost = (x >= 0 && y >= 0 ? dp[x][y] : 0);
        if(dp[curx][cury] == prevcost + 1) {
            ans.pb(a[curx]);
        }
        curx = x;
        cury = y;
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int x : ans) {
        cout << x << " ";
    }
    cout << "\n";



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

