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
    int n, m; // 2000, 2000
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /*
    1
    WW
    WB

    2
    BW
    WB

    WWWW
    WBBW
    WBBW
    WWWW




    WWW WWW
    WWW WBB
    WWW WWW

    BBB
    WWW
    WWW
    ---
    After each touch, star is formed. 

    2^(locked cell)
    */

    int x[] = {1, 0, -1, 0};
    int y[] = {0, 1, 0, -1};

    auto islocked = [&] (int cx, int cy) {
        for(int i = 0; i < 4; i++) {
            int nx = cx + x[i], ny = cy + y[i];
            if(nx >= n || nx < 0 || ny >= m || ny < 0 || a[nx][ny] == a[cx][cy]) {
                continue;
            }
            return false;
        }
        return true;
    };

    int ans = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(islocked(i, j)) {
                ans = ans * 2 % MOD;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
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

