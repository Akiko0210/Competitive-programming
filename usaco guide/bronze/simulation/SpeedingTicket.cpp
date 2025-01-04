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
}

int main() {
    ifstream in ("speeding.in");
    ofstream out("speeding.out");
    int n, m;
    in >> n >> m;
    vector<pii> a(n), b(m);
    for(int i = 0; i < n; i++) {
        in >> a[i].ff >> a[i].ss;
    }
    for(int i = 0; i < m; i++) {
        in >> b[i].ff >> b[i].ss;
    }

    int ans = max(0, b[0].ss - a[0].ss), asum = a[0].ff, bsum = b[0].ff, l = 0, r = 0;

    for(int i = 1; i < n + m; i++) {
        if(bsum - b[r].ff != asum && asum - a[l].ff != bsum) {
            ans = max(ans, b[r].ss - a[l].ss);
        }
        if(asum < bsum) {
            asum += a[++l].ff;
        } else {
            bsum += b[++r].ff;
        }

    }

    out << ans << "\n";



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

