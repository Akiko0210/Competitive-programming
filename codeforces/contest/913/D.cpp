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
    vector<pii> seg(n);
    for(int i = 0; i < n; i++) {
        cin >> seg[i].ff >> seg[i].ss;
    }

    auto merge = [&] (pii cur, int i) -> pii {
        int l = cur.ff;
        int r = cur.ss;
        if(l > seg[i].ss || r < seg[i].ff) {
            return {-1, -1};
        }
        return {max(l, seg[i].ff), min(r, seg[i].ss)};
    };

    int l = 0, r = 1e9;
    while(l < r) {
        int m = (l + r) / 2;
        pii cur = {0, m};
        bool can = true;
        for(int i = 0; i < n; i++) {
            cur = merge(cur, i);
            if(cur.ff == -1) {
                can = false;
                break;
            }
            cur.ff -= m;
            cur.ss += m;
        }
        
        if(!can) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l << "\n";
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

