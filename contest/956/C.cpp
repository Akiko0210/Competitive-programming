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

ll tot = 0;
bool isans(vector<ll>& a, vector<ll>& b, vector<ll>& c, vector<int> order) {
    ll sum = 0, l = 0, r = 0, n = a.size();
    vector<pii> ans;
    while(r < n && sum < tot) {
        sum += a[r++];
    }
    // debug(l, r, sum, tot);
    if(sum < tot) return false;
    ans.pb({l, r - 1});

    sum = 0;
    l = r;
    while(r < n && sum < tot) {
        sum += b[r++];
    }
    if(sum < tot) return false;
    ans.pb({l, r - 1});

    sum = 0;
    l = r;
    while(r < n && sum < tot) {
        sum += c[r++];
    }
    if(sum < tot) return false;
    ans.pb({l, r - 1});

    for(int i = 0; i < 3; i++) {
        cout << ans[order[i]].ff + 1 << " " << ans[order[i]].ss + 1 << " ";
    }
    cout << "\n";
    return true;
}

void solve() {
    // cout << "\n\n\n\n";
    int n;
    cin >> n;
    tot = 0;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    tot = (tot + 2) / 3;

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    if(isans(a, b, c, {0, 1, 2}) || isans(a, c, b, {0, 2, 1}) || isans(b, a, c, {1, 0, 2}) || isans(b, c, a, {2, 0, 1}) || isans(c, a, b, {1, 2, 0}) || isans(c, b, a, {2, 1, 0})) {
        return;
    } 

    cout << "-1\n";
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
    * int overflow, aray bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

