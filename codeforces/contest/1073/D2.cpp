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

void solve() {
    /*
    a better than b if
    1) a[i] = (
    b[i] = ) 
    OR
    2) b is prefix of a. a != b.

    ((()))()()
         ij k

    ()()()
     ij k
    (())

    ans = sum of every subseq score 
    = sum of every regular bracket subseq score

    score of s is subseq of s, r, that is better than s. 
    r can't be better than s while being subseq of s. 
    so r is better than s in only (1) way. 



    */
    int n;
    string s;
    cin >> n >> s;
    // pattern : )((
    vector<vector<vector<int> > > cnt(n + 1, vector<vector<int> > (n + 1, vector<int> (4, 0)));;
    vector<vector<vector<int> > > sum(n + 1, vector<vector<int> > (n + 1, vector<int> (4, 0)));;
    for(int i = 0; i < n; i++) {
        // debug(i);
        if(i == 0) {
            if(s[i] == '(') {
                cnt[i][1][0] = 1;
                sum[i][1][0] = 1;
            } else {
                // can't do anything with it. 
            }
        } else {
            if(s[i] == '(') {
                for(int j = 1; j <= n; j++) {
                    int extra = (j == 1);
                    // 0
                    cnt[i][j][0] = (cnt[i - 1][j - 1][0] + extra) % MOD;
                    sum[i][j][0] = (sum[i - 1][j - 1][0] + cnt[i][j][0]) % MOD;
                    // 1
                    // cnt[i][j][1] = cnt[i - 1][j - 1][1];
                    // sum[j][j][1] = (sum[i - 1][j - 1][1] + cnt[i][j][1]) % MOD;
                    // 2
                    cnt[i][j][2] = cnt[i - 1][j - 1][1];
                    sum[i][j][2] = (sum[i - 1][j - 1][1] + cnt[i][j][2]) % MOD;
                    // 3
                    cnt[i][j][3] = (cnt[i - 1][j - 1][2] + cnt[i - 1][j - 1][3]) % MOD;
                    sum[i][j][3] = ((sum[i - 1][j - 1][2] + sum[i - 1][j - 1][3]) % MOD + cnt[i][j][3]) % MOD;
                }
            } else {
                for(int j = 0; j < n; j++) {
                    // 0
                    // not possible.
                    // 1
                    cnt[i][j][1] = (cnt[i - 1][j + 1][0] + cnt[i - 1][j + 1][1]) % MOD;
                    sum[i][j][1] = ((sum[i - 1][j + 1][0] + sum[i - 1][j + 1][1]) % MOD + cnt[i][j][1]) % MOD;
                    // 2
                    cnt[i][j][2] = cnt[i - 1][j + 1][2];
                    sum[i][j][2] = (sum[i - 1][j + 1][2] + cnt[i][j][2]) % MOD;
                    // 3
                    cnt[i][j][3] = cnt[i - 1][j + 1][3];
                    sum[i][j][3] = (sum[i - 1][j + 1][3] + cnt[i][j][3]) % MOD;
                }
            }

            for(int j = 0; j <= n; j++) {
                for(int k = 0; k < 4; k++) {
                    cnt[i][j][k] = (cnt[i][j][k] + cnt[i - 1][j][k]) % MOD;
                    sum[i][j][k] = (sum[i][j][k] + sum[i - 1][j][k]) % MOD;
                }
            }
        }
        // for(int j = 0)
    }

    // n - 1, 0, 3
    int ans = (sum[n - 1][0][3] - 2 * cnt[n - 1][0][3] % MOD + MOD) % MOD;
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

