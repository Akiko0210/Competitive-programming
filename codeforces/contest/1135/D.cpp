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
    if(b == 0) return 1;

    ll h = pw(a, b / 2);
    h = h * h % MOD;
    if(b & 1) {
        h = h * a % MOD;
    }

    return h;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), reva;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    reva = a;
    reverse(reva.begin(), reva.end());

    ll diff = 0;
    unordered_map<ll, vector<int> > pos;
    for(int i = 0; i < n; i++) {
        diff += a[i] - reva[i];
        pos[diff].pb(i);
    }

    auto equal_cnt = [&](int l, int r, int dif) {
        if(r < l || pos[dif].empty()) return 0;

        int cnt = lower_bound(pos[dif].begin(), pos[dif].end(), r) - 
            lower_bound(pos[dif].begin(), pos[dif].end(), l);
        return cnt;
    };

    int total = equal_cnt(0, n - 1, 0);

    vector<ll> fac(n + 1, 1);
    for(int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * (i) % MOD;
    }

    auto choose = [&](int a, int b) {
        if(b > a) return 0LL;
        // a choose b
        return fac[a] * pw(fac[b], MOD - 2) % MOD * pw(fac[a - b], MOD - 2) % MOD;
    };
    /*
    2 1
    1 2 3 2 1
    1 3 3 2 1
    1 2 3 3 1

    
    */
    while(q--) {
        int l, val;
        cin >> l >> val;
        l--;
        int r = n - 1 - l;
        val = -val;
        if(l > r) {
            val = -val;
            swap(l, r);
        }
        int sub = equal_cnt(l, r, 0);
        int add = equal_cnt(l, r, val);
        // debug(l, r, sub, add);
        int qtotal = total - sub + add;
        // qtotal choose m
        // debug(qtotal);
        cout << choose(qtotal, m - 1) << "\n";
    }

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

