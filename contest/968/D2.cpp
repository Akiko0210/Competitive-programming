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
    ll n, m;
    cin >> n >> m;
    map<int, vector<int> > edges;
    map<int, int> cnt;
    map<int, int> destination;
    set<int> nodes;

    for(int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> a(l);
        for(int &x : a) cin >> x;

        a.pb(1e9);
        sort(a.begin(), a.end());
        int prev = -1, mx = -1, nxtmx = -1;
        for(int j = 0; j < l + 1; j++) {
            if(a[j] - prev > 1) {
                if(mx == -1) {
                    mx = prev + 1;
                    prev = mx;
                    j--;
                    continue;
                }
                if(nxtmx == -1) {
                    nxtmx = prev + 1;
                    break;
                }
            }
            prev = a[j];
        }
        edges[nxtmx].pb(mx);
        nodes.insert(mx);
        debug(mx, nxtmx);
        destination[mx] = max(destination[mx], nxtmx);
        cnt[mx]++;
    }

    int max_forked = 0;
    while(!nodes.empty()) {
        auto it = nodes.end();
        it--;
        int cur = *it;
        nodes.erase(it);
        
        max_forked = max(max_forked, cur);
        if(cnt[cur] > 1) {
            max_forked = max(max_forked, destination[cur]);
        }
        debug(cur, destination[cur]);

        for(int x : edges[cur]) {
            destination[x] = max(destination[x], destination[cur]);
        }
    }

    ll ans = m * (m + 1) / 2, count = min((ll)max_forked, m) + 1;
    ans += count * max_forked - count * (count - 1) / 2;
    debug(max_forked);
    for(auto &[k, v] : destination) {
        int prev_val = max(max_forked, k);
        if(k <= m && v > prev_val) { // imidiate reach.
            debug(k, v);
            ans += v - prev_val;
        }
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

