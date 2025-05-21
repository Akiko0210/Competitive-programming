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
    int n;
    cin >> n;
    vector<int> a(n);

    vector<ll> cnt(1e5 + 1, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 1; j * j <= a[i]; j++) {
            if(a[i] % j == 0) {
                cnt[j]++;
                if(a[i] / j != j) {
                    cnt[a[i] / j]++;
                }
            }
        }
    }

    ll ans = 0;

    for(int i = 1e5; i > 0; i--) {
        if(cnt[i] < 2) continue;
        debug(i, cnt[i] * (cnt[i] - 1) / 2);
        ans += cnt[i] * (cnt[i] - 1) / 2 * i;
        for(int j = 1; j * j <= i; j++) {
            if(i % j == 0) {
                cnt[j] -= cnt[i];
                ans += cnt[i] * cnt[j] * j;
                debug(j, cnt[i] * cnt[j]);
                if(i / j != j && j != 1) {
                    cnt[i / j] -= cnt[i];
                    ans += cnt[i] * cnt[i / j] * (i / j);
                    debug(i / j, cnt[i] * cnt[i / j]);
                }
            }
        }
    }
    cout << ans << "\n";

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

