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

ll pw (ll a, ll b) {
    if(b == 0) {
        return 1;
    }

    ll m = pw(a, b / 2);
    m = m * m % MOD;
    if(b & 1) m = m * a % MOD;

    return m;
}

int main() {
    int t = 1;
    cin >> t;
    vector<int> n(t), k(t);
    for(int &x : n) {
        cin >> x;
    }

    for(int &x : k) {
        cin >> x;
    }

    for(int i = 0; i < t; i++) {
        if(k[i] == 0 || k[i] == n[i]) {
            cout << "1\n";
            continue;
        }

        // debug()

        cout << pw(2, k[i]) << "\n";
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

