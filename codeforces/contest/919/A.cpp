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
    int n, mx = 0, mn = 1e9;
    cin >> n;
    vector<int> ar;
    for(int i = 0; i < n; i++) {
        int a, x;
        cin >> a >> x;
        if(a == 1) {
            mx = max(mx, x);
        }
        if(a == 2) {
            mn = min(mn, x);
        }
        if(a == 3) {
            ar.push_back(x);
        }
    }
    sort(ar.begin(), ar.end());
    int ind = mn - mx + 1 - (upper_bound(ar.begin(), ar.end(), mn) - lower_bound(ar.begin(), ar.end(), mx));
    cout << max(ind, 0) << "\n";

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

