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
    int n;
    cin >> n;
    vector<pii> a(n);
    vector<int> cnt(2 * n + 1, 0), sum(2 * n + 1, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
        if(a[i].ff == a[i].ss) {
            cnt[a[i].ff]++;
            sum[a[i].ff] = 1;
        }
    }

    for(int i = 1; i <= 2 * n; i++) {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }

    for(int i = 0; i < n; i++) {
        int total = cnt[a[i].ss] - cnt[a[i].ff - 1];
        int t = sum[a[i].ss] - sum[a[i].ff - 1];
        if(a[i].ff == a[i].ss) {
            if(total == 1) cout << 1;
            else cout << 0;
        } else {
            if(t < a[i].ss - a[i].ff + 1) cout << 1;
            else cout << 0;
        }
    }


    cout << "\n";
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

