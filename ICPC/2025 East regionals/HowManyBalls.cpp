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
    /*
2rgq = (r+g)(r+g-1)p
2rgq = (r^2 + rg - r + rg + g^2 - g)p
0 = pr^2 - pr + (2prg - pg - 2rgq) + (pg^2)
0 = g^2(p)
    
    */
    ll p, q;
    cin >> p >> q;
    for(ll r = 1; r <= 1e6; r++) {
        ll a = p, b = 2 * r * p - p - 2 * r * q, c = p * r * r - p * r;
        ll D = b * b - 4 * a * c;
        if(D < 0) continue;
        ll d = sqrt(D);
        if(d * d != D) continue;

        ll g = -b + d;
        if(g % (2 * a) != 0) continue;
        g /= 2 * a;
        if(g >= r) {
            cout << r << ' ' << g << "\n";
            return 0;
        }
    }
    cout << "impossible\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

