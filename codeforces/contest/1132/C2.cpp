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

const int N = 2e5;
vector<int> primes;

void sieve() {
    vector<bool> p(N + 1, true);
    for(int i = 2; i <= N; i++) {
        if(p[i]) {
            primes.pb(i);
            for(ll j = (ll)i * i; j <= N; j += i) {
                p[j] = false;
            }
        }
    }
}

int gcd(int a, int b) {
    if(b == 0) return a;

    return gcd(b, a % b);
}

void solve() {
    int a, b;
    cin >> a >> b;
    if(a == b) {
        cout << "0\n";
        return;
    }

    if(gcd(a, b) == 1) {
        cout << "1\n";
        cout << b - a << "\n";
        return;
    }

    auto it = upper_bound(primes.begin(), primes.end(), a);

    while (it != primes.end() && *it < b && b % *it == 0) ++it;
    if (it != primes.end() && *it < b) {
        int p = *it;
        cout << "2\n" << p - a << " " << b - p << "\n";
        return;
    }


    // a - b is at most 71.
    int d = b - a;
    vector<int> dp(d + 1, INF), prev(d + 1, -1);
    dp[0] = 0;
    for(int i = 1; i <= d; i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j] != INF && gcd(a + i, a + j) == 1) {
                if(dp[i] > dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }

    int cur = d;
    vector<int> vis;
    while(cur != -1) {
        // debug(cur);
        vis.pb(cur);
        cur = prev[cur];
    }

    reverse(vis.begin(), vis.end());
    cout << vis.size() - 1 << "\n";
    for(int i = 1; i < vis.size(); i++) {
        cout << vis[i] - vis[i - 1] << " ";
    }
    cout << "\n";
}

int main() {
    sieve();
    // int mx = 0;
    // for(int i = 2; i <= N / 2; i++) {
    //     int nxt = *lower_bound(primes.begin(), primes.end(), i);
    //     mx = max(mx, nxt - i);
    // }
    // debug(mx);

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

