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
    ll N, C, T;
    cin >> N >> C >> T;

    if(N == 1) {
        cout << "0\n";
        return 0;
    }
    
    if(C > T) {
        cout << "-1\n";
        return 0;
    }

    if(N <= 2) {
        cout << "1\n";
        return 0;
    }

    ll cols = T / C, rows = 0;
    while((1LL << rows) <= N) {
        rows++;
    }

    vector<vector<ll> > dp(rows, vector<ll> (cols, 0));

    for(int i = 0; i < rows; i++) {
        dp[i][0] = (1LL << (i + 1));
    }

    for(int i = 0; i < cols; i++) {
        dp[0][i] = i + 2;
    }

    if(dp[0][cols - 1] >= N) {
        cout << "1\n";
        return 0;
    }

    for(int i = 1; i < rows; i++) {
        if(dp[i][0] >= N) {
            cout << i + 1 << "\n";
            return 0;
        }
        for(int j = 1; j < cols; j++) {
            ll multiplier = (1LL << (i + 1)) - 1;
            bool add = ((N - dp[i][j - 1]) % multiplier > 0);
            if((N - dp[i][j - 1]) / multiplier + add <= dp[i - 1][j - 1]) {
                cout << i + 1 << "\n";
                return 0;
            }
            dp[i][j] = dp[i][j - 1] + multiplier * dp[i - 1][j - 1];
        }
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

