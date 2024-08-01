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
    int n, m;
    cin >> n >> m;
    vector<ll> line(n);
    for(int i = 0; i < n; i++) {
        cin >> line[i];
    }

    sort(line.begin(), line.end());
    while(m--) {
        double a, b, c, x0, m;
        cin >> a >> b >> c;
        x0 = sqrt(c / a);
        m = 2 * a * x0 + b;
        ll upper = m;
        if(upper < m) {
            upper++;
        }
        int ind = lower_bound(line.begin(), line.end(), upper) - line.begin();
        ind--;
        if(ind >= 0) {
            cout << "YES\n" << line[0] << "\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    int t;
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
