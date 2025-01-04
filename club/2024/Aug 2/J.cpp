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
    int cntpos = 0, cntneg = 0, unknown = 0;
    string s1, s2;
    cin >> s1 >> s2;

    for(char c : s1) {
        cntpos += c == '+';
        cntneg += c == '-';
    }

    for(char c : s2) {
        cntpos -= c == '+';
        cntneg -= c == '-';
        unknown += c == '?';
    }

    if(cntpos < 0 || cntneg < 0) {
        cout << fixed << setprecision(9) << 0.0 << "\n";
        return;
    }

    int x = 1;
    for(int i = 1; i <= min(cntpos, cntneg); i++) {
        x *= (unknown + 1 - i);
        x /= i;
    }

    double ans = x;
    while(unknown--) {
        ans /= 2;
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

