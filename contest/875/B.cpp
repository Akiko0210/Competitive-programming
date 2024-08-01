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
    int n, ans = 1;
    cin >> n;
    vector<int> a(n), b(n), ca(2 * n + 1, 0), cb(2 * n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ca[a[0]] = 1;
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1]) {
            cnt ++;
        } else {
            cnt = 1;
        }
        ca[a[i]] = max(ca[a[i]], cnt);
    }
    ca[a[n - 1]] = max(ca[a[n - 1]], cnt);

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cb[b[0]] = 1;
    cnt = 1;

    for(int i = 1; i < n; i++) {
        if(b[i] == b[i - 1]) {
            cnt ++;
        } else {
            cnt = 1;
        }
        cb[b[i]] = max(cb[b[i]], cnt);
    }
    cb[b[n - 1]] = max(cb[b[n - 1]], cnt);

    for(int i = 0; i <= 2 * n; i++) {
        ans = max(ans, ca[i] + cb[i]);
    }
    cout << ans << "\n";

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
