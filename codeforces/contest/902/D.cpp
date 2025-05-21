#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<ll, ll>
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

const ll MOD = 998244353;

vector<vector<int> > factors(1e5 + 1);

void sieve() {
    for(int i = 1; i <= 1e5; i++) {
        for(int j = i; j <= 1e5; j += i) {
            factors[j].pb(i);
        }
    }
}

ll pw(ll a, ll b) {
    if(b == 0) return 1;

    ll m = pw(a, b / 2);
    (m *= m) %= MOD;
    if(b & 1) {
        (m *= a) %= MOD;
    }
    return m;
}

void solve() {
    sieve();
    int n;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].ff;
        a[i].ss = i + 1;
    }

    sort(a.begin(), a.end(), [](pii i, pii j) -> bool {
        if(i.ff < j.ff) {
            return 0;
        }
        if(i.ff > j.ff) {
            return 1;
        }
        return i.ss < j.ss;
    });

    ll sum = 0, cur = n;
    vector<bool> down(n + 1, 1);
    for(int i = 0; i < n; i++) {
        if(!down[a[i].ss]) 
            continue;

        long long cnt = 0;
        for(int x : factors[a[i].ss]) {
            cnt += down[x];
            cur -= down[x];
            down[x] = 0;
        }

        (sum += (ll)a[i].ff * pw(2, cur) % MOD * (pw(2, cnt) - 1 + MOD) % MOD) %= MOD;
        // debug(a[i].ss, cur, sum);
        // for(bool x : down) {
        //     cout << x << " ";
        // }
        // cout << '\n';
    }
    // debug(cur, sum);
    cout << sum << "\n";

}

int main() {
    int t = 1;
    // cin >> t;
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
