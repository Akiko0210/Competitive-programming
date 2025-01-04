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
    int n, s, ps, pu, total_turns;
    cin >> n >> s;
    total_turns = 2 * n * (s + 1);
    vector<int> turns(total_turns);
    for(int i = 0; i < total_turns; i++) {
        cin >> turns[i];
        turns[i]--;
    }

    cin >> ps;
    vector<int> sa(ps);
    for(int i = 0; i < ps; i++) {
        cin >> sa[i];
    }
    sort(sa.rbegin(), sa.rend());

    cin >> pu;
    vector<int> ua(pu);
    for(int i = 0; i < pu; i++) {
        cin >> ua[i];
    }
    sort(ua.rbegin(), ua.rend());
    int max_mask = (1 << (2 * n));
    vector<int> bits(max_mask, 0);
    for(int mask = 0; mask < max_mask; mask++) {
        for(int j = 0; j < 2 * n; j++) {
            if(mask & (1 << j)) {
                bits[mask]++;
            }
        }
    }
    vector<vector<ll> > dp(total_turns + 1, vector<ll> (max_mask));
    for(int i = 0; i < max_mask; i++) {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= total_turns; i++) {
        for(int mask = 0; mask < max_mask; mask++) {
            if(turns[i - 1] < n) {
                dp[i][mask] = -INF;
            } else {
                dp[i][mask] = INF;
            }
        }
    }

    // for(int i = 0; i <= total_turns; i++) {
    //     for(int mask = 0; mask < max_mask; mask++) {
    //         cout << dp[i][mask] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 0; i < total_turns; i++) {
        int sign = turns[i] < n ? 1 : -1;
        ll imp = (i > 0 && turns[i - 1] < n ? -INF : INF);
        for(int mask = 0; mask < max_mask; mask++) {
            if(bits[mask] > i + 1) continue;


            if(dp[i][mask] != imp && i >= bits[mask] && i - bits[mask] < ps) {
                if(sign > 0) {
                    dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask] + sa[i - bits[mask]]);
                } else {
                    dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask] - sa[i - bits[mask]]);
                }
            }
            if((mask & (1 << turns[i])) && dp[i][mask ^ (1 << turns[i])] != imp) {
                if(sign > 0) {
                    dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask ^ (1 << turns[i])] + ua[bits[mask] - 1]);
                } else {
                    dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask ^ (1 << turns[i])] - ua[bits[mask] - 1]);
                }
            }
        }
    }

    ll ans = dp[total_turns][max_mask - 1];
    cout << ans << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

