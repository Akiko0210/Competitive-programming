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

const ll MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), ind(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    int x = 0;
    ll ans = 0, sum = 0;
    vector<bool> mark(n, false);
    for(int i = k; i < n; i++) {
        mark[ind[i]] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(!mark[i]) {
            sum += a[i];
        }
    }
    ans = sum;
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        if(!mark[i]) {
            cur += a[i];
            ans = min(ans, max(cur, sum - cur));
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
