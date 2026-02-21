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

int main() {
    ll base = 10000;
    double _;
    cin >> _;
    ll X = round(_ * base);
    if(X == base * 10) {
        cout << "No solution\n";
        return 0;
    }
    vector<ll> ans;
    for(ll t = 0; t < 8; t++) {
        ll p = pow(10, t);
        ll num = (X * p - 10000);
        ll denom = (100000 - X);
        for(ll a = 1; a <= 9; a++) {
            ll b = num * a;
            // debug(b, denom);
            if(b % denom > 0) continue;

            b /= denom;
            // debug(b);
            if(b >= p) {
                continue;
            }
            ll num1 = a * p + b;
            ans.pb(num1);
        }
    }

    if(ans.empty()) {
        cout << "No solution\n";
        return 0;
    }

    for(int x : ans) {
        cout << x << "\n";
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

