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

int main() {
    ifstream cin("cbarn.in");
    ofstream cout("cbarn.out");

    int n;
    cin >> n;
    vector<int> a(n + 1), asum(n + 1, 0), sum(n + 1, 0);
    for(int i = n; i > 0; i--) 
        cin >> a[i];
    
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        asum[i] = asum[i - 1] + sum[i - 1] + a[i];
    }

    int ans = INF;
    for(int i = 1; i <= n; i++) {
        int cur = asum[i - 1] + asum[n] - asum[i] - sum[i] * (n - i) + (sum[n] - sum[i]) * (i - 1);
        // 0 + 88 - 4 - 4 * 4 + (25 - 4) * (0) = 68
        // debug(i, cur);
        ans = min(ans, cur);
    }
    cout << ans << "\n";



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

