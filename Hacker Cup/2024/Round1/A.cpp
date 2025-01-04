#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<ll, ll>
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

void printans(int t, double ans) {
    cout << "Case #" << t << ": " << fixed << setprecision(6) << ans << "\n";
}

double solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
    }
    ll top = a[0].ss, bot = a[0].ff, toppos = 0, botpos = 0;
    for(int i = 1; i < n; i++) {
        // top / toppos > a[i].ss / (i + 1)
        // bot / botpos < a[i].ff / (i + 1);
        if(top * (i + 1) > a[i].ss * (toppos + 1)) {
            top = a[i].ss;
            toppos = i;
        }
        if(bot * (i + 1) < a[i].ff * (botpos + 1)) {
            bot = a[i].ff;
            botpos = i;
        }

        if(top * (botpos + 1) < bot * (toppos + 1)) {
            return -1;
        }
    }

    return (double)(toppos + 1) / top;


}

int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        printans(i, solve());
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

