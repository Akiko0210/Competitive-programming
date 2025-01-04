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
    vector<int> a(n), pr(n), nx(n), order(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pr[i] = i - 1;
        nx[i] = i + 1;
    }

    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] > a[j];
    });
    for(int i : order) {
        int mx = -1;
        if(pr[i] != -1) mx = max(mx, a[pr[i]]);
        if(nx[i] != n) mx = max(mx, a[nx[i]]);

        if(a[i] > mx + 1 || (a[i] == 0 && mx == 0)) {
            cout << "NO\n";
            return;
        }

        if(pr[i] != -1) 
            nx[pr[i]] = nx[i];

        if(nx[i] != n) 
            pr[nx[i]] = pr[i];
    }
    cout << "YES\n";
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

