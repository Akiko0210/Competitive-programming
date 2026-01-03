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
    /*
    2 5 5
    0 0
    5 5
    ----
    3 3
    2 2
    */
    int n, x, y, ind0 = -1, ind1 = -1;
    string s;
    cin >> n >> x >> y >> s;
    int tx = x, ty = y;
    vector<int> p(n), a(n), b(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        if(s[i] == '0') {
            ind0 = i;
            a[i] = p[i] / 2 + 1;
            b[i] = p[i] - a[i];
        } else {
            ind1 = i;
            b[i] = p[i] / 2 + 1;
            a[i] = p[i] - b[i];
        }
        tx -= a[i];
        ty -= b[i];
        sum += p[i];
    }
    if(sum > x + y) {
        cout << "NO\n";
        return;
    }

    // adjust
    for(int i = 0; i < n && (tx != 0 || ty != 0); i++) {
        // debug(tx, ty);
        if(tx > 0 && ty > 0) {
            int sub = min(tx, ty);
            a[i] += sub;
            b[i] += sub;
            tx -= sub;
            ty -= sub;
        }
        if(tx < 0 && ty > 0) {
            // a is overused.
            // b is underused.
            if(s[i] == '1') {
                int sub = min(min(-tx, a[i]), ty);
                a[i] -= sub;
                tx += sub;
                b[i] += sub;
                ty -= sub;
            }
        }

        if(tx > 0 && ty < 0) {
            // b is overused.
            // a is underused.
            if(s[i] == '0') {
                int sub = min(min(-ty, b[i]), tx);
                b[i] -= sub;
                ty += sub;
                a[i] += sub;
                tx -= sub;
            }
        }

        if(tx == 0 && ty > 0) {
            if(s[i] == '1') {
                b[i] += ty;
                ty = 0;
            } else {
                int sub = min(a[i] - b[i] - 1, ty);
                b[i] += sub;
                ty -= sub;
            }
        }

        if(ty == 0 && tx > 0) {
            if(s[i] == '0') {
                a[i] += tx;
                tx = 0;
            } else {
                int sub = min(b[i] - a[i] - 1, tx);
                a[i] += sub;
                tx -= sub;
            }
        }
    }
    // for(int x : a) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // for(int x : b) {
    //     cout << x << " ";
    // }
    // cout << "\n";

    if(tx == 0 && ty == 0)
        cout << "YES\n";
    else cout << "NO\n";
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

