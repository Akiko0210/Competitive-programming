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

ll pw(ll a, ll b) {
    if(b == 0) return 1;

    ll h = pw(a, b / 2);
    h = h * h % MOD;
    if(b & 1) {
        h = h * a % MOD;
    }

    return h;
}

ll inv(ll a) {
    return pw(a, MOD - 2);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    /*
        rearrange b.
        sorted matching...
    
    */

    vector<int> aind(n), bind(n);
    iota(aind.begin(), aind.end(), 0);
    sort(aind.begin(), aind.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    iota(bind.begin(), bind.end(), 0);
    sort(bind.begin(), bind.end(), [&](int x, int y) {
        return b[x] < b[y];
    });

    unordered_map<int, multiset<int> > am, bm;
    ll ans = 1;
    for(int i = 0; i < n; i++) {
        am[a[aind[i]]].insert(b[bind[i]]);
        bm[b[bind[i]]].insert(a[aind[i]]);
        ans = ans * min(a[aind[i]], b[bind[i]]) % MOD;
    }

    cout << ans << " ";
    while(q--) {
        int o, x;
        cin >> o >> x;
        x--;

        if(o == 1) {
            // delete max value from am.
            auto ita = am[a[x]].end();
            ita--;
            int val = *ita;
            am[a[x]].erase(ita);
            // delete a[x] from bm.
            auto itb = bm[val].find(a[x]);
            bm[val].erase(itb);

            ans = ans * inv(min(a[x], val)) % MOD;

            a[x]++;
            am[a[x]].insert(val);
            bm[val].insert(a[x]);

            ans = ans * min(a[x], val) % MOD;
        } else {
            // delete max value from bm.
            auto itb = bm[b[x]].end();
            itb--;
            int val = *itb;
            bm[b[x]].erase(itb);
            // delete b[x] from am.
            auto ita = am[val].find(b[x]);
            am[val].erase(ita);

            ans = ans * inv(min(b[x], val)) % MOD;

            b[x]++;
            bm[b[x]].insert(val);
            am[val].insert(b[x]);
            ans = ans * min(b[x], val) % MOD;
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    FAST
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

