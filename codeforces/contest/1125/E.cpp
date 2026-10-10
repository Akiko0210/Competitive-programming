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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    auto check = [&](int i, int j) {
        return a[i] == b[j] ? 2 : 1;
    };  

    int sum1 = check(n - 1, n - 1), sum2 = 0, mn = check(n - 1, n - 1);
    vector<int> pre(n);
    for(int i = 0; i < n; i++) {
        sum2 += check(i, i);
        if(i > 0) {
            int d1 = check(i, i - 1);
            int d2 = check(i - 1, i);
            sum2 += d1;
        }
        pre[i] = sum2;
    }
    int ans = pre[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        int d1 = check(i, i + 1);
        int d2 = check(i + 1, i);
        sum1 += d1 + d2;
        ans = max(ans, pre[i] + sum1 - check(i, i));
    }

    cout << ans << "\n";
}

int main() {
    FAST
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

