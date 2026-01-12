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
    ll A, B, ca, cb, fa;
    cin >> A >> B >> ca >> cb >> fa;
    A += B / cb * ca;
    B %= cb;
    if(fa <= A) {
        cout << "0\n";
        return;
    }
    ll need = fa - A;
    ll cost1 = need + cb - B - 1;
    if(ca > cb) {
        cout << cost1 << "\n";
        return;
    }
    // cb > ca;
    ll a = ((need - 1) / ca + 1) * ca;
    ll b = a / ca * cb;
    /*
    a - ca + x == need - 1;
    */
    cout << max(cost1, b - B + need - 1 - a + ca) << "\n";
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

