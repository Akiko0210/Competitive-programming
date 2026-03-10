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
const int N = 40;
bitset<2505> dp[N + 1][N + 1][400];

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    dp[0][0][0][0] = true;
    /*
    P1 = N
    P2 = NA
    P3 = NAC
    */

    for(int i = 0; i < n; i++) {
        if(s[i] != 'N' && s[i] != 'A' && s[i] != 'C') {
            for(int j = 0; j <= n; j++) {
                for(int l = 0; l < 400; l++) {
                    dp[i + 1][j][l] |= dp[i][j][l];
                }
            }
            // cout << dp[i + 1][0][0][0] << " copy\n";
            // debug(dp[i + 1][0][0][0], dp[i][0][0][0]);
        }

        if(s[i] == 'N' || s[i] == '?') {
            for(int j = 1; j <= n; j++) {
                for(int l = 0; l < 400; l++) {
                    dp[i + 1][j][l] |= dp[i][j - 1][l];
                }
            }
        }
        
        if(s[i] == 'A' || s[i] == '?') {
            // cout << "trying A\n";
            for(int j = 0; j <= n; j++) {
                // if k was possible, now k + j is possible.
                for(int l = j; l < 400; l++) {
                    dp[i + 1][j][l] |= dp[i][j][l - j];
                }
            }
        }

        if(s[i] == 'C' || s[i] == '?') {
            // cout << "trying C\n";
            for(int j = 0; j <= n; j++) {
                for(int l = 0; l < 400; l++) {
                    // dp[j][l][p] true to dp[i + 1][j][l][p + l] true
                    dp[i + 1][j][l] |= (dp[i][j][l] << l);
                }
            }
        }

    }

    int cn = -1, cna = -1, cnac = k;

    for(int i = 0; i <= n; i++) {
        for(int l = 0; l < 400; l++) {
            if(dp[n][i][l][k]) {
                // can make at k
                cn = i;
                cna = l;
            }
        }
    }

    if(cn == -1) {
        cout << "-1\n";
        return 0;
    }

    for(int i = n; i > 0; i--) {
        char c = s[i - 1];
        // dp[i][cn][cna][cnac] is guarenteed true. 
        if((c == 'N' || c == '?') && (cn >= 1 && dp[i - 1][cn - 1][cna][cnac])) {
            cn--;
            s[i - 1] = 'N';
            continue;
        }

        if((c == 'A' || c == '?') && (cna >= cn && dp[i - 1][cn][cna - cn][cnac])) {
            cna -= cn;
            s[i - 1] = 'A';
            continue;
        }

        if((c == 'C' || c == '?') && (cnac >= cna && dp[i - 1][cn][cna][cnac - cna])) {
            cnac -= cna;
            s[i - 1] = 'C';
            continue;
        }

        if(c == '?') {
            s[i - 1] = 'X';
        }
    }

    cout << s << "\n";

    // how to backtrack ? 






    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

