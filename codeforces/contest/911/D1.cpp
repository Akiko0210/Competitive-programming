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

vector<vector<int>> divs(1e5 + 1);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    vector<int> cnt(1e5 + 1, 0);
    vector<int> m(1e5 + 1, 0);
    for(int i = 0; i < n; i++) {
        ll t = n - 1 - i;
        for(int j = divs[a[i]].size() - 1; j >= 0; j--) {
            int x = divs[a[i]][j];
            ans += t * (cnt[x] - m[x]) * x;

            for(int y : divs[x]) {
                m[y] += cnt[x] - m[x];
            }
            cnt[x]++;
        }

        for(int x : divs[a[i]]) {
            m[x] = 0;
        }
    }
    cout << ans << "\n";

}

int main() {
    FAST
    for(int i = 1; i <= 1e5; i++) {
        for(int j = i; j <= 1e5; j += i) {
            divs[j].pb(i);
        }
    }
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

