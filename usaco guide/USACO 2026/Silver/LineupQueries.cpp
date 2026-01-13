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

ll one(ll c, ll t) {
    if(c * 2 > t) return c;

    ll time = c * 2, pos = c - 1;
    while(time + pos + 1 <= t) {
        time += pos + 1;
        pos = time / 2;
    }
    return pos - t + time;
}

ll two(ll x, ll t) {
    if(x > t / 2) return x;
    if(x == t / 2) return two(0, t - 1);

    if(t % 2 == 0) return two(x + 1, t - 1);

    ll d = t / 2 - x, time = d / 3 * 2 + d % 3;
    return two(x + time, t - time);
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        ll t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            cout << one(a, b) << "\n";
        } else {
            cout << two(a, b) << "\n";
        }
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

