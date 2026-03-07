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

const ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, base = 123491919;

ll pw(ll a, ll b, ll MOD) {
    if(b == 0) return 1;

    ll h = pw(a, b / 2, MOD);
    h = h * h % MOD;
    if(b & 1) {
        h = h * a % MOD;
    }

    return h;
}

int main() {
    FAST
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // hash a difference

    ll ahash1 = 0, ahash2 = 0;
    ll bhash1 = 0, bhash2 = 0;
    vector<ll> p1(n, 1), p2(n, 1);
    for(int i = 1; i < n; i++) {
        p1[i] = p1[i - 1] * base % MOD1;
        p2[i] = p2[i - 1] * base % MOD2;
        ahash1 = (ahash1 + p1[i - 1] * (a[i] - a[i - 1]) % MOD1) % MOD1;
        ahash2 = (ahash2 + p2[i - 1] * (a[i] - a[i - 1]) % MOD2) % MOD2;
     
        bhash1 = (bhash1 + p1[i - 1] * (b[i] - b[i - 1]) % MOD1) % MOD1;
        bhash2 = (bhash2 + p2[i - 1] * (b[i] - b[i - 1]) % MOD2) % MOD2;
    }

    ll ibase1 = pw(base, MOD1 - 2, MOD1), ibase2 = pw(base, MOD2 - 2, MOD2);
    for(int i = 0; i < n; i++) {
        // debug(ahash, bhash);
        // sending i to the end.
        if(bhash1 == ahash1 && bhash2 == ahash2) {
            cout << "possible\n";
            return 0;
        }
        bhash1 = (bhash1 - (b[(i + 1) % n] - b[i] + 360000) % 360000 + MOD1) % MOD1 * ibase1 % MOD1;
        bhash2 = (bhash2 - (b[(i + 1) % n] - b[i] + 360000) % 360000 + MOD2) % MOD2 * ibase2 % MOD2;
        // debug(bhash);
        (bhash1 += p1[n - 2] * ((b[i] - b[(i - 1 + n) % n] + 360000) % 360000) % MOD1) %= MOD1;
        (bhash2 += p2[n - 2] * ((b[i] - b[(i - 1 + n) % n] + 360000) % 360000) % MOD2) %= MOD2;
        // debug(bhash);
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

