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

int stree[1000000];

int F(int i, int L, int R, int l) {
    if(L > l) {
        return stree[i];
    }

    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    if(M > l) {
        return F(x, L, M, l) + F(y, M + 1, R, l);
    }
    return F(y, M + 1, R, l);
}

void update(int i, int L, int R, int l) {
    if(L == R) {
        stree[i] = 1;
        return;
    }
    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    if(M >= l) {
        update(x, L, M, l);
    } else {
        update(y, M + 1, R, l);
    }
    stree[i] = stree[x] + stree[y];
}

void solve() {
    // start before me and end after me gonna greet with me.
    int n;
    cin >> n;
    vector<pii> a(n);
    map<int, int> m;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
        m[a[i].ff] = 1;
    }

    int preind = 0;
    for(auto &[k, v] : m) {
        v += preind;
        preind = v;
    }

    for(int i = 0; i < (n + 1) * 4; i++) {
        stree[i] = 0;
    }

    sort(a.begin(), a.end(), [&](pii a, pii b) {
        return a.second < b.second;
    });


    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += F(0, 0, n, m[a[i].ff] - 1);
        update(0, 0, n, m[a[i].ff] - 1);
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

