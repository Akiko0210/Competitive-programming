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

ll pw(ll a, ll b) {
    if(b == 1) return a;

    ll h = pw(a, b / 2);
    h = h * h % MOD;
    if(b & 1) {
        return h * a % MOD;
    }
    return h;
}

void solve() {
    ll n, k, sum = 0, specialSum = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i < k) {
            (specialSum += a[i]) %= MOD;
        } else {
            (sum += a[i]) %= MOD;
        }
    }

    ll aliceNormalExpected = sum * pw(n - k, MOD - 2) % MOD * ((n - k + 1) / 2) % MOD;

    ll aliceSpecialExpected = specialSum * pw(k, MOD - 2) % MOD * ((n - k + 2) / 2) % MOD * k % MOD * pw(n - k + 1, MOD - 2) % MOD;

    ll alice = (aliceNormalExpected + aliceSpecialExpected) % MOD, bob = (sum + specialSum - alice + MOD) % MOD;
    cout << alice << " " << bob << "\n";
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

