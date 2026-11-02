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
    ll n, midones = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if(i > 0 && i < n - 1 && a[i] == 1) {
            midones++;
        }
    }
    if(n == 2 && a[0] == 1 && a[n - 1] == 1) {
        cout << "-1\n";
        return;
    }
    // debug(midones);
    if(midones == 0 || midones < n - 2) {
        cout << sum - 1 << "\n";
        return;
    }

    assert(midones == n - 2 && n > 2);
    if(a[0] > 1 || a[n - 1] > 1) {
        cout << sum - n + 1 << "\n";
        return;
    }

    cout << "-1\n";
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

