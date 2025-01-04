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

void solve() {
    ll n, m, mx_val = 0;
    cin >> n >> m;
    map<int, vector<int> > mex;
    vector<pii> ar;
    for(int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> a(l);
        for(int &x : a) cin >> x;

        sort(a.begin(), a.end());
        a.pb(1e9);

        int prev = -1, mx = -1, nxt = -1, maxmex = 0;
        for(int i = 0; i <= l; i++) {
            if(a[i] - prev > 1) {
                if(mx == -1) {
                    mx = prev + 1;
                    if(a[i] - mx > 1) {
                        nxt = mx + 1;
                        break;
                    }
                } else {
                    nxt = prev + 1;
                    break;
                }
            }
            prev = a[i];
        }
        mx_val = max((ll)mx, mx_val);
        mex[nxt].pb(mx);
    }

    map<int, int> val;
    set<int> keys;
    for(auto &[k, v] : mex) {
        val[k] = k;
        keys.insert(k);
    }

    while(!keys.empty()) {
        auto it = keys.end();
        it--;
        int cur = *it;
        keys.erase(it);
        for(int x : mex[cur]) {
            val[x] = max(val[x], val[cur]);
            keys.insert(x);
        }
    }

    // ll mx_val = 0;
    for(int i = mx_val; i >= 0; i--) {
        mx_val = max(mx_val, (ll)val[i]);
    }

    // debug(mx_val);
    ll ans;
    if(mx_val < m) {
        ans = mx_val * (mx_val + 1) + (m + mx_val + 1) * (m - mx_val) / 2;
    } else {
        ans = mx_val * (m + 1);
    }
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

