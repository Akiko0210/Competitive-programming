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

vector<int> digs(int x) {
    vector<int> ans;
    while(x) {
        ans.pb(x % 10);
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int n, total_digits = 0, range = 1, range_nums = 1;
    cin >> n;

    while(n > total_digits) {
        total_digits += range * range_nums * 9;
        range++;
        range_nums *= 10;
    }
    range--;
    range_nums /= 10;
    total_digits -= range * range_nums * 9;
    n -= total_digits;
    int x = (n - 1) / range + range_nums;
    n = (n - 1) % range + 1;
    vector<int> d = digs(x);
    cout << d[n - 1] << "\n";
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

