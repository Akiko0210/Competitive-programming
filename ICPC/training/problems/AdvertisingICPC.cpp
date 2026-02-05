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

const ll MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'I') a[i][j] = 0;
            if(s[j] == 'C') a[i][j] = 1;
            if(s[j] == 'P') a[i][j] = 2;
            if(s[j] == '?') a[i][j] = -1;
        }
    }

    vector<vector<vector<ll> > > dp(n, vector<vector<ll> > (m, vector<ll> (9, 0)));
    vector<ll> cnt(3, 0);
    if(a[0][0] == -1) {
        cnt[0] = cnt[1] = cnt[2] = 1;
    } else {
        cnt[a[0][0]] = 1;
    }
    for(int i = 1; i < m; i++) {
        if(a[0][i] == -1) {
            // 0, 1, 2
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    dp[0][i][j * 3 + k] = cnt[j];
                }
            }
        } else {
            for(int j = 0; j < 3; j++) {
                dp[0][i][j * 3 + a[0][i]] = cnt[j];
            }
        }

        cnt[0] = cnt[1] = cnt[2] = 0;
        for(int j = 0; j < 9; j++) {
            (cnt[j % 3] += dp[0][i][j]) %= MOD;
        }
    }

    for(int i = 1; i < n; i++) {
        cnt[0] = cnt[1] = cnt[2] = 0;
        if(a[i][0] == -1) {
            cnt[0] = cnt[1] = cnt[2] = 1;
        } else {
            cnt[a[i][0]] = 1;
        }

        for(int j = 1; j < m; j++) {
            if(a[i][j] == -1) {
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        dp[i][j][k * 3 + l] = cnt[k];
                    }
                }
            } else {
                for(int k = 0; k < 3; k++) {
                    dp[i][j][k * 3 + a[i][j]] = cnt[k];
                }
            }
            cnt[0] = cnt[1] = cnt[2] = 0;
            ll sum = 0;
            for(int k = 0; k < 9; k++) {
                sum += dp[i - 1][j][k];
                (cnt[k % 3] += dp[i][j][k]) %= MOD;
            }

            for(int k = 0; k < 9; k++) {
                dp[i][j][k] = dp[i][j][k] * (k == 7 ? sum - dp[i - 1][j][1] : sum) % MOD;
            }
        }
    }

    ll total = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == -1) {
                total = (total * 3) % MOD; 
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < 9; i++) {
        debug(i, dp[n - 1][m - 1][i]);
        debug(i, dp[n - 2][m - 1][i]);
        ans = (ans + dp[n - 1][m - 1][i]) % MOD;
    }
    cout << ((total - ans) % MOD + MOD) % MOD << "\n";
    /*
    ??P
    ?C? -> 


    
    */
    



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

