#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF INT64_MAX
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
    int q;
    cin >> q;
    ll mn = 0, mx = INF;
    ll a, b, n;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            cin >> a >> b >> n;
            ll x = a * n - b * (n - 1), y = (n > 1 ? (x - (a - b) + 1) : 1);
            if(x < mn || y > mx) {
                cout << "0 ";
            } else {
                mn = max(mn, y);
                mx = min(mx, x);
                cout << "1 ";
            }
        } else {
            cin >> a >> b;
            ll dif = a - b, xleft = max(mn - a, 0LL), yleft = max(mx - a, 0LL);
            ll x = 1 + ((xleft % dif == 0) ? (xleft / dif) : (xleft / dif + 1));
            ll y = 1 + ((yleft % dif == 0) ? (yleft / dif) : (yleft / dif + 1));

            if(x != y) {
                cout << "-1 ";
            } else {
                cout << x << " ";
            }
        }
    }
    cout << "\n";
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
