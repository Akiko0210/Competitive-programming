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

ll checka(vector<ll> ar, vector<ll> br, int k, int n) {
    if(br.size() > 0) {
        sort(br.begin(), br.end());
        br[br.size() - 1] += k;
        while(!br.empty()) {
            ar.pb(br.back());
            br.pop_back();
        }
    }

    sort(ar.begin(), ar.end());
    return ar.back() + ar[n / 2 - 1];

}

ll checkb(vector<ll> ar, vector<ll> br, ll k, int n) {
    sort(ar.begin(), ar.end());
    sort(br.begin(), br.end());
    ll mx = max((ar.empty() ? 0 : ar.back()), br.empty() ? 0 : br.back());

    ll l = 0, r = mx;
    while(l < r) {
        // debug(l, r);
        ll m = (l + r + 1) / 2, sum = 0, pivot = n / 2;
        ll cnt = lower_bound(ar.begin(), ar.end(), m) - ar.begin();
        if(cnt >= pivot) {
            r = m - 1; 
            continue;
        }

        for(int i = pivot - cnt - 1; i < br.size(); i++) {
            sum += max(m - br[i], 0LL);
        }
        // debug(sum);

        if(sum <= k) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    // debug(mx, l);
    return mx + l;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> ar, br;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(!b[i]) {
            ar.pb(a[i]);
        } else {
            br.pb(a[i]);
        }
    }
    ll ans = checka(ar, br, k, n);
    // debug(k);
    cout << max(ans, checkb(ar, br, k, n)) << "\n";
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

