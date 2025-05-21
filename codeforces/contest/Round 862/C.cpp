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
        double a, b, c, temp, x1, x0, mx, mn;
        cin >> a >> b >> c;
        temp = sqrt(c / a);
        if(c < 0) {
            cout << "NO\n";
            return;
        }
        mx = 2 * a * temp + b;
        mn = -2 * a * temp + b;
        ll upper = mx;
        if(upper < mx) {
            upper++;
        }
        int mx_ind = lower_bound(line.begin(), line.end(), upper) - line.begin();
        mx_ind--;
        upper = mn;

        int mn_ind = upper_bound(line.begin(), line.end(), upper) - line.begin();
        // debug(mx_ind, mn_ind);
        if(mn_ind <= mx_ind) {
            cout << "YES\n" << line[mn_ind] << "\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    FAST
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
