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
        (i, j) -> (x, y)
        (1, 1) -> (2, 2)
        (2, 1) -> (1, 2)
        
        
        (1, 1) -> (2, 1) -> change r1, r2, change c1, c1
        (1, 2) -> (2, 2) -> change r1, r2, change c2, c2
        (2, 1) -> (1, 2) -> change r1, r2, change c1, c2
        (2, 2) -> (1, 1) -> change r1, r2, change c1, c2
    */

    int n, m;
    cin >> n >> m;
    vector<pii> posa(n * m + 1), posb(n * m + 1);
    vector<int> rchange(n, -1), cchange(m, -1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            posa[x] = {i, j};
        }
    }

    bool isans = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            posb[x] = {i, j};
            if(rchange[i] == -1) {
                rchange[i] = posa[x].first;
            } else if(rchange[i] != posa[x].first) {
                isans = false;
            }
            if(cchange[j] == -1) {
                cchange[j] = posa[x].second;
            } else if(cchange[j] != posa[x].second) {
                isans = false;
            }
        }
    }

    if(!isans) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";

    // for(int i = 1; i <= n * m; i++) {
    //     int ra = posa[i].first, ca = posa[i].second, rb = posb[i].first, cb = posb[i].second;
    //     debug(rchange[ra], rchange[rb], ra, rb);
    //     debug(cchange[ca], cchange[cb], ca, cb);
    //     if(ra != rchange[rb] || rb != rchange[ra]) {
    //         cout << "No\n";
    //         return;
    //     }

    //     if(ca != cchange[cb] || cb != cchange[ca]) {
    //         cout << "No\n";
    //         return;
    //     }
    // }
    // cout << "Yes\n";





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

