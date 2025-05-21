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
    vector<int> a(n);

    vector<bool> gt(n, false), lw(n, false);
    int gtsum = 0, lwsum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        lw[i] = a[i] <= a[(i + 1) % n];
        lwsum += lw[i];
        gt[i] = a[i] >= a[(i + 1) % n];
        gtsum += gt[i];
    }

    if(lwsum <= n - 2 && gtsum <= n - 2) {
        cout << "-1\n";
        return;
    }

    if(lwsum == n || gtsum == n) {
        cout << "0\n";
        return;
    }

    // for(bool x : gt) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // for(bool x : lw) {
    //     cout << x << " ";
    // }
    // cout << "\n";

    int mxgt = 0, mxlw = 0;
    for(int i = 0; i < n; i++) {
        // if(!gt[i] || !lw[i]) mx = i;
        if(!gt[i] && gtsum == n - 1) mxgt = i;
        if(!lw[i] && lwsum == n - 1) mxlw = i;
    }

    cout << min(min(n - mxgt, 1 + mxgt + 1) + (gtsum != n - 1) * 1e9, min(n - mxlw - 1, mxlw + 3) + (lwsum != n - 1) * 1e9) << "\n";


    /*
        1. shift
        2. reverse

        find min operation.
    */


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

