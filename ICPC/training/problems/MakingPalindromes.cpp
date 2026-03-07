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

vector<vector<vector<ll> > > dp;
int n;
string s;

ll pw(ll a, ll b) {
    if(b == 0) return 1;
    ll h = pw(a, b / 2);
    h = h * h % MOD;
    if(b & 1)
        h = h * a % MOD;
    return h;
}

ll calc(int i, int l, int r) {
    if(l > r) {
        return pw(26, n - i);
    }

    if(2 * n - 2 * i < r - l + 1) {
        return 0;
    }

    if(dp[i][l][r] != -1) {
        return dp[i][l][r];
    }
    dp[i][l][r] = 0;

    if(i == n - 1) {
        return dp[i][l][r] = (s[l] == s[r]);
    }

    if(s[l] == s[r]) {
        dp[i][l][r] += calc(i + 1, l + 1, r - 1);
        dp[i][l][r] += calc(i + 1, l, r) * 25;
    } else {
        dp[i][l][r] += calc(i + 1, l, r) * 24;
        dp[i][l][r] += calc(i + 1, l + 1, r);
        dp[i][l][r] += calc(i + 1, l, r - 1);
    }
    // debug(i, l, r, dp[i][l][r]);
    dp[i][l][r] %= MOD;
    return dp[i][l][r];
}

void solve() {
    cin >> n >> s;
    if(n == 0) {
        cout << "1\n";
        return;
    }
    dp = vector (n + 1, vector (n + 1, vector (n + 1, (ll)-1)));
    cout << calc(0, 0, n - 1) << "\n";
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }


    return 0;
}