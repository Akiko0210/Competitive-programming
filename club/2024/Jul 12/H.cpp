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

ll n, h;
vector<ll> a;

bool check(ll k) {
    ll total_damage = 0;
    for(int i = 0; i < n; i++) {
        ll poisenend = a[i] + k - 1;
        if(i < n - 1 && a[i + 1] <= poisenend) { 
            poisenend = a[i + 1] - 1; 
        }
        ll damage = poisenend - a[i] + 1;
        total_damage += damage;
    }
    return h <= total_damage;
}

void solve() {
    cin >> n >> h;
    a.resize(n);
    for(ll &x: a) {
        cin >> x;
    }

    ll l = 1, r = h;
    while(l < r) {
        ll m = (l + r) / 2;
        if(check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << l << "\n";
}

int main() {
    int t;
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

