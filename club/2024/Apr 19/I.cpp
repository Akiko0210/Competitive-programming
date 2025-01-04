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

vector<pii> res;
vector<int> a(18);

void rec(int l, int r) {
    if(l > r) {
        return;
    }
    rec(l, r - 1);
    if(a[r] != r - l) {
        res.pb({l, r});
        // a[r] = r - l;
        for(int i = l; i <= r; i++) {
            a[i] = r - l;
        }
    }
    rec(l, r - 1);
}

void solve() {
    /*
    for each segment l, r we can make all of them (r - l + 1)
    */
    /*
    
    
    */
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, bestMask;
    for(int mask = 0; mask < (1 << n); mask++) {
        int l = (mask & 1 ? 0 : -1), sum = (mask & 1 ? 1 : a[0]);
        for(int i = 1; i < n; i++) {
            if(mask & (1 << i)) {
                if(l == -1) {
                    l = i;
                }
                sum += (i - l) * 2 + 1;
            } else {
                sum += a[i];
                l = -1;
            }
        }
        if(ans < sum) {
            bestMask = mask;
            ans = sum;
        }
    }
    vector<pii> ranges;
    int l = (bestMask & 1 ? 0 : -1);
    for(int i = 1; i < n; i++) {
        if(bestMask & (1 << i)) {
            if(l == -1) {
                l = i;
            }
        } else {
            if(l != -1) {
                ranges.pb({l, i - 1});
                l = -1;
            }
        }
    }
    if(l != -1) {
        ranges.pb({l, n - 1});
    }

    for(pii range : ranges) {
        rec(range.ff, range.ss);
        res.pb(range);
    }
    cout << ans << " " << res.size() << "\n";
    for(pii op : res) {
        cout << op.ff + 1 << " " << op.ss + 1 << "\n";
    }

}

int main() {
    int t = 1;
    // cin >> t;
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

