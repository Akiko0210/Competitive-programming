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
    string s, t;
    cin >> s >> t;
    int cnt1 = 0, cnt2 = 0;
    for(char c : s) {
        if(c == '+') cnt1++;
    }

    for(char c : t) {
        if(c == '+') cnt1--;
        if(c == '?') cnt2++;
    }

    if(cnt1 < 0 || cnt1 > cnt2) {
        cout << fixed << setprecision(9) << 0.0 << "\n";
        return;
    }
    double ans = 1;
    for(int i = 0; i < cnt2; i++) {
        ans /= 2;
    }

    for(int i = 1; i <= cnt1; i++, cnt2--) {
        ans = ans * cnt2 / i;
    }
    cout << fixed << setprecision(9) << ans << "\n";
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

