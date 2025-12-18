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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    auto dis = [&](int i, int j) {
        int ydis = y[i] - y[j];
        int xdis = x[i] - x[j];
        return xdis * xdis + ydis * ydis;
    };

    int max_mask = (1 << n);
    vector<vector<int> > dp(n, vector<int> (max_mask, 1e9));
    for(int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for(int mask = 1; mask < max_mask; mask++) {
        for(int i = 1; i < n; i++) {
            // dp[i][mask]
            if(i > 0) {
                dp[i][mask] = dp[i - 1][mask];
            }
            if(!(mask & (1 << i))) continue;

            for(int j = 0; j < n; j++) {
                if(j == i && !(mask & (1 << j))) continue;

                int cur_dis = dis(j, i);
                dp[i][mask] = min(dp[i][mask], dp[i - 1][mask ^ (1 << i) ^ (1 << j)] + cur_dis);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int mask = 0; mask < max_mask; mask++) {
            cout << (dp[i][mask] == 1e9 ? -1 : dp[i][mask]) << " ";
        }
        cout << "\n";
    }

    cout << dp[n - 1][max_mask - 1] << " ans\n";


    return 0;
}