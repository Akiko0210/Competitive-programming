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

int main() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].ss >> a[i].ff;
    }

    sort(a.begin(), a.end());
    int ans = 0, last = 0;
    for(int i = 0; i < n; i++) {
        ans += max(a[i].ss - last - 1, 0);
        last = max(last + 1, a[i].ss);
        // debug(ans, i, a[i].ff, a[i].ss);
    }

    cout << ans << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

